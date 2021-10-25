#include<iostream>

using namespace std;

int n;
long long num[200010];
long long sum = 0;
long long mod = (int)1e9+7;
long long aftans[200010];
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = n; i >= 1; i--)
        aftans[i] = (aftans[i+1] + num[i])%mod;
    for(int i = 1; i < n; i++)
        sum += ((num[i]%mod)*(aftans[i+1]%mod))%mod;
    cout << sum%mod << endl;
    return 0;
}
