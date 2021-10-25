#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int finans;
int ans;
int tot[5];
int num[233333];
int f[233333];
void work(int pos)
{
    ans = 0;
    for(int i = 1; i <= tot[pos]; i++)
        cin >> num[i],ans += num[i];
    for(int i = 1; i <= ans; i++)
        f[i] = 0;
    for(int i = 1; i <= tot[pos]; i++)
    for(int j = ans/2; j >= num[i]; j--)
        f[j] = max(f[j],f[j-num[i]]+num[i]);
    finans += max(ans-f[ans/2],f[ans/2]);
}
//4 3  1 0 2 1
int main()
{
    for(int i = 1; i <= 4; i++)
        cin >> tot[i];
    for(int i = 1; i <= 4; i++)
        work(i);
    cout << finans;
}