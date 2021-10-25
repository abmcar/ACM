#include<iostream>
#include<algorithm>
#define Maxn (int)1e6+10
using namespace std;

int n,m;
long long r[Maxn];
long long changer[Maxn];
long long findd[Maxn];

struct request
{
    int strday;
    int endday;
    long long d;
    int pos;
    void get()
    {
        cin >> d >> strday >> endday;
    }
}quest[Maxn];

bool check(int num)
{
    bool ok = 0;
    for(int i = 1; i <= n; i++)
        changer[i] = 0;
    for(int i = 1; i <= num; i++)
    {
        changer[quest[i].strday] += quest[i].d;
        changer[quest[i].endday+1] -= quest[i].d;
    }
    for(int i = 0; i <= n; i++)
        findd[i] = 0;
    long long nownum = 0;
    for(int i = 0; i <= n; i++)
    {
        nownum += changer[i];
        findd[i] += nownum;
        // cout << findd[i] << " ";
        if(findd[i] > r[i])
        {
            ok = 1;
            // break;
        }
    }
    // cout << endl;
    return ok;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> r[i];
    for(int i = 1; i <= m; i++)
        quest[i].get(),quest[i].pos = i;

    // sort(quest+1,quest+1+m,cmp);
    long long tl = 0;
    long long tr = m;
    long long ans = m+233;
    while(tl <= tr)
    {
        long long mid = (tl+tr)/2;
        // cout << tl << " " << mid << " " << tr << endl;
        if(check(mid))
        {
            ans = min(ans,mid);
            tr = mid-1;
        }else
            tl = mid+1;
    }
    if(ans == m+233)
    {
        cout << "0";
        return 0;
    }
    cout << "-1" << endl;
    cout << ans;
    return 0;
}