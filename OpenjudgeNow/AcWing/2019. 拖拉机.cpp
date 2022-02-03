#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, strX, strY;
int nx[] = {0, 1, 0, -1};
int ny[] = {1, 0, -1, 0};
vector<vector<int>> bd(2010, vector<int>(2010)), dis(2010, vector<int>(2010)), vis(2010, vector<int>(2010));

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> strX >> strY;
    auto Fun_resize = [&](auto it) -> void
    {
        it.resize(n + 10);
    };
    for (int i = 1; i <= n; i++)
    {
        int tx, ty;
        cin >> tx >> ty;
        bd[tx][ty] = 1;
    }
    deque<pair<int, int>> Q;
    Q.push_back({strX, strY});
    for (int i = 0; i <= 1010; i++)
        for (int j = 0; j <= 1010; j++)
            dis[i][j] = Maxn;
    dis[strX][strY] = 0;
    while (!Q.empty())
    {
        auto nowQ = Q.front();
        int nowX = nowQ.first;
        int nowY = nowQ.second;
        Q.pop_front();
        if (vis[nowX][nowY])
            continue;
        vis[nowX][nowY] = true;
        if (nowX == nowY && nowX == 0)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + nx[i];
            int nextY = nowY + ny[i];
            if (nextX < 0 || nextY < 0 || nextX >= 1005 >> nextY >= 1005)
                continue;
            int addDis = bd[nextX][nextY];
            if (dis[nextX][nextY] > dis[nowX][nowY] + addDis)
            {
                dis[nextX][nextY] = dis[nowX][nowY] + addDis;
                if (addDis)
                    Q.push_back({nextX, nextY});
                else
                    Q.push_front({nextX, nextY});
            }
        }
    }
    cout << dis[0][0] << endl;
    return 0;
}