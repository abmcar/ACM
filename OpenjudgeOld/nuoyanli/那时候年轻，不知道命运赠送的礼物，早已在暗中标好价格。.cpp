#include<iostream>
#include<algorithm>
#define MAXN (int)1e6+10
using namespace std;

int t;
int n,a,b;
long long num[MAXN];
long long maxn[MAXN],minn[MAXN]; 

void work()
{
    int ans = 0;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++)
    {
        maxn[i] = 0;
        minn[i] = 1e10;
    }
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = 2; i <= n; i++)
        maxn[i] = max(maxn[i-1],num[i-1]);
    for(int i = n-1; i >= 1; i--)
        minn[i] = min(minn[i+1],num[i+1]);
    for(int i = 2; i <= n-1; i++)
        if(maxn[i] > a && minn[i] < b)
            ans++;
    cout << ans << endl;
    return;
}

int main()
{
    cin >> t;
    while(t--)
        work();
    return 0;
}