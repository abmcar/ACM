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
// #define endl "\n"
// #define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int t;
int n, m;
string afS[Maxn], orS[Maxn];

void work()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> orS[i];
    for (int i = 1; i < n; i++)
        cin >> afS[i];
    for (int i = 0; i < m; i++)
    {
        map<char,int> M;
        for (int j = 1; j <= n; j++)
            M[orS[j][i]]++;
        for (int j = 1; j < n; j++)
            M[afS[j][i]]--;
        for (char j = 'a'; j <= 'z'; j++)
            if (M[j] != 0)
                cout << j;
    }
    cout << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}