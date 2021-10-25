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
#include <cstddef>
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
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int sons[Maxn][26], idx;
map<int,vector<int> > cnt;
void insert(String string, int pos)
{
    int nowNode = 0;
    for (char i : string)
    {
        int nextChar = i - 'a';
        if (!sons[nowNode][nextChar])
            sons[nowNode][nextChar] = ++idx;
        nowNode = sons[nowNode][nextChar];
    }
    cnt[nowNode].push_back(pos);
}

vector<int> query(String string)
{
    int nowNode = 0;
    for (char i : string)
    {
        int nextChar = i - 'a';
        if (!sons[nowNode][nextChar])
            return vector<int>(0);
        nowNode = sons[nowNode][nextChar];
    }
    return cnt[nowNode];
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    return 0;
}