#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int n, k, cntPos;
int num[Maxn];
vector<int> V[Maxn];
int totAns[Maxn];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int totAns = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> num[i], totAns += num[i];
    sort(num + 1, num + 1 + n);
    int nowPos = 1;
    int nowAns = 0;
    cntPos = 1;
    while (nowPos <= n)
    {
        nowAns += num[nowPos];
        V[cntPos].push_back(num[nowPos]);
        totAns = totAns - num[nowPos];
        if (nowAns != 0)
        {
            cntPos++;
        }
    }
}