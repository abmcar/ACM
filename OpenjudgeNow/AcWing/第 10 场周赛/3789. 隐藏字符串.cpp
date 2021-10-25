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
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

unordered_map<string, int> M;
string oriS;
int len;
int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> oriS;
    len = oriS.size();
    for (int i = 0; i < len; i++)
        M[string(1,oriS[i])]++;
    for (int l = 2; l <= len; l++)
    {
        for (int i = 0; i < len; i++)
        {
            for (int d = 0; (i+l + (l - 1) * d-1) <= len; d++)
            {
                int nowPos = i;
                string nowS = "";
                for (int j = 1; j <= l; j++)
                {
                    nowS = nowS + oriS[nowPos];
                    nowPos = nowPos + d + 1;
                }
                // cout << i << " ";
                // cout << nowS << endl;
                M[nowS]++;
            }
        }
    }
    int maxn = 0;
    for (auto i : M)
    {
        // cout << i.first << " " << i.second << endl;
        maxn = max(maxn, i.second);
    }
    cout << maxn << endl;
    return 0;
}