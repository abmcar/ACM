#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define Maxn (int)1e6
using namespace std;

int t,n;
int num[Maxn];
int maxn = 0;

bool check(int pos)
{
    int nownum = num[pos];
    for(int i = pos-1 ; i >= 1; i--)
        if(nownum > num[i])
        {
            if(nownum > maxn)
                return true;
            nownum++;
        }
        else
            break;
    for(int i = pos+1; i <= n; i++)
        if(nownum > num[i])
        {
            if(nownum > maxn)
                return true;
            nownum++;
        }
        else
            break;
    if(nownum > maxn)
        return true;
    return false;
}

void work()
{
    cin >> n;
    maxn = 0;
    for(int i = 1; i <= n; i++)
        cin >> num[i],maxn = max(maxn,num[i]);
    for(int i = 1; i <= n; i++)
        if(check(i))
        {
            cout << i << endl;
            return;
        }
    cout << "-1" << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}