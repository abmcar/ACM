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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int n, t, m;
int num[Maxn];
void work()
{
    map<int,bool> M;
    for (int i = -3e4; i <= 3e4; i++)
        M[i] = false;
    M[0] = true;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int j = 1; j <= n; j++)
    for (int i = 3e4;  i >= -3e4; i--)
        if (M[i-num[j]])
            M[i] = true;
    for (int j = 1; j <= n; j++)
    for (int i = -3e4;  i <= 3e4; i++)
        if (M[i+num[j]])
            M[i] = true;
    cin >> m;
    while (m--)
    {
        int temp;
        cin >> temp;
        if (M[temp])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}