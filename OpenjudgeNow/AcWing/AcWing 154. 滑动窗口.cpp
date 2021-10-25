#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <deque>
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

deque<int> Qmin,Qmax;
int n, k;
int num[Maxn], ansMin[Maxn], ansMax[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
        Qmin.push_back(1);
        Qmax.push_back(1);
    ansMin[1] = 1;
    ansMax[1] = 1;
    for (int i = 2; i <= n; i++)  
    {
        if (Qmin.size() && Qmin.front() + k - 1 < i)
            Qmin.pop_front();
        if (Qmax.size() && Qmax.front() + k - 1 < i)
            Qmax.pop_front();
        while (Qmin.size() && num[Qmin.back()] >= num[i])
            Qmin.pop_back();
        while (Qmax.size() && num[Qmax.back()] <= num[i])
            Qmax.pop_back();
        Qmin.push_back(i);
        Qmax.push_back(i);
        ansMin[i] = Qmin.front();
        ansMax[i] = Qmax.front();
    }
    for (int i = k; i <= n; i++)
        cout << num[ansMin[i]] << " ";
    cout << endl;
    for (int i = k; i <= n; i++)
        cout << num[ansMax[i]] << " ";
    return 0;
}