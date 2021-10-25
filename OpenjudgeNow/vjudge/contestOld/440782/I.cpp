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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int f[Maxn];
int n;
vector<int> v;

void work()
{
    memset(f,0,sizeof(f));
    v.clear();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        ans += t1*t2;
        int base = 1;
        while (t2 >= base)
        {
            t2 = t2 - base;
            v.push_back(t1*base);
            base *= 2;
        }
        v.push_back(t1*t2);
    }
    // cout << "pass" << endl;
    int mid = (ans+1)/2;
    int nowMax = 0;
    for (int i = 0; i < v.size(); i++)
    for (int j = mid; j >= v[i]; j--)
        f[j] = max(f[j], f[j-v[i]] + v[i]), nowMax = max(nowMax, f[j]);
    cout << max(ans-nowMax,nowMax) << " " << min(ans-nowMax,nowMax) << endl;
}

int main()
{
    Buff;
    while (cin >> n)
    {
        if (n < 0)
            break;
        work();
    }
    return 0;
}