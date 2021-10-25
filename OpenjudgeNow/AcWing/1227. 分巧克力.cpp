#include<iostream>
#include<algorithm>
#define Maxn (int)1e6+10
using namespace std;

int k,n;
int h[Maxn],w[Maxn];

bool check(int num)
{
    int cut = 0;
    for(int i = 1; i <= n; i++)
        cut += (h[i]/num)*(w[i]/num);
    return cut >= k;
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> h[i] >> w[i];
    int l = 0;
    int r = 1e5;
    int ans;
    while(l <= r)
    {
        // cout << l << "  " << r << endl;
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