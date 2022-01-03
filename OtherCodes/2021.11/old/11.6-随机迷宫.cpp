#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

const int Maxn = 1e2 + 10;

// �Թ�
int maze[Maxn][Maxn];
// �����ƶ�
int Move[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
// �Ƿ�ѹ���ջ
bool vis[Maxn][Maxn];
// �Ƿ��߹�
bool vised[Maxn][Maxn];
// �Թ���С
int n, m;
// �����յ�
int strX, strY, endX, endY;


// ����ṹ��
struct Pos
{
    int x, y;
};


// ��ӡ��ǰ�Թ�״̬,messageΪ��ʾ��Ϣ
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

// ��ʼ��ΪĬ���Թ�
void defaultBoard()
{
    n = 8;
    m = 10;
    strX = strY = 1;
    endX = 6;
    endY = 8;
    // �Թ���ֵ
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


// ��������Թ�
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

// ��·
void find()
{
    // ��ʼ��
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vis[i][j] = false;
    stack<Pos> Spos;
    // ѹ�����
    Spos.push({strX,strY});
    maze[strX][strY] = 2;
    vis[strX][strY] = true;
    while (!Spos.empty())
    {
        int nowX = Spos.top().x;
        int nowY = Spos.top().y;
        // Spos.pop();
        maze[nowX][nowY] = 2;
        // �ж��Ƿ���ʵ��յ�
        if (nowX == endX && nowY == endY)
        {
            printBoard("Ѱ·���");
            system("pause");
            return;
        }
        printBoard("");
        // ��4�������ƶ�
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
        // �ж��Ƿ���·����
        if (Spos.top().x == nowX && Spos.top().y == nowY)
        {
            maze[nowX][nowY] = 0;
            Spos.pop();
            vised[nowX][nowY] = 1;
            printBoard("");
        }
    }
    cout << "�޷��ҵ���·ǰ���յ�(" << endX << "," << endY << ")" << endl;
    system("pause");
}

void welcome()
{
    system("cls");
    cout << "���� 1 ��ʼ���Թ�ΪĬ���Թ�" << endl;
    cout << "���� 2 ��ʼ���Թ�Ϊ����Թ�" << endl;
    cout << "���� 3 ��ʼѰ·" << endl;
    cout << "���� -1 ��������" << endl;
}

int main()
{
    int opt;
    welcome();
    // �����������
    while (cin >> opt)
    {
        if (opt == -1)
            break;
        if (opt == 1)
        {
            defaultBoard();
            printBoard("��ʼ��Ĭ���Թ����");
            system("pause");
        }
        if (opt == 2)
        {
            genBoard();
            printBoard("��ʼ������Թ����");
            system("pause");
        }
        if (opt == 3)
        {
            cout << "��ʼѰ·" << endl;
            sleep(1);
            find();
        }
        welcome();
    }
    return 0;
}