#include<iostream>
#include<algorithm>
#define MAXN 100100
#define mo 10007
using namespace std;

int n,m;
long long number[MAXN];
int color[MAXN];
int s[MAXN][3],sum[MAXN][3];
long long ans;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> number[i];
    for(int i = 1; i <= n; i++)
        cin >> color[i];
    for(int i = 1; i <= n; i++)
    {
        s[color[i]][i%2]++;
        sum[color[i]][i%2] = (sum[color[i]][i%2]%mo + number[i]%mo)%mo;
    }
    for(int i = 1; i <= n; i++)
        ans = (ans + i*((s[color[i]][i%2]-2)*number[i]%mo + sum[color[i]][i%2]))%mo;
            // (ans + i*((s[color[i]][i%2]-2)*number[i]%mo + sum[color[i]][i%2]))%mo;
    cout << ans;
    return 0;
}