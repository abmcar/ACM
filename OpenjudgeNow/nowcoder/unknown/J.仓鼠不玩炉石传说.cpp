#include<iostream>
#include<algorithm>

using namespace std;

int n,a,k;
bool used[233333];
int num[233333];
int maxn;

int work(int pos)
{
    used[pos] = 1;
    int ans = 0;
    if(num[pos] - a == 0)
    {
        used[pos] = 0;
        return 1;
    }
    if(num[pos] - a > 0)
    {
        used[pos] = 0;
        return 0;
    }
    ans++;
    for(int i = 1; i <= n; i++)
    {
        cout << num[i] << " " << k <<" "<< num[i]-k  << " " << ans << endl;
        if(used[pos] == 1)
            continue;
        if(num[i]-k <= 0)
            ans++;
        if(num[i]-k >= 0) 
            break;
    }
    used[pos] = 0;
    cout << ans << endl;
    return ans;
}

int main()
{
    cin >> n >> a >> k;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = 1; i <= n; i++)
        maxn = max(maxn,work(i));
    cout << maxn;
    return 0;
}