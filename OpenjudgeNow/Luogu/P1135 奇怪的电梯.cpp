#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int n,a,b;
int num[233];
int mint[233];
int ans = 1e9;

void work(int nowpos,int nowt)
{
    if(nowpos == b)
    {
        ans = min(ans,nowt);
        return;
    }
    if(mint[nowpos] != 0 && mint[nowpos] < nowt)
        return;
    else
        mint[nowpos] = nowt;
    // cout << nowpos << " " << nowt << endl;
    if(nowpos+num[nowpos] <= n)
        work(nowpos+num[nowpos],nowt+1);
    if(nowpos-num[nowpos] >= 1)
        work(nowpos-num[nowpos],nowt+1);
}

int main()
{
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    work(a,0);
    if(ans == 1e9)
        ans = -1;
    cout << ans;
    return 0;
}