#include<iostream>
#include<algorithm>

using namespace std;

int l,k;
long long codel[(int)1e5+10];
long long ansmin;
long long ansmax;

bool checkmin(long long num)
{
    int nowcut = 0;
    long long nowcode = 0;
    for(int i = 1; i <= l; i++)
    {
        nowcode += codel[i];
        if(nowcode <= 0)
            nowcode = 0;
        if(nowcode >= num)
        {
            nowcut++;
            nowcode = 0;
        }
    }
    return nowcut >= k;
}

bool checkmax(long long num)
{
    int nowcut = 0;
    long long nowcode = 0;
    for(int i = 1; i <= l; i++)
    {
        nowcode += codel[i];
        if(nowcode <= 0)
            nowcode = 0;
        if(nowcode >= num)
        {
            nowcut++;
            nowcode = 0;
        }
    }
    return nowcut <= k;
}

bool checkfin(long long num)
{
    int nowcut = 0;
    long long nowcode = 0;
    for(int i = 1; i <= l; i++)
    {
        nowcode += codel[i];
        if(nowcode <= 0)
            nowcode = 0;
        if(nowcode >= num)
        {
            nowcut++;
            nowcode = 0;
        }
    }
    return nowcut == k;
}

int main()
{
    cin >> l >> k;
    for(int i = 1; i <= l; i++)
        cin >> codel[i];
    long long tl = 1;
    long long tr = 1e15;
    while(tl <= tr)
    {
        // cout << tl << ' ' << tr << endl;
        long long mid = (tl+tr)/2;
        if(checkmin(mid))
        {
            if(checkfin(mid))
                ansmax = mid;
            tl = mid+1;
        }else
            tr = mid-1;
    }
    tl = 1;
    tr = 1e15;
    while(tl <= tr)
    {
        long long mid = (tl+tr)/2;
        if(checkmax(mid))
        {
            if(checkfin(mid))
                ansmin = mid;
            tr = mid-1;
        }else
            tl = mid+1;
    }
    if(ansmin == 0 && ansmax == 0)
    {
        cout << "-1";
        return 0;
    }
    cout << ansmin << " " << ansmax << endl;
    return 0;
}