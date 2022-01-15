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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;

int nx[] = {1, 0, -1, 0};
int ny[] = {0, 1, 0, -1};
vector<int> M[Maxn];

void work()
{
    cin >> n >> m;
    queue<pair<int, int>> Q;
    for (int i = 1; i <= n; i++)
        M[i].resize(m + 1), M[i].clear();
    map<int, int> ans;
    for (int i = (n + 1) / 2; i <= (n + 2) / 2; i++)
        for (int j = (m + 1) / 2; j <= (m + 2) / 2; j++)
        {
            Q.push({i, j});
            M[i][j] = 1;
        }
    while (!Q.empty())
    {
        int nowX = Q.front().first;
        int nowY = Q.front().second;
        Q.pop();
        ans[M[nowX][nowY]]++;
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + nx[i];
            int nextY = nowY + ny[i];
            int nextV = M[nowX][nowY] + 1;
            if (nextX < 1 || nextY < 1 || nextX > n || nextY > m)
                continue;
            if (M[nextX][nextY] != 0)
                continue;
            M[nextX][nextY] = nextV;
            Q.push({nextX, nextY});
        }
    }
    int oriAns = n / 2 + m / 2;
    for (auto it : ans)
    {
        if (it.second == 0)
            continue;
        int cnt = it.second;
        for (int i = 1; i <= cnt; i++)
            cout << oriAns << " ";
        oriAns++;
    }
    cout << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}