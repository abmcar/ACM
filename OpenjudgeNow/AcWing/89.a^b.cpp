#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

ll a,b,p;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> a >> b >> p;
    ll nowMultiple = a;
    a = 1;
    if(b == 0)
    {
        cout << a%p;
        return 0;
    }
    while (b != 0)
    {
        if(b % 2 == 1)
        {
            a = ((a%p)*(nowMultiple%p))%p;
            b--;
            continue;
        }
        b = b / 2;
        nowMultiple *= nowMultiple;
        nowMultiple = nowMultiple % p;
    }
    cout << a; 
    return 0;
}