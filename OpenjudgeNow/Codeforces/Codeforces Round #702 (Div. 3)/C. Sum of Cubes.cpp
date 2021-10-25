#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
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
map<ll,ll> cube;
map<ll,bool> ok;
vector<ll> finnum;
int t;
int main()
{
    Buff;
    for(ll i = 1; i*i*i <= 1e12; i++)
        cube[i] = i*i*i,ok[i*i*i] = true; 
    cin >> t;
    while(t--)
    {
        ll temp;
        bool isok = false;
        cin >> temp;
        for(ll i = 1; i <= 1e4; i++)
            if(ok[temp-cube[i]] == true)
            {
                isok = true;
                cout << "YES" << endl;
                break;
            }
        if(!isok)
            cout << "NO" << endl;
    }
    return 0;
}