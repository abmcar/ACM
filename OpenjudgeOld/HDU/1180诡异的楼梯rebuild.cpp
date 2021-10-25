#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int sx, sy, m, n, ans;
char a[20][20], ch;
bool vis[20][20];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}; //下右上左
struct node
{
    int x, y, step;
};
int check(node p)
{
    if (p.x >= 0 && p.x < m && p.y >= 0 && p.y < n && !vis[p.x][p.y]) //没有出界并且没有访问过
        return 1;
    else
        return 0;
}
int stair(node q, int i)
{
    if ((a[q.x][q.y] == '-' && i % 2 == 1 && (q.step - 1) % 2 == 0) || //楼梯开始时横着，人左右走，此时楼梯仍横着
        (a[q.x][q.y] == '-' && i % 2 == 0 && (q.step - 1) % 2 == 1) || //楼梯开始时横着，人上下走，此时楼梯旋转成竖着
        (a[q.x][q.y] == '|' && i % 2 == 0 && (q.step - 1) % 2 == 0) || //楼梯开始时竖着，人上下走，此时楼梯仍竖着
        (a[q.x][q.y] == '|' && i % 2 == 1 && (q.step - 1) % 2 == 1))   //楼梯开始时竖着，人左右走，此时楼梯旋转成横着
        return 1;
    else
        return 0;
}
void bfs()
{
    queue<node> Q;
    node p, q;
    p.x = sx;
    p.y = sy;
    p.step = 0;
    Q.push(p);
    while (!Q.empty())
    {
        p = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            q.x = p.x + dir[i][0];
            q.y = p.y + dir[i][1];
            q.step = p.step + 1;

            if (check(q) && a[q.x][q.y] != '*')
            {
                if (a[q.x][q.y] == 'T')
                {
                    ans = q.step;
                    return;
                }
                if (a[q.x][q.y] == '.')
                {
                    vis[q.x][q.y] = true;
                    Q.push(q);
                }
                if (a[q.x][q.y] == '-' || a[q.x][q.y] == '|')
                {
                    if (stair(q, i))
                    {
                        q.x = q.x + dir[i][0];
                        q.y = q.y + dir[i][1];
                        if (check(q) && a[q.x][q.y] != '*')
                        {
                            if (a[q.x][q.y] == 'T')
                            {
                                ans = q.step;
                                return;
                            }
                            vis[q.x][q.y] = true;
                            Q.push(q);
                        }
                    }
                    else
                    {
                        q = p;
                        q.step++;
                        Q.push(q);
                    }
                }
            }
        }
    }
}
int main()
{
    while (cin >> m >> n)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> ch;
                a[i][j] = ch;
                if (ch == 'S')
                {
                    sx = i;
                    sy = j;
                }
            }
        memset(vis, 0, sizeof(vis));
        vis[sx][sy] = true;
        bfs();
        cout << ans << endl;
    }
    return 0;
}