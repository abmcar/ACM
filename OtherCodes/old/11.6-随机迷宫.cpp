#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

const int Maxn = 1e2 + 10;

// 迷宫
int maze[Maxn][Maxn];
// 坐标移动
int Move[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
// 是否压入过栈
bool vis[Maxn][Maxn];
// 是否走过
bool vised[Maxn][Maxn];
// 迷宫大小
int n, m;
// 起点和终点
int strX, strY, endX, endY;


// 坐标结构体
struct Pos
{
    int x, y;
};


// 打印当前迷宫状态,message为提示信息
void printBoard(string message)
{
    system("cls");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 2)
            {
                cout << "X";
                continue;
            }
            if (maze[i][j] == 1)
                cout << "*";
            if (vised[i][j])
            {
                cout << "#";
                continue;
            }
            if (maze[i][j] == 0)
                cout << "O";
        }
        cout << endl;
    }
    cout << message << endl;
    sleep(1);
}

// 初始化为默认迷宫
void defaultBoard()
{
    n = 8;
    m = 10;
    strX = strY = 1;
    endX = 6;
    endY = 8;
    // 迷宫赋值
    for (int i = 0; i <= n - 1; i++)
        maze[i][0] = maze[i][m - 1] = 1;
    for (int i = 0; i <= m - 1; i++)
        maze[0][i] = maze[n - 1][i] = 1;
    maze[1][3] = 1;
    maze[1][4] = 1;
    maze[1][6] = 1;
    maze[1][8] = 1;
    maze[2][1] = 1;
    maze[2][4] = 1;
    maze[2][5] = 1;
    maze[3][7] = 1;
    maze[3][8] = 1;
    maze[4][1] = 1;
    maze[4][2] = 1;
    maze[4][4] = 1;
    maze[4][5] = 1;
    maze[5][6] = 1;
    maze[5][8] = 1;
    maze[6][1] = 1;
    maze[6][3] = 1;
}


// 生成随机迷宫
void genBoard()
{
    srand(time(0));
    n = 8;
    m = 10;
    strX = strY = 1;
    endX = 6;
    endY = 8;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            maze[i][j] = (rand() % 4 == 0) ? 1 : 0;
    maze[strX][strY] = maze[endX][endY] = 0;
}

// 找路
void find()
{
    // 初始化
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vis[i][j] = false;
    stack<Pos> Spos;
    // 压入起点
    Spos.push({strX,strY});
    maze[strX][strY] = 2;
    vis[strX][strY] = true;
    while (!Spos.empty())
    {
        int nowX = Spos.top().x;
        int nowY = Spos.top().y;
        // Spos.pop();
        maze[nowX][nowY] = 2;
        // 判断是否访问到终点
        if (nowX == endX && nowY == endY)
        {
            printBoard("寻路完毕");
            system("pause");
            return;
        }
        printBoard("");
        // 向4个方向移动
        for (int i = 0; i < 4; i++)
        {
            int nx = nowX + Move[0][i];
            int ny = nowY + Move[1][i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (vis[nx][ny])
                continue;
            if (maze[nx][ny] != 0)
                continue;
            Spos.push({nx,ny});
            vis[nx][ny] = true;
        }
        // 判断是否无路可走
        if (Spos.top().x == nowX && Spos.top().y == nowY)
        {
            maze[nowX][nowY] = 0;
            Spos.pop();
            vised[nowX][nowY] = 1;
            printBoard("");
        }
    }
    cout << "无法找到道路前往终点(" << endX << "," << endY << ")" << endl;
    system("pause");
}

void welcome()
{
    system("cls");
    cout << "输入 1 初始化迷宫为默认迷宫" << endl;
    cout << "输入 2 初始化迷宫为随机迷宫" << endl;
    cout << "输入 3 开始寻路" << endl;
    cout << "输入 -1 结束程序" << endl;
}

int main()
{
    int opt;
    welcome();
    // 输入操作种类
    while (cin >> opt)
    {
        if (opt == -1)
            break;
        if (opt == 1)
        {
            defaultBoard();
            printBoard("初始化默认迷宫完成");
            system("pause");
        }
        if (opt == 2)
        {
            genBoard();
            printBoard("初始化随机迷宫完成");
            system("pause");
        }
        if (opt == 3)
        {
            cout << "开始寻路" << endl;
            sleep(1);
            find();
        }
        welcome();
    }
    return 0;
}