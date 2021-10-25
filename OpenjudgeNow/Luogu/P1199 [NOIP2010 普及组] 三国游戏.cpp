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

const int Maxn = 1e4+10;
const ll Mod = 1e9+7;

ll bd[Maxn][Maxn];
int n;
ll ans;

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++)
    {
        cin >> bd[i][j];
        bd[j][i] = bd[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        sort(bd[i]+1,bd[i]+1+n);
        ans = max(ans, bd[i][n-1]);
    }
    cout << "1" << endl << ans << endl; 
    return 0;
}