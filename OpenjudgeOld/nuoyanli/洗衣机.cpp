#include<iostream>
#include<algorithm>

using namespace std;

int n,k;
int num[2333];

bool check(int nownum)
{
    int nowans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= 2333; j++)
            if(nownum+j*k >= num[i])
            {
                nowans += j;
                break;
            }
    }
    return nowans <= nownum;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    cin >> k;
    int l = 0;
    int r = 1e8;
    int ans;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            r = mid-1;
        }else
            l = mid+1;
    }
    cout << ans;
}