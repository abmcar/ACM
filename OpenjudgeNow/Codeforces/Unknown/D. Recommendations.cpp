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

int n;
ll now, ans, nowTot;
multiset<int> S;

struct Node
{
    int pos, val;
    bool const operator<(Node b) const
    {
        if (pos == b.pos)
            return val > b.val;
        return pos < b.pos;
    }
} node[Maxn];

int main()
{
    // Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> node[i].pos;
    for (int i = 1; i <= n; i++)
        cin >> node[i].val;
    sort(node + 1, node + 1 + n);
    now = node[1].pos;
    S.insert(node[1].val);
    nowTot += node[1].val;
    for (int i = 2; i <= n; i++)
    {
        // cout << "str" << endl;
        if (now != node[i].pos)
        {
            while (now != node[i].pos)
            {
                if (S.size() == 0)
                {
                    now = node[i].pos;
                    break;
                }
                int temp = *S.rbegin();
                nowTot = nowTot - temp;
                ans += nowTot;
                S.erase(S.find(temp));
                now++;
            }
            // cout << now << endl;
            // cout << temp << endl;
            // cout << temp << endl;
            S.insert(node[i].val);
            nowTot += node[i].val;
            continue;
        }
        S.insert(node[i].val);
        nowTot += node[i].val;
        // cout << i << endl;
    }
    while (S.size() != 1)
    {
        int temp = *S.rbegin();
        nowTot = nowTot - *S.rbegin();
        ans += nowTot;
        S.erase(S.find(temp));
    }
    cout << ans << endl;
    return 0;
}