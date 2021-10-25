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
#include <list>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, q;
int fir = 1;

struct Node
{
    int pre, aft;
    // int pos;
    // int next;
}node[Maxn];

vector<int> V;
map<int,int> M;
int now = 0;

list<int> L;

int main()
{
    Buff;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        node[i].pre = i-1;
        node[i].aft = i+1;
    }
    // node[1].pre = -1;
    // node[1].aft = 2;
    // node[n].pre = n-1;
    // node[n].aft = -1;
    while (q--)
    {
        int t1, t2;
        cin >> t1 >> t2;
        if (fir == t1)
            continue;
        int nowtail = t1;
        int nowhead = node[t1].pre;
        for (int i = 1; i <= t2; i++)
        {
            if (node[nowtail].aft == n+1)
                break;
            nowtail = node[nowtail].aft;
        }
        node[nowhead].aft = node[nowtail].aft;
        if (node[nowtail].aft != n+1)
            node[node[nowtail].aft].pre = nowhead;
        node[nowtail].aft = fir;
        node[fir].pre = nowtail;
        fir = t1;
    }
    // if (n == 1)
    // {
    //     cout << 1 << endl;
    //     return 0;
    // }
    for (int i = 1; i <= n; i++)
    {
        cout << fir << " ";
        fir = node[fir].aft;
    }
    // cout << endl;
    return 0;
}
/*
1 2 3 4 5
1 2 3 4 5

2 3 4 5 1
2 3 4 5 1

2 3 4 5 1
1 2 3 4 5

3 4 2 5 1
2 3 1 4 5

2 3 4 5 1
2 3 4 5 1
*/
