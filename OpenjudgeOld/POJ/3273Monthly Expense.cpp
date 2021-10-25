#include<iostream>
#include<algorithm>
#define Maxn 100010

using namespace std;

int n,m;
int days[Maxn];
int minn = 1e9;
int maxn;

bool check(int num)
{
    int nowcost;
    int nowarrange;
    nowcost = 0;
    nowarrange = 1;
    for(int i = 1; i <= n+1; i++)
    {
        if(days[i] > num)
            return false;
        if(nowcost + days[i] > num)
        {
            nowarrange++;
            nowcost = days[i];
        }else
        nowcost += days[i];
        // cout << "i:" << i << " " << nowcost << " " << nowarrange << endl;
    }
    // cout << num << "  " << nowarrange << endl;
    return nowarrange <= m;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> days[i];
        minn = min(minn,days[i]);
        maxn = max(maxn,days[i]);
    }
    int l = maxn;
    int r = 1e8;
    int ans;
    while(l <= r)
    {
        // cout << l << ' ' << r << endl; 
        int mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            r = mid-1;
        }else
            l = mid+1;
    }
    cout << ans;
    return 0;
}