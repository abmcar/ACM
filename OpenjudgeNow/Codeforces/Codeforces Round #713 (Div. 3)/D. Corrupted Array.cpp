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

const int Maxn = 2e5 + 10;
const ll Mod = 1e9 + 7;

ll t, n;
ll num[Maxn];
ll totn, maxn;

void work()
{
    map<ll,ll> M;
    ll x, xpos;
    ll maxPos;
    x = -1;
    totn = maxn = 0;
    cin >> n;
    for (int i = 1; i <= n+2; i++)
    {
        cin >> num[i];
        totn += num[i];
        if (num[i] > maxn)
        {
            maxn = num[i];
            maxPos = i;
        }
        M[num[i]]++;
    }
    {
        num[maxPos] = -1;
        ll newmax = 0;
        int newmaxpos;
        ll newtot = 1;
        for (int i = 1; i <= n+2; i++)
        {
            newtot += num[i];
            if (num[i] > newmax)
            {
                newmax = num[i];
                newmaxpos = i;
            }
        }
        if (newtot == 2*newmax)
        {
            // cout << "pass1" << endl;
            for (int i = 1; i <= n+2; i++)
            {
                if (num[i] == -1 || i == newmaxpos)
                    continue;
                cout << num[i] << " ";
            }
            cout << endl;
            return;
        }
    }
    totn = totn - maxn;
    // if (maxn <= totn)
    // {
    //     cout << "-1" << endl;
    //     return;
    // }
    num[maxPos] = -1;
    M[maxn]--;
    bool ok = false;
    for (map<ll,ll>::iterator it = M.begin(); it != M.end(); it++)
    {
        if (totn-it->first == maxn && M[it->first] != 0)
        {
            x = it->first;
            ok = true;
            break;
        }
        // if (totn-it->first < maxn)
        // {
        //     cout << "-1" << endl;
        //     return;
        // }
    }
    if (!ok)
    {
        cout << "-1" << endl;
        return;
    }
    bool fir = true;
    // xpos = upper_bound(num+1,num+3+n,x) - num - 1;
    // cout << x << "   " << xpos << " " << num[xpos] << endl;
    for (int i = 1; i <= n+2; i++)
    {
        if (num[i] == -1)
            continue;
        if (num[i] == x && fir == true)
        {
            fir = false;
            continue;
        }
        cout << num[i] << " ";
    }
    cout << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}