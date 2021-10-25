#include<iostream>
#include<algorithm>
#define Maxn (int)1e3+10

using namespace std;

int n;
int high[Maxn];
int ans = 1e9;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> high[i];
    for(int i = 1; i < 84; i++)
    {
        int temp = 0;
        int l = i;
        int r = i + 17;
        for(int j = 1; j <= n; j++)
        {
            if(high[j] < l) temp = temp + (high[j]-l)*(high[j]-l);
            if(high[j] > r) temp = temp + (r-high[j])*(r-high[j]);
        }
        ans = min(ans,temp);
    }
    cout << ans;
    return 0;
}