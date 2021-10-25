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
#include <iomanip>
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

double p;
double n;
double nowp;

int main()
{
    Buff;
    while (cin >> n)
    {
        p = 1/n;
        double op = p;
        for (int i = 1; i <= n; i++)
        {
            cout << i << " " << nowp << " " << p << endl;
            nowp += p;
            p = 1 - nowp;
            p *= i * op;
        }
        cout << fixed << setprecision(2) << (-1 + sqrt(4 * n + 1)) / 2 << " " << setprecision(0) << (int)((1+sqrt(4*n+1))/2) << endl;
    }
    return 0;
}