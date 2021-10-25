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
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

struct Node
{
    int pos;
    int val;
    bool used;
}nodes[Maxn];
int n;
bool used[Maxn];

bool cmp1(Node a, Node b)
{
    return a.pos*2+a.val > b.pos*2+b.val;
}

bool cmp2(Node a, Node b)
{
    return a.val > b.val;
}

int main()
{
    Buff;
    ll ans;
    ll nowdis;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> nodes[i].pos;
    for(int i = 1; i <= n; i++)
        cin >> nodes[i].val;
    sort(nodes+1,nodes+1+n,cmp1);
    nodes[1].used = true;
    nowdis = nodes[1].pos;
    ans = nodes[1].pos*2 + nodes[1].val;
    cout << ans << endl;
    sort(nodes+1,nodes+1+n,cmp2);
    int temppos = 1;
    for(int i = 2; i <= n; i++)
    {
        while(nodes[temppos].used)
            temppos++;
        if(nodes[temppos].pos > nowdis)
        {
            ans += (nodes[temppos].pos - nowdis) * 2;
            nowdis = nodes[temppos].pos;
        }
        ans += nodes[temppos].val;
        cout << ans << endl;
        temppos++;
    }
    return 0;
}