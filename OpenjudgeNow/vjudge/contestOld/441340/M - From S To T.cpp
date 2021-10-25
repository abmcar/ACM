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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int q;
string s, p, t;

void work()
{
    map<char,int> M;
    cin >> s >> t >> p;
    int nowS = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == s[nowS])
            nowS++;
        else
            M[t[i]]++;
    }
    // cout << nowS << endl;
    if (nowS != s.size())
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < p.size(); i++)
        M[p[i]] = max(0, M[p[i]]-1);
    for (map<char,int>::iterator it = M.begin(); it != M.end(); it++)
        if (it->second > 0)
        {
            // cout << it->first << endl;
            cout << "NO" << endl;
            return;
        }
    cout << "YES" << endl;
}

int main()
{
    Buff;
    cin >> q;
    while (q--)
        work();
    return 0;
}