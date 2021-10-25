#include<iostream>
#include<algorithm>
#include<cmath>
#define Maxn (int)1e5+10
using namespace std;

int t;
long long n,m;
long long num[Maxn];

void work()
{
    cin >> n >> m;
    long long l1,l2,r1,r2;
    r1 = 1e9;
    r2 = 1e9;
    l1 = m;
    l2 = m;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = 1; i <= n; i++)
    {
        r1 = min(r1,num[i]);
        l1 -= (m-num[i]);
        r2 = min(r2,m-num[i]);
        l2 -= num[i];
    }
    l1 = max((long long)0,l1);
    l2 = max((long long)0,l2);
    cout << l1 << ' ' << r1 << endl << l2 << " " << r2 << endl;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}