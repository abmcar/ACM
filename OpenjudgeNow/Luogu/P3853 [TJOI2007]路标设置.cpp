#include<iostream>
#include<algorithm>

using namespace std;

long long l;
int n,k;
int dis[100010];

bool check(long long num)
{
    long long now = dis[1];
    int cut = 0;
    for(int i = 2; i <= n; i++)
    {
        if(now+num < dis[i])
        {
            while(now+num < dis[i])
            {
                cut++;
                now += num;
            }
            now = dis[i];
        }
        else
            now = dis[i];
    }
    return (cut <= k);
}

int main()
{
    cin >> l >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> dis[i];
    long long tl = 1;
    long long tr = l;
    long long ans = -1;
    while(tl <= tr)
    {
        // cout << l << "  " << r << endl;
        long long mid = (tl+tr)/2;
        if(check(mid))
        {
            ans = mid;
            tr = mid-1;
        }else
            tl = mid+1;
    }
    if(ans == -1)
        ans = tl;
    cout << ans;
    return 0;
}