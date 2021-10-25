#include<iostream>
#include<algorithm>
#include<vector>
#define Maxn (int)1e6+10

using namespace std;

long long n,c,f;
struct cow
{
    long long money,grade;
}cows[Maxn];
cow cows_[Maxn];

bool cmp(cow a,cow b)
{
    return a.money < b.money;
}

bool cmp_(cow a,cow b)
{
    return a.grade < b.grade;
}

bool check(int num)
{
    if(num-1 < n/2)
        return true;
    if(c-num < n/2)
        return false;
    int leftnum,rightnum;
    leftnum = rightnum = 0;
    long long nowmoney = cows[num].money;
    int nowgrade = cows[num].grade;
    for(int i = 1; i <= n; i++)
    {
        if(cows_[i].grade > nowgrade)
        {
            if(rightnum == n/2)
                continue;
            rightnum++;
            nowmoney += cows_[i].money;
        }else
        {
            if(leftnum == n/2)
                continue;
            leftnum++;
            nowmoney += cows_[i].money;
        }
    }
    return nowmoney <= f;
}


int main()
{
    std::ios::sync_with_stdio(false);
    long long minn = 1e10;
    cin >> n >> c >> f;
    for(int i = 1; i <= c; i++)
    {
        cin >> cows[i].grade >> cows[i].money;
        cows_[i] = cows[i];
        minn = min(minn,cows[i].money);
    }
    if(minn > f)
    {
        cout << "-1";
        return 0;
    }
    sort(cows+1,cows+1+c,cmp_);
    sort(cows_+1,cows_+1+c,cmp);
    // cout << endl;
    // for(int i = 1; i <= c; i++)
    // {
    //     cout << cows[i].grade << " " << cows[i].money;
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i = 1; i <= c; i++)
    // {
    //     cout << cows_[i].grade << " " << cows_[i].money;
    //     cout << endl;
    // }
    // cout << endl;
    int l = 1;
    int r = c;
    int ans = 0;
    while (l <= r)
    {
        // cout << l << " " << r << " " << cows[(l+r)/2].grade << endl;
        int mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            l = mid+1;
        }else
            r = mid-1;
    }
    if(cows[ans].grade == 0)
    {
        cout << "-1";
        return 0;
    }
    cout << cows[ans].grade;
    return 0;
}