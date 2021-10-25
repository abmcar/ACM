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
// #include <unordered_set>
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
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
const ll Mod = 2e10;

int t;
ll n, s;
ll nums[Maxn];
ll nowNum;
ll ansL, ansR;
ll ans = 2e10;
String opts;

void work()
{
    ans = 2e10;
    cin >> n;
    cin >> opts;
    unordered_map<ll, vector<ll>> M;
    nums[0] = 0;
    opts = '-' + opts;
    for (int i = 0; i <= n; i++)
    {
        char nowChar = opts[i];
        nums[i] = nums[i-1];
        if (nowChar == 'L')
            nums[i]++;
        else if (nowChar == 'R')
            nums[i]--;
        else if (nowChar == 'U')
            nums[i]+=1e6;
        else if (nowChar == 'D')
            nums[i]-=1e6;
        M[nums[i]].push_back(i);
        // cout << nums[i] << " ";
    }
    // cout << endl;
    for (auto it : M)
    {
        if (it.second.size() >= 2)
        {
            int prePos = it.second[0];
            for (int i = 1; i < it.second.size(); i++)
            {
                if (ans > it.second[i]-prePos)
                {
                    ans = it.second[i]-prePos;
                    ansL = prePos;
                    ansR = it.second[i];
                }
                prePos = it.second[i];
            }
        }
    }
    if (ans == 2e10)
        cout << -1 << endl;
    else
        cout << ansL+1 << " " << ansR << endl;
}

int main()
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