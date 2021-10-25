#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 30000+10;
int n,m;
int v[Maxn],p[Maxn],w[Maxn];
int f[Maxn];

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> v[i] >> p[i], w[i] = v[i] * p[i];
    for(int i = 1; i <= m; i++)
    for(int j = n; j >= v[i]; j--)
        f[j] = max(f[j],f[j - v[i]] + w[i]);
    cout << f[n];
    return 0;
}

/*
f[j] = max(f[j],f[j-v[i]]+w[i])
*/
