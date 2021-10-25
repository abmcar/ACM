#include <iostream>
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
int c,n,m;
int w[Maxn],v[Maxn],num[Maxn];
int f[Maxn];

void work()
{
    memset(f,0,sizeof(f));
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> v[i] >> w[i] >> num[i];
    for(int i = 1; i <= m; i++)
    {
        int tempnum = num[i];
        int base = 1;
        while(tempnum != 0)
        {
            for(int j = n; j >= v[i]*base; j--)
                f[j] = max(f[j],f[j-v[i]*base] + w[i]*base);
            tempnum = tempnum - base;
            if(tempnum == 0)
                break;
            base *= 2;
            if(base > tempnum)
                base = tempnum;
        }
    }
    // int tempmaxn = 0;
    // for(int i = 1; i <= n; i++)
    //     tempmaxn = max(tempmaxn,f[i]);
    cout << f[n] << endl;
}

int main()
{
    Buff;
    cin >> c;
    while(c--)
        work();
    return 0;
}