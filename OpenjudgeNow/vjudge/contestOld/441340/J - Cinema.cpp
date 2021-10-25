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

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int a[Maxn], b[Maxn], c[Maxn];
map<int, int> M;

struct Movie
{
    int pleased, satisfied, pos;
    bool const operator<(Movie a) const
    {
        if (pleased != a.pleased)
            return pleased > a.pleased;
        return satisfied > a.satisfied;
    }
} movie[Maxn];

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], M[a[i]]++;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= m; i++)
        cin >> c[i];
}

void work()
{
    for (int i = 1; i <= m; i++)
    {
        movie[i].pleased = M[b[i]];
        movie[i].satisfied = M[c[i]];
        movie[i].pos = i;;
    }
    sort(movie + 1, movie + 1 + m);
    cout << movie[1].pos << endl;
}

int main()
{
    Buff;
    init();
    work();
    return 0;
}