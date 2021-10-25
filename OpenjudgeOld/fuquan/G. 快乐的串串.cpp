#include<iostream>
#include<string>
#include<algorithm>
#define Maxn (int)1e6+10
using namespace std;

string s;
int pre0[Maxn];
int pre1[Maxn];
int ans;

bool check(int num)
{
    if(num == 0)
        return true;
    if(num % 2 == 1)
        num--;
    int n0,n1;
    int nowans = 0;
    n0 = n1 = 0;
    for(int i = 1; i <= s.size()-num+1; i++)
    {
        n0 = pre0[i+num-1]-pre0[i-1];
        n1 = pre1[i+num-1]-pre1[i-1];
        //cout << num << " " << i << " " << n0 << ' ' << n1 << endl;
        if(n0 == n1)
            nowans = max(nowans,n0*2);
    }
    if(nowans == num)
        return true;
    return false;
}

int main()
{
    cin >> s;
    for(int i = 0 ; i < s.size(); i++)
    {
        if(s[i] == '0')
            pre0[i+1]++;
        else
            pre1[i+1]++;
        pre0[i+1] += pre0[i];
        pre1[i+1] += pre1[i];
    }
    int l = 0;
    int r = s.size();
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            if(ans % 2 == 1)
                ans--;
            l = mid+1;
        }else
            r = mid-1;
    }
    cout << ans;
    return 0;
}
