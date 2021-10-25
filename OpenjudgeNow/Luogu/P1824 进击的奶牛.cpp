#include<iostream>
#include<algorithm>

using namespace std;

int n;
long long c;
long long num[100100];

bool check(long long mid)
{
    long long cut = 0;
    long long now = num[1];
    for(int i = 2; i <= n; i++)
        if(now+mid > num[i])
            cut++;
        else
            now = num[i];
    return cut <= (n-c);
}

int main()
{
    cin >> n >> c;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    sort(num+1,num+1+n);
    long long l = 1;
    long long r = 1000000000;
    long long ans;
    while(l <= r)
    {
        // cout << l << " " << r << endl;
        long long mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            l = mid+1;
        }else
            r = mid-1;
    }
    cout << ans;
    return 0;
}