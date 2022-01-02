#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;
int ans, cnt;
bool vis[123][123][123];
int nx[] = {0, 1, 0, -1};
int ny[] = {1, 0, -1, 0};

int praseInt(String nowString)
{
    int nowNum = 0;
    int cnt = 1;
    for (int i = nowString.size() - 1; i >= 0; i--)
    {
        // cout << nowString[i] << " " << nowNum << " " << (nowString[i] - '0') * cnt << endl;
        nowNum += (int)(nowString[i] - '0') * cnt;
        cnt = cnt * 10;
    }
    return nowNum;
}

void work()
{
    memset(vis, 0, sizeof vis);
    String oriString;
    cin >> n;
    int totAns, pos;
    totAns = 0;
    pos = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> oriString;
        if (pos)
            continue;
        String s1 = oriString.substr(0, oriString.find(','));
        oriString = oriString.substr(oriString.find(',') + 1);
        String s2 = oriString.substr(0, oriString.find(','));
        oriString = oriString.substr(oriString.find(',') + 1);
        String s3 = oriString;
        int nowX = praseInt(s1) + 1;
        int nowY = praseInt(s2) + 1;
        int nowZ = praseInt(s3) + 1;
        int now = 6;
        // cout << nowX << " " << nowY << " " << nowZ << " " << totAns << endl;
        vis[nowX][nowY][nowZ] = true;
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + nx[i];
            int nextY = nowY + ny[i];
            if (vis[nextX][nextY][nowZ])
            {
                now--;
                totAns--;
                continue;
            }
        }
        if (vis[nowX][nowY][nowZ + 1])
        {
            now--;
            totAns--;
            // continue;
        }
        if (vis[nowX][nowY][nowZ - 1])
        {
            now--;
            totAns--;
            // continue;
        }
        if (pos == 0)
            if (now == 6 && i != 1)
            {
                // cout << i << " !!!! " << endl;
                pos = i;
            }
        totAns += now;
        // cout << i << " " << now << " :: " << totAns << endl;
        // cout << s1 << " " << s2 <<  " " << s3 << endl;
        // cout << praseInt(s1) << " " << praseInt(s2) << " " << praseInt(s3) << endl;
    }
    cout << ++cnt;
    if (pos)
    {
        cout << " NO " << pos << endl;
        return;
    }
    cout << " " << totAns << endl;
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