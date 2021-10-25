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

int t, n;
string oriString;

void work()
{
    cin >> n;
    cin >> oriString;
    for (int k = 0; k < oriString.size(); k++)
    for (int i = 0; i < oriString.size(); i++)
    {
        if (i != oriString.size() - 1)
        {
            if (oriString[i] == '?' && oriString[i+1] == 'B')
                oriString[i] = 'R';
            if (oriString[i] == '?' && oriString[i+1] == 'R')
                oriString[i] = 'B';
        }
        if (i != 0)
        {
            if (oriString[i] == '?' && oriString[i-1] == 'B')
                oriString[i] = 'R';
            if (oriString[i] == '?' && oriString[i+-1] == 'R')
                oriString[i] = 'B';
        }
    }
    if (oriString[0] == '?')
    for (int i = 0; i < oriString.size(); i++)
        if (i % 2)
            oriString[i] = 'B';
        else
            oriString[i] = 'R';
    cout << oriString << endl;
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