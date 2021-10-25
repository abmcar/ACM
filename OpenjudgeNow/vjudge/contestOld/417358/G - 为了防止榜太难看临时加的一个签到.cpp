#include<iostream>
#include<algorithm>
#define Maxn (int)1e5+10

using namespace std;

long long n;
long long ans[Maxn];

int main()
{
    for(int i = 1; i <= Maxn; i++)
        ans[i] = ans[i-1]+i;
    while (cin >> n)
        cout << ans[n] << endl << endl;
    return 0;
}