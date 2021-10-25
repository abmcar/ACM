#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int t,n,k;
int num[Maxn];

void work()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    num[n+1] = 0;
    for(int i = 1; i <= k; i++)
    {
        int nowpos = 1;
        for(; nowpos <= n; nowpos++)
        {
            if(num[nowpos+1] > num[nowpos])
            {
                num[nowpos]++;
                break;
            }
        }
        if(nowpos == n+1)
        {
            cout << "-1" << endl;
            return;
        }
        if(i == k)
        {
            cout << nowpos << endl;
            return;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
        work();
    return 0;
}