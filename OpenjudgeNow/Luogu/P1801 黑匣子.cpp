#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> minq;
priority_queue<int, vector<int>, less<int>> maxq;
queue<int> q;
int n,m;
int nowpos;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    for(int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        while(minq.size() + maxq.size() < temp)
        {
            minq.push(q.front());
            q.pop();
        }
        maxq.push(minq.top());
        minq.pop();
        cout << "size:" << maxq.size() << " " << minq.size() << endl;
        if(minq.size() != 0)
        while (minq.top() < maxq.top())
        {
            int minn = minq.top();
            int maxn = maxq.top();
            minq.pop();
            maxq.pop();
            maxq.push(minn);
            minq.push(maxn);
        }
        cout << maxq.top() << endl;
    }
    return 0;
}
