#include<iostream>
#include<cmath>

using namespace std;

long long n;
int ans;
bool isprime[(int)1e7+10];
bool used[(int)1e7+10];

int main()
{
    cin >> n;
    for(long long i = 2; i <= 1e6; i++)
    {
        if(used[i])
            continue;
        isprime[i] = 1;
        used[i] = 1;
        for(long long j = i*2; j <= (int)1e6; j+=i)
        {
            isprime[j] = 0;
            used[j] = 1;
        }
    }
    //cout << isprime[2] << endl;
    for(long long i = 2; i*i <= n; i++)
        if(isprime[i])
            ans++;
    cout << ans;
    return 0;
}