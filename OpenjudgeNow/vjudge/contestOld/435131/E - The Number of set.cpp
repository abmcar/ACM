#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <unordered_map>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int ans;
bool now[Maxn];

void work()
{
    memset(now, false, sizeof(now));
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int nowNum,temp;
        int nowS = 0;
        cin >> nowNum;
        for (int j = 1; j <= nowNum; j++)
        {
            cin >> temp;
            temp--;
            nowS = nowS | (1 << temp);
        }
        now[nowS] = true;
        for (int j = 0; j < (1 << m); j++)
            if (now[j])
                now[j | nowS] = true;
        
    }
    for (int i = 0; i < (1 << m); i++)
        if (now[i])
            ans++;
    cout << ans << endl;
}

int main()
{
    Buff;
    while (cin >> n >> m)
        work();
    return 0;
}