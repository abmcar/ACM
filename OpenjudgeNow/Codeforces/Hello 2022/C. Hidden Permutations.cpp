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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <unordered_set>
// #include <ext/pb_ds/priority_queue.h>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
// #define endl "\n"
// #define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e4 + 10;
const ll Mod = 1e9 + 7;

int n, t, cnt;
int father[Maxn];
map<int, int> M;

int find(int x)
{
    if (x == father[x])
        return x;
    father[x] = find(father[x]);
    return father[x];
}

int query(int pos)
{
    cout << "? " << pos << endl;
    int targetVal;
    cin >> targetVal;
    return targetVal;
}

void work()
{
    cin >> n;
    M.clear();
    cnt = 0;
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int k = 1; k <= n; k++)
    {
        if (cnt == n)
            break;
        if (M[find(k)] != 0)
            continue;
        int nowNum = query(k);
        while (M[nowNum] == 0)
        {
            int newNum = query(k);
            M[nowNum] = newNum;
            father[find(nowNum)] = find(newNum);
            nowNum = newNum;
            cnt++;
            if (cnt == n)
                break;
        }
    }
    // ll tot = 0;
    // for (int i = 1; i <= n; i++)
    //     tot += M[i];
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << M[i] << " ";
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