#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int t;
int m,k;

struct node
{
    long long l,r,s;
}tnode[(int)3e6];

bool cmp(node a,node b)
{
    return a.l < b.l;
}

bool cmpp(node a,node b)
{
    return a.r > b.r;
}

void work()
{
    long long ans = 0;
    cin >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> tnode[i].l >> tnode[i].r >> tnode[i].s;
        if(tnode[i].r >= 1e9)
            tnode[i].r = 1e9;
    }
    sort(tnode+1,tnode+1+m,cmp);
    for(int i = 1; i <= m; i++)
    {
        long long nowans = 0;
        for(int j = i; j <= m; j++)
        {
            if(min((long long)1e9,tnode[i].l+k-1) <= tnode[j].r)
            {
                nowans += tnode[j].s * (min((long long)1e9,tnode[i].l+k-1) - tnode[j].l + 1);
                break;
            }
            nowans += tnode[j].s * (min((long long)1e9,tnode[j].r) - tnode[j].l + 1);
        }
        ans = max(nowans,ans);
    }
    sort(tnode+1,tnode+1+m,cmpp);
    for(int i = 1; i <= m; i++)
    {
        long long nowans = 0;
        for(int j = i; j <= m; j++)
        {
            if(max((long long)0,tnode[i].r-k+1) >= tnode[j].l)
            {
                nowans += tnode[j].s * (tnode[j].r - max((long long)0,tnode[i].r-k+1) + 1);
                break;
            }
            nowans += tnode[j].s * (tnode[j].r - tnode[j].l + 1);
        }
        ans = max(nowans,ans);
    }
    cout << ans << endl;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}