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

int n;
int l[Maxn];
priority_queue<int,vector<int>,greater<int> > q;
ll ans;

int main()
{
    Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    while(q.size() != 1)
    {
        int t1 = q.top();
        q.pop();
        int t2 = q.top();
        q.pop();
        ans += t1 + t2;
        q.push(t1+t2);
    }
    cout << ans;
    return 0;
}