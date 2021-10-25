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
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;

void work()
{
    cin >> n;
    vector<long double> nowV;
    unordered_map<long double, int> M;
    long double nowTot = 0;
    long double avg;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        nowV.push_back(temp);
        nowTot += temp;
    }
    avg = nowTot / n;
    for (int i = 0; i < n; i++)
        M[nowV[i]]++;
    for (auto it : nowV)
    {
        ans += M[2*avg-it];
        if (it == 2*avg-it)
            ans--;
        // cout << it << " " <<M[(it-avg)*-1] << " " << ans << endl;
    }
    cout << ans / 2 << endl;
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
// 2*avg - it 