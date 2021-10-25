#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n;
int high[123];
int f1[123],f2[123];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> high[i];
    for(int i = 2; i <= n; i++)
    for(int j = 1; j < i; j++)
    if(high[i] > high[j])
        f1[i] = max(f1[j]+1,f1[i]);
    for(int i = n-1; i >= 1; i--)
    for(int j = n; j > i; j--)
    if(high[i] > high[j])
        f2[i] = max(f2[j]+1,f2[i]);
    int maxn = 0;
    for(int i = 1; i <= n; i++)
        cout << i << " " << f1[i] << " " << f2[i] << endl;
    for(int i = 1; i <= n; i++)
        maxn = max(maxn,f1[i]+f2[i]);
    cout << n - maxn - 1;
    return 0;
}