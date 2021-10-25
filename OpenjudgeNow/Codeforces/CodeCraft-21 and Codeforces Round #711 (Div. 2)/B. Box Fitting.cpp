#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int t, n;
int W;
int ans;
vector<int> V;
priority_queue<int> Q;
map<int,int> M;
void work()
{
    cin >> n >> W;
    V.clear();
    M.clear();
    ans = 0;
    int now = W;
    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        M[temp]++;
        maxn = max(maxn,temp);
    }
    for(int k = 0; k <= n;)
    {
        for(int i = maxn; i != 0; i = i / 2)
        {
            if(k == n)
                break;
            if(now == 0)
            {
                // now = W;
                // ans++;
                break;
            }
            if(M[i] == 0)
                continue;
            if(now < i)
                continue;
            int tempnum = min(M[i],now / i);
            M[i] = M[i] - tempnum;
            now = now - i*tempnum;
            // cout << i << " " << tempnum << " " << k << endl;
            k+= tempnum;
        }
        ans++;
        now = W;
        if(k == n) 
            break;
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}