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
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

ll t,a,b;

void work()
{
    cin >> a >> b;
    ll ans = 1e9;
    queue<int> qa,qb,qo;
    qa.push(a);
    qb.push(b);
    qo.push(0);
    while(!qa.empty())
    {
        ll nowa = qa.front();
        ll nowb = qb.front();
        ll nowo = qo.front();
        qa.pop();
        qb.pop();
        qo.pop();
        if(nowo > ans)
            continue;
        if(nowa == 0)
        {
            cout << nowo << endl;
            return;
        }
        qa.push(nowa);
        qb.push(nowb+1);
        qo.push(nowo+1);
        ll nowans = 0;
        if(nowb != 1)
        {
            while(nowa != 0)
            {
                nowa = nowa/nowb;
                nowans++;
            }
            ans = min(nowans+nowo,ans);
        }
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}