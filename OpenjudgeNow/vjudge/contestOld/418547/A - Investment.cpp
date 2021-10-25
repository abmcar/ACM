#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

const int Maxn = 100010;
const int Multiple = 1000;

int t;
int nowans;
int years,m;
int v[Maxn];
int w[Maxn];
int f[Maxn];

void work()
{
    cin >> nowans >> years;
    cin >> m;
    nowans = nowans;
    for(int i = 1; i <= m; i++)
    {
        cin >> v[i] >> w[i];
        v[i] = v[i] / Multiple;
        w[i] = w[i];
    }
    for(int k = 1; k <= years; k++)
    {
        memset(f,0,sizeof(f));
        for(int i = 1; i <= m; i++)
        for(int j = v[i]; j <= nowans/1000; j++)
            f[j] = max(f[j],f[j - v[i]] + w[i]);
        nowans = nowans + f[nowans/1000];
        // cout << fixed << setprecision(2) << nowans << endl;
    }
    cout << nowans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
        work();
    return 0;
}