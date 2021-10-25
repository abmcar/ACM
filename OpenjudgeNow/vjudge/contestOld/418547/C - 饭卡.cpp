#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 1e4+10;
const ll Mod = 1e9+7;
int n,m;
int v[Maxn],f[Maxn];

void work()
{
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    cin >> m;
    if(m < 5)
    {
        cout << m << endl;
        return;
    }
    sort(v+1,v+1+n);
    int nowans = m - 5;
    memset(f,0,sizeof(f));
    for(int i = 1; i < n; i++)
    for(int j = nowans; j >= v[i]; j--)
        f[j] = max(f[j],f[j-v[i]]+v[i]);
    cout << m-f[nowans]-v[n] << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> n)
    {
        if(n == 0)
            return 0;
        work();
    }
}