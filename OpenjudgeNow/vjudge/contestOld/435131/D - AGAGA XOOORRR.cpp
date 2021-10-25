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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;
ll num[Maxn];
ll preXor[Maxn], aftXor[Maxn];

void work()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    ll temp = 0;
    for (int i = 1; i <= n; i++)
        temp = temp xor num[i];
    if (temp == 0)
    {
        cout << "YES" << endl;
        return;
    }
    ll ans = temp;
    temp = 0;
    int nowS = 0;
    for (int i = 1; i <= n; i++)
    {
        temp = temp xor num[i];
        if (temp == ans)
        {
            temp = 0;
            nowS++;
        }
    }
    if (temp == 0 && nowS >= 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    // for (int i = 1; i <= n; i++)
    //     preXor[i] = preXor[i - 1] xor num[i];
    // for (int i = n; i >= 1; i--)
    //     aftXor[i] = aftXor[i + 1] xor num[i];
    
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}