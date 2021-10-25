#include <iostream>
#include <algorithm>
#include <cmath>
#define Maxn (int)3e5
using namespace std;

long long t,n,k;
long long num[Maxn];

void work()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    long long g = abs(num[1]-num[2]);
    for(int i = 3; i <= n; i++)
        g = __gcd(g,abs(num[i]-num[i-1]));
    for(int i = 1; i <= n; i++)
        if((k-num[i]) % g == 0)
        {
            cout << "YES" << endl;
            return;
        }
    cout << "NO" << endl;
}

int main()
{
    cin >> t;
    while (t--)
        work();
    return 0;
}