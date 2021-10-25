#include<iostream>
#include<algorithm>

using namespace std;

unsigned long long n,m;
unsigned long long num[1000010];

bool check(unsigned long long h)
{
    unsigned long long toth = 0;
    for(int i = 1; i <= n; i++)
    if(num[i] < h)
        continue;
    else
        toth += num[i]-h;
    if(toth >= m)
        return true;
    else
        return false;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    unsigned long long l = 1;
    unsigned long long r = 1000000000;
    while(l < r)
    {
        // cout << l << " " << r << endl;
        long long mid = (l+r+1)/2;
        if(check(mid))
            l = mid;
        else
            r = mid-1;
    }
    cout << l;
}