#include<iostream>
#include<algorithm>
#include<cmath>
#define Maxn 20

using namespace std;

int n;
int s[Maxn],b[Maxn];
int ans = 1e9;

void work(int pos,int nows,int nowb)
{
    ans = min(ans,abs(nows-nowb));
    for(int i = pos+1; i <= n; i++)
        work(i,nows*s[i],nowb+b[i]);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i] >> b[i];
    for(int i = 1; i <= n; i++)
        work(i,s[i],b[i]);
    cout << ans;
    return 0;
}