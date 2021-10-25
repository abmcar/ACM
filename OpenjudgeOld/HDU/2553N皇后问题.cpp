#include<iostream>
#include<algorithm>
#include<cmath>
#define Maxn 33
using namespace std;

bool usedx[Maxn],usedy[Maxn];
bool used1[Maxn],used2[Maxn];
int n;
int ans;
int finans[Maxn];

void dfs(int nowh)
{
    //cout << nowh << endl;
    if(nowh == n)
    {
        ans++;
        return;
    }
    for(int j = 1; j <= n; j++)
    {
        if(usedy[j])
            continue;
        if(used1[nowh-j+10] || used2[j+nowh])
            continue;
        usedy[j] = used1[nowh-j+10] = used2[j+nowh] = 1;
        dfs(nowh+1);
        usedy[j] = used1[nowh-j+10] = used2[j+nowh] = 0;
    }
}

void work()
{
    if(finans[n] != 0)
    {
        cout << finans[n] << endl;
        return;
    }
    ans = 0;
    dfs(0);
    cout << ans << endl;
    finans[n] = ans;
}

int main()
{
    while(cin >> n)
    {
        if(n == 0)
            return 0;
        work();
    }
    return 0;
}