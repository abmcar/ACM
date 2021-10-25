#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e6+10;
const ll Mod = 1e9+7;
int t,n;
struct Node
{
    ll score;
    int pos;
    bool const operator< (Node b) const
    {
        return score > b.score;
    }

};

Node a[Maxn];
ll preans[Maxn];

priority_queue<Node,vector<Node> > q;

bool cmp(Node a,Node b)
{
    return a.pos < b.pos;
}
 

void work()
{
    scanf("%d",&n);
    // memset(preans,0,sizeof(preans));
    // memset(a,0,sizeof(a));
    ll maxn = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i].score, a[i].pos = i, q.push(a[i]), maxn = max(maxn,a[i].score);
    ll ans = 0;
    vector<Node> finans;
    while(!q.empty())
    {
        Node nownode = q.top();
        ans += nownode.score;
        q.pop();
        if(ans >= maxn)
        {
            finans.push_back(nownode);
            if(q.empty())
                break;
            continue;
        }
        // cout << ans << endl;
        Node nextnode = q.top();
        if(ans >= nextnode.score)
            finans.push_back(nownode);
        else
            finans.clear();
    }
    sort(finans.begin(),finans.end(),cmp);
    printf("%d\n",finans.size());
    for(int i = 0; i < finans.size(); i++)
        printf("%d ",finans[i].pos);
    printf("\n");
}

int main()
{
    // Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}