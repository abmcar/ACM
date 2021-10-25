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

int t, n, k;

void work()
{
    cin >> n >> k;
    if (n % 2 == 1 && k % 2 == 0)
    {
        cout << "NO" << endl;
        return;
    }
    if ((n-k+1) % 2 == 1)
    {
        if (n-k+1 <= 0)
        {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        for (int i = 1; i < k; i++)
            cout << "1 ";
        cout << n-k+1 << endl;
        return;
    }
    if (n-k*2+2 <= 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 1; i < k; i++)
        cout << "2 ";
    cout << n-k*2+2 <<endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}