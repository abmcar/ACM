#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
    LL a1 = 1, a2 = 2, a3 = 5, MOD = 100000;
    for (int i = 4; i <= 1000; i++)
    {
        LL tmp = a1 * a2 * a3 + a1 + a2 + a3;
        tmp %= MOD;
        a1 = a2;
        a2 = a3;
        a3 = tmp;
    }
    cout << a3 << endl;
    return 0;
}
