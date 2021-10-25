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
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;
int numa[Maxn], numb[Maxn];

struct Node
{
    int d, pos;
};

vector<Node> n1, n2;

void work()
{
    n1.clear();
    n2.clear();
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> numa[i];
    for (int i = 1; i <= n; i++)
        cin >> numb[i];
    int tot1, tot2;
    tot1 = tot2 = 0;
    for (int i = 1; i <= n; i++)
    {
        Node nowNode;
        nowNode.pos = i;
        nowNode.d = numb[i] - numa[i];
        if (nowNode.d > 0)
            n1.push_back(nowNode), tot1 += nowNode.d;
        else
            n2.push_back(nowNode), tot2 += nowNode.d;
    }
    // cout << tot1 <<  " " << tot2 << endl;
    if (tot1 + tot2 != 0)
    {
        cout << "-1" << endl;
        return;
    }
    cout << tot1 << endl;
    int now2 = 0;
    for (int i = 0; i < n1.size(); i++)
    {
        while (n1[i].d != 0 && n2[now2].d != 0)
        {
            cout << n2[now2].pos << " " << n1[i].pos << endl;
            // cout << n1[i].pos << " " << n2[i].pos << endl;
            n1[i].d--;
            n2[now2].d++;
        }
        if (n1[i].d != 0)
            i--;
        if (n2[now2].d == 0)
            now2++;
    }
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