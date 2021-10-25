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

const int Maxn = 1e4+10;
const ll Mod = 1e9+7;
int t,n;
int num[Maxn];
void work()
{
    ll haveBlocks = 0;
    ll needBlocks = 0;
    ll pos = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = 1; i <= n; i++)
    {
        ll temp = num[i];
        haveBlocks += temp;
        needBlocks += pos++;
        if(needBlocks > haveBlocks)
        {
            cout << "NO\n";
            return;
        }        
    }
    cout << "YES\n";
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}