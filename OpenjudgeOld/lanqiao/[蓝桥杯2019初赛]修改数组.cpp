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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, num[Maxn];
bool M[Maxn];
int minn = 1;

int main()
{
    Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 1; i <= n; i++)
    {
        if (minn > num[i])
            num[i] = minn;
        while (M[num[i]] == true)
            num[i]++;
        M[num[i]] = true;
        while (M[minn])
            minn++;
    }
    for (int i = 1; i <= n; i++)
        cout << num[i] << " ";
    return 0;
}