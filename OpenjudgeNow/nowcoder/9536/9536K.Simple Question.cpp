#include<iostream>

using namespace std;

int n,m,k;
int ans = -1;

int main()
{
    cin >> n >> m >> k;
    int temp = n;
    while(n % m != 0)
    {
        n += temp;
    }
    for(int i = n; i <= k; i+=n)
        ans = i;
    cout << ans;
    return 0;
}