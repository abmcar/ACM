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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <map>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int n, ans;
ll num[5][Maxn];
map<int, int> f[6], ff[6];
map<int, int> mp;
vector<int> v;

int main()
{
    Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[1][i] >> num[2][i] >> num[3][i] >> num[4][i];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
        int temp = num[1][i] + num[2][j];
        v.push_back(temp);
        // cout << temp << endl;
    }
    sort(v.begin(),v.end());
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
        int temp = num[3][i] + num[4][j];
        vector<int>::iterator it = lower_bound(v.begin(),v.end(),temp * -1);
        while (*it == temp * (-1) && it != v.end())
            ans++, it++;
        // cout << temp << endl;
    }
    cout << ans;
    return 0;
}