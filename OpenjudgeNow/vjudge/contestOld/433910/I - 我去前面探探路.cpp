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

const int Maxn = 567;
const ll Mod = 1e9 + 7;

int n;
int num1[Maxn], num2[Maxn];
// int num[Maxn];
int ans;

int main()
{
    Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t1,t2;
        char tempChar;
        cin >> tempChar;
        cin >> t1 >> t2;
        if (tempChar == 'M')
        {
            for (int j = t1; j <= t2; j++)
                num1[j]++;
        }else
            for (int j = t1; j <= t2; j++)
                num2[j]++;
    }
    for (int i = 1; i <= 366; i++)
        ans = max(ans, min(num1[i],num2[i]));
    cout << ans*2;
    return 0;
}