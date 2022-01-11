#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 1010;

bool g[N][N], st[N][N];
int dist[N][N];

int bfs(int sx, int sy)
{
    deque<PII> q;
    q.push_back({sx, sy});
    memset(dist, 0x3f, sizeof dist);
    dist[sx][sy] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())
    {
        auto t = q.front();
        q.pop_front();

        if (st[t.x][t.y])
            continue;
        st[t.x][t.y] = true;

        if (!t.x && !t.y)
            break;

        for (int i = 0; i < 4; i++)
        {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x >= 0 && x < N && y >= 0 && y < N)
            {
                int w = 0;
                if (g[x][y])
                    w = 1;
                if (dist[x][y] > dist[t.x][t.y] + w)
                {
                    dist[x][y] = dist[t.x][t.y] + w;
                    if (!w)
                        q.push_front({x, y});
                    else
                        q.push_back({x, y});
                }
            }
        }
    }

    return dist[0][0];
}

int main()
{
    int n, sx, sy;
    scanf("%d%d%d", &n, &sx, &sy);
    while (n--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = true;
    }

    printf("%d\n", bfs(sx, sy));

    return 0;
}