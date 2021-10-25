#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e6+10;
const ll Mod = 1e9+7;
ll t,n,num[Maxn];

void work()
{
    // memset(num,0,sizeof(num));
    map<ll,int> M;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        M[num[i]]++;

    }
    ll minans = 1e9;
    int nowpos = 0;
    ll now = 0;
    for(map<ll,int>::iterator it = M.begin(); it != M.end(); it++)
    {
        num[nowpos++] = it->second;
    }
    sort(num,num+M.size());
    nowpos = 0;
    for(map<ll,int>::iterator it = M.begin(); it != M.end(); it++)
    {
        minans = min(n-(M.size()-nowpos)*num[nowpos],minans);
        // cout << now << " " << M.size() << " " << nowpos << " " << num[nowpos] << endl;
        now += num[nowpos];
        nowpos++;
    }
    cout << minans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}