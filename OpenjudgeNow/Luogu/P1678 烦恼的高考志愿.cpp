#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int m,n;
long long line[(int)1e6+10];
long long score[(int)1e6+10];
long long ans;

long long Search(long long num)
{
    int l = 1;
    int r = m;
    long long tempans = 1e9;
    while(l <= r)
    {
        // cout << l << " " << r << endl;
        int mid = (l+r)/2;
        if(line[mid] >= num)
            r = mid,tempans = min(line[mid]-num,tempans);
        else
            l = mid+1,tempans = min(num-line[mid],tempans);
        if(l == mid && r == mid)
            break;
    }
    return tempans;
}


void work(long long num)
{
    ans += Search(num);
}

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> line[i];
    sort(line+1,line+1+m);
    for(int i = 1; i <= n; i++)
        cin >> score[i];
    for(int i = 1; i <= n; i++)
        work(score[i]);
    cout << ans;
}