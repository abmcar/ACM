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

const int Maxn = 1e5+10;
const ll Mod = 1e9+7;
int t,n;
int maxn;
int g[Maxn];

void work()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int ta,tb;
        cin >> ta >> tb;
    }
    if(n == 1)
        cout << "1\n";
    else
        cout << "2\n";
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}