#include<iostream>
#include<algorithm>
#define mod 10000

using namespace std;

int n;
int num[1000010];

int main()
{
    cin >> n;
    num[1] = 1;
    num[2] = 2;
    num[3] = 5;
    for(int i = 4; i <= n; i++)
        num[i] = (num[i-1]*2+num[i-3])%mod;
    cout << num[n];
    return 0;
}

