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
#include <unordered_map>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 2e5 + 10;
const ll Mod = 1e9 + 7;

int t, n;
int a[Maxn], b[Maxn];
int M[Maxn];
// unordered_map<int,int> M;
void work()
{
    // memset(b, 0, sizeof(b));
    // memset(M, 0, sizeof(M));
    // M.clear();
    int ans = 0;
    cin >> n;
    // M.clear();
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = M[i] = 0;
    for (int i = n; i >= 1; i--)
    {
        if (M[a[i]] == 0)
        {
            M[a[i]] = i;
            b[i] = a[i];
            ans++;
        }
    }
    queue<int> Q;
    for (int i = 1; i <= n; i++)
        if (M[i] == 0)
            Q.push(i);
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 0)
        {
            if (Q.front() == i)
            {
                Q.push(Q.front());
                Q.pop();
            }
            b[i] = Q.front();
            Q.pop();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == i)
            swap(b[i], b[M[a[i]]]);
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
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