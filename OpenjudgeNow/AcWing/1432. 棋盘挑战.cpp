#include<iostream>
#include<algorithm>
#include<cmath>
#define Maxn (int)14

using namespace std;

int n;
int cnt;
int ans[Maxn];
bool used1[Maxn];
bool used2[Maxn*3];
bool used3[Maxn*3];

void dfs(int h)
{
    if(h == n+1)
    {
        if(cnt < 3)
        {
            for(int i = 1; i <= n; i++)
                cout << ans[i] << " ";
            cout << endl;
        }
        cnt++;
        return;
    }
    for(int i = 1; i <= n; i++)
    if(used1[i] || used2[h-i+n] || used3[i+h])
        continue;
    else
    {
        used1[i] = used2[h-i+n] = used3[i+h] = true;
        ans[h] = i;
        dfs(h+1);
        used1[i] = used2[h-i+n] = used3[i+h] = false;
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << cnt;
    return 0;
}