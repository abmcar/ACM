#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

const int Maxn = 5e3+10;

ll m,n,k;

inline ll getAns(ll num)
{
    ll temp = 0;
    while (num != 0)
    {
        ll tempnum = num % 10;
        num = num / 10;
        temp += tempnum*tempnum;
    }
    return temp;
}

bool ok = false;

int main()
{
    Buff;
    cin >> m >> n >> k;
    ll str = 1;
    for(int i = 1; i < m; i++)
        str *= 10;
    ll end = str*10-1;
    for(ll i = str; i <= end; i++)
        if((i % n) == getAns(i))
            cout << i%k << endl,ok = true;
    if(!ok)
        cout << "-1";
    return 0;
}