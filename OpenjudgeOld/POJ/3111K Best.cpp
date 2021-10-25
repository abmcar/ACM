#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iomanip>
#include<cstdio>
#define Maxn (int)1e5+233
using namespace std;

int n,k;
int v[Maxn],w[Maxn];
int finans[Maxn];
bool fin;
struct jewel
{
    int pos;
    double s;
};

bool cmp(jewel a,jewel b)
{
    return a.s > b.s;
}


bool check(double num)
{
    double ans = 0;
    jewel tempv[Maxn];
    for(int i = 1; i <= n; i++)
    {
        double tempb = (double)v[i] - num*(double)w[i];
        jewel tempj;
        tempj.s = tempb;
        tempj.pos = i;
        tempv[i-1] = tempj;
    }
    sort(tempv,tempv+n,cmp);
    for(int i = 0; i < k; i++)
        ans += tempv[i].s;
    if(fin)
        for(int i = 0; i < k; i++)
        finans[i] = tempv[i].pos;
    return ans >= 0;
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        scanf("%d %d",&v[i],&w[i]);
    double l = 0;
    double r = 1e6+10;
    double ans;
    while(r - l >= 1e-6)
    {
        double mid = (l+r)/2;
        if(check(mid))
        {
            l = mid;
        }
        else
            r = mid;
    }
    fin = 1;
    check(l);
    for(int i = 0; i < k; i++)
        cout << finans[i] << ' ';
    return 0;
}