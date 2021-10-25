#include<iostream>
#include<algorithm>

using namespace std;

int t;
int n,k;
long long num[233333];
long long pre[233333];
long long preans[233333];
long long nowmax = -1e15;
long long finmax = -1e15;

void work()
{
    cin >> n >> k;
    nowmax = -1e15;
    finmax = -1e15;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i-1]+num[i];
    for(int i = k; i <= n; i++)
        preans[i] = pre[i]-pre[i-k];
    // for(int i = 1; i <= n; i++)
    //     cout << premax[i] << " " << aftmax[i] << endl;
    for(int i = k*2; i <= n; i++)
    {
        nowmax = max(nowmax,preans[i-k]);
        finmax = max(finmax,nowmax+preans[i]);
    }
    cout << finmax << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
        work();
    return 0;
}