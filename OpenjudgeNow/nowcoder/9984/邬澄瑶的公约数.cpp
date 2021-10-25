#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int n;
ll ans = 1;
ll g;
ll tx[Maxn],tp[Maxn];
ll tans[Maxn];
ll minn = 1e10;
vector<ll> tg;
bool used[Maxn];
bool isprime[Maxn];
vector<ll> primes;
map<ll,ll> M,M1;

ll quickPow(ll x, ll p)
{
    ll now = 1;
    ll base = x;
    while(p != 0)
    {
        if(p%2 == 1)
        {
            now = now*base%Mod;
            p--;
            continue;
        }
        base = base*base%Mod;
        p = p/2;
    }
    // cout << now << "\n";
    return now % Mod;
}


int main()
{
    Buff;
    for(ll i = 2; i <= 1e4; i++)
    {
        if(used[i] == 0)
        {
            isprime[i] = true;
            for(int j = 1; j * i <= 1e4; j++)
                used[i*j] = true;
            primes.push_back(i);
        }
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> tx[i];
    for(int i = 1; i <= n; i++)
        cin >> tp[i];
    for(auto j : primes)
        while(tx[1] % j == 0)
        {
            if(isprime[tx[1]] == true)
            {
                M[tx[1]]++;
                break;
            }
            tx[1] = tx[1] / j;
            M[j]++;
        }
    for(map<ll,ll>::iterator it = M.begin(); it != M.end(); it++)
    {
        // cout << it.first << " " << it.second << "\n";
        it->second = it->second * tp[1];
        // cout << it->first << " " << it->second << "\n";
    }
    for(int i = 2; i <= n; i++)
    {
        map<ll,ll> tm;
        for(auto j : primes)
            while(tx[i] % j == 0)
            {
                if(isprime[tx[i]] == true)
                {
                    tm[tx[i]]++;
                    break;
                }
                tx[i] = tx[i] / j;
                tm[j]++;
            }
        for(map<ll,ll>::iterator it = tm.begin(); it != tm.end(); it++)
        {
            it->second *= tp[i];
            // cout << it->first << " " << it->second << "\n";
        }
        for(map<ll,ll>::iterator it = M.begin(); it != M.end(); it++)
        {
            it->second = min(tm[it->first],it->second);
            // cout << it->first << " " << it->second << "\n";
        }
    }
    for(auto it : M)
    {
        if(it.second != 0)
            ans = ((ans%Mod)*(quickPow(it.first,it.second)%Mod))%Mod;
    }
    cout << ans;
}