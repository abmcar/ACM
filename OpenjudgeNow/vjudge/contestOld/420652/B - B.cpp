#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int t,n,k;

void work()
{
    cin >> n >> k;
    priority_queue<int,vector<int>,greater<int> > qminn;
    priority_queue<int,vector<int>,less<int> > qmaxn;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        qminn.push(temp);
        ans += temp;
    }
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        qmaxn.push(temp);
    }
    for(int i = 1; i <= k; i++)
    {
        if(qminn.top() > qmaxn.top())
            break;
        int minn = qminn.top();
        int maxn = qmaxn.top();
        // cout << minn << " " << maxn << endl;
        qminn.pop();
        qmaxn.pop();
        qminn.push(maxn);
        qmaxn.push(minn);
        ans += maxn-minn;
    }
    cout << ans << endl;
}

int main()
{
    cin >> t;
    while(t--)
        work();
    return 0;
}