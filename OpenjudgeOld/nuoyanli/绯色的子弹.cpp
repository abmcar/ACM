#include<iostream>
#include<cmath>

using namespace std;

int n,k;
int ans;
bool used[2333];
int usedjc[23];

int jc(int tempnum)
{
    int now = 1;
    if(usedjc[tempnum] != 0)
        return usedjc[tempnum];
    for(int i = 1; i <= tempnum; i++)
        now *= i;
    usedjc[tempnum] = now;
    return now;
}

void dfs(int lastnum,int nowsum,int deepth)
{
    if(nowsum > n)
        return;
    if(deepth == k)
    {
        if(nowsum == n)
            ans += jc(k);
        return;
    }
    for(int i = lastnum+1; i <= n; i++)
        if(used[i] == 0)
        {
            if(nowsum + i > n)
                break;
            used[i] = 1;
            dfs(i,nowsum+i,deepth+1);
            used[i] = 0;
        }
    return;
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        used[i] = 1;
        dfs(i,i,1);
        used[i] = 0;
    }
    cout << ans;
    return 0;
}