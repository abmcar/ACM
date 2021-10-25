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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;
int num1[Maxn], num2[Maxn];

void work()
{
    cin >> n;
    bool fin = false;
    int d;
    bool ok = true;
    for (int i = 1; i <= n; i++)
        cin >> num1[i];
    for (int i = 1; i <= n; i++)
        cin >> num2[i];
    for (int i = 1; i <= n; i++)
        if (num1[i] != num2[i])
        {
            d = num1[i] - num2[i];
            if (fin || d > 0)
            {
                ok = false;
                break;
            }
            while (num1[i] != num2[i] && i <= n)
            {
                if (num1[i] - num2[i] != d)
                {
                    ok = false;
                    break;
                }
                i++;
            }
            fin = true;
        }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}