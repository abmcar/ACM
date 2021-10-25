#include<iostream>
#include<algorithm>

using namespace std;

int n,c;
long long num[(int)1e6+10];
long long ans;

inline int Search(long long number)
{
    int l = 1;
    int r = n;
    int ans = -1;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(num[mid] >= number)
        {
            if(num[mid] == number)
            ans = mid;
            r = mid;
        }else
            l = mid+1;
        if(l == mid && r == mid)
            break;
    }
    return ans;
}

inline int Search1(long long number)
{
    int l = 1;
    int r = n;
    int ans = -1;
    while(l <= r)
    {
        //cout << l << " " << r << endl;
        int mid = (l+r+1)/2;
        if(num[mid] <= number)
        {
            if(num[mid] == number)
            ans = mid;
            l = mid;
        }else
            r = mid-1;
        if(l == mid && r == mid)
            break;
    }
    return ans+1;
}


int main()
{
    std::ios::sync_with_stdio(false);
    // freopen("a.in","r",stdin);
    cin >> n >> c;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    sort(num+1,num+1+n);
    for(int i = 1; i <= n; i++)
    {
        int strpos = Search(num[i]+c);
        if(strpos == -1)
            continue;
        long long cut = Search1(num[i]+c) - Search(num[i]+c);
        if(strpos == i)
        cut--;
        // cout << i << " " << Search1(num[i]+c) << " " << Search(num[i]+c) << endl;
        // cout << i << " " << (upper_bound(num+1,num+1+n,num[i]+c)-num) << " " <<(lower_bound(num+1,num+1+n,num[i]+c)-num) << endl;
        ans += cut;
    }
    cout << ans;
    return 0;
}