#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>
#define ll long long

using namespace std;

const int Maxn = 3000100;
const ll Mod = 1e9+7;
vector<double> prices;
double f[Maxn];
double q;
int n;

void work()
{
    prices.clear();
    memset(f,0,sizeof(f));
    q *= 100;
    for(int i = 1; i <= n; i++)
    {
        int cnt;
        cin >> cnt;
        char type,temp;
        double nowprice;
        double cnta,cntb,cntc;
        cnta = cntb = cntc = 0;
        bool isok = true;
        for(int j = 1; j <= cnt; j++)
        {
            cin >> type >> temp;
            cin >> nowprice;
            nowprice *= 100;
            if(type >= 'A' && type <= 'C')
            {
                if(type == 'A')
                    cnta += nowprice;
                if(type == 'B')
                    cntb += nowprice;
                if(type == 'C')
                    cntc += nowprice;
            }
            else
            {
                isok = false;
                break;
            }
            if(cnta > 60000 || cntb > 60000 || cntc > 60000)
                isok = false;
            if(cnta+cntb+cntc > 100000)
                isok = false;
        }
        if(isok)
        prices.push_back(cnta+cntb+cntc);
    }
    for(int i = 0; i < prices.size(); i++)
    for(int j = q; j >= prices[i]; j--)
        f[j] = max(f[j],f[j-(int)prices[i]] + prices[i]);
    cout << fixed << setprecision(2);
    cout << f[(int)q]/100 << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> q >> n)
    {
        if(n == 0)
            return 0;
        work();
    }
    return 0;
}