#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
long long k;

bool check(int num)
{
    long long cut = num;
    long long  nowleft = k-1;
    long long  tl = max(num-1,1);
    long long  tr = max(num-1,1);
    long long  nowright = k+1;
    while(nowleft >= 1)
    {
        if(cut > m)
            return false;
        if(tl == 1)
        {
            cut += nowleft;
            break;
        }
        cut += tl;
        nowleft--;
        tl = max(tl-1,(long long)1);
    }
    while(nowright <= n)
    {
        if(cut > m)
            return false;
        if(tr == 1)
        {
            cut += n-nowright+1;
            break;
        }
        cut += tr;
        nowright++;
        tr = max(tr-1,(long long )1);
    }
    // cout << cut << endl;
    return cut <= m;
}

int main()
{
    cin >> n >> m >> k;
    int l = 1;
    int r = 1e9;
    int ans;
    while(l <= r)
    {
        // cout << l << " " << r << endl;
        int mid = (l+r)/2;
        if(check(mid))
        {
            l = mid+1;
            ans = mid;
        }else
            r = mid-1;
    }
    cout << ans;
    return 0;
}