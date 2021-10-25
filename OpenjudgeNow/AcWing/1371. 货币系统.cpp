#include<iostream>

using namespace std;

int v,n;
long long f[12345];
long long num[123];

int main()
{
    f[0] = 1;
    cin >> v >> n;
    for(int i = 1; i <= v; i++)
        cin >> num[i];
    for(int i = 1; i <= v; i++)
    for(int j = num[i]; j <= n; j++)
        f[j] = f[j-num[i]] + f[j];
    cout << f[n] << endl;
    return 0;
}
