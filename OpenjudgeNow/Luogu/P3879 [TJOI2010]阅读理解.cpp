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
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const ll Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

ll n, m;
ll sons[Maxn][32], idx;
set<ll> cnt[Maxn];
vector<String> words[Maxn];
vector<String> rawWords;

bool insert(String string, ll pos)
{
    ll nowNode = 0;
    for (char nowChar : string)
    {
        ll nextChar = nowChar - 'a';
        if (!sons[nowNode][nextChar])
            sons[nowNode][nextChar] = ++idx;
        nowNode = sons[nowNode][nextChar];
    }
    cnt[nowNode].insert(pos);
}

set<ll> query(String string)
{
    set<ll> tempS;
    ll nowNode = 0;
    for (char i : string)
    {
        ll nextChar = i - 'a';
        if (!sons[nowNode][nextChar])
            return tempS;
        nowNode = sons[nowNode][nextChar];
    }
    return cnt[nowNode];
}

void init()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll nowSize;
        cin >> nowSize;
        for (ll j = 1; j <= nowSize; j++)
        {
            String nowWord;
            cin >> nowWord;
            words[i].push_back(nowWord);
        }
    }
    cin >> m;
    for (ll i = 1; i <= m; i++)
    {
        String nowString;
        cin >> nowString;
        rawWords.push_back(nowString);
    }
}

void work()
{
    for (ll i = 1; i <= n; i++)
        for (String string : words[i])
            insert(string,i);
    for (ll i = 1; i <= m; i++)
    {
        set<ll> nowAns = query(rawWords[i-1]);
        bool fir = true;
        for (int nowInt : nowAns)
        {
            if (!fir)
                cout << " ";
            else
                fir = false;
            cout << nowInt;
        }
        cout << endl;
    }
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    init();
    work();
    return 0;
}