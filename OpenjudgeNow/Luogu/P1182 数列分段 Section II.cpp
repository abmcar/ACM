#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
long long preans[(int)1e6+10];
long long num[(int)1e6+10];

bool check(long long nownum)
{
    long long now = 1;
    long long cut = 0;
    for(int i = 1; i <= n; i++)
    {
        if(preans[i]-preans[now-1] >= nownum)
            cut++,now=i;
    }
    return (cut >= m);
}

int main()
{
    cin >> n >> m;
    long long l = 0;
    long long r = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        cin >> num[i],l = max(l,num[i]),r += num[i];
    for(int i = 1; i <= n; i++)
        preans[i] += preans[i-1]+num[i];
    ans = -1;
    // cout << ans << " " << r << endl;
    while(l <= r)
    {
        // cout << l << " " << r << endl;
        long long mid = (r+l)/2;
        if(check(mid))
        {
            ans = mid;
            l = mid+1;
        }else
            r = mid-1;
    }
    if(ans == -1)
        ans = r+1;
    cout << ans;
    return 0;
}