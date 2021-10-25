#include<iostream>
#include<algorithm>
#include<cmath>
#define Maxn (int)1e5+10

using namespace std;

int n;
long long a[Maxn],b[Maxn];
long long numa[Maxn];
long long numb[Maxn];
int f[Maxn];

/*
f[n] = min(
            max(a[n-1],numa[n])+b[n-1]),
            a[n-1]+max(b[n-1],numb[n])
        )
*/

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> numa[i];
    for(int i = 1; i <= n; i++)
        cin >> numb[i];
    for(int i = n; i >= 1; i--)
    for(int j = 1; j <= n; j++)
        f[n] = 
    cout << f[n];
    return 0;
}