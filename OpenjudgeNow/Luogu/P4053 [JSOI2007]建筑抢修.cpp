#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>
#define Maxn (int)2e5

using namespace std;

struct Node
{
    int t1, t2;
    bool operator<(const Node a) const
    {
        return this->t2 < a.t2;
    }
    void get()
    {
        cin >> t1 >> t2;
    }
}node[Maxn];
int n, nowt;
priority_queue<int, vector<int>> q;
int ans;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        node[i].get();
    sort(node+1,node+1+n);
    for(int i = 1; i <= n; i++)
    {
        if(nowt + node[i].t1 > node[i].t2)
        {
            if(q.top() > node[i].t1)
            {
                nowt = nowt - q.top();
                q.pop();
                q.push(node[i].t1);
                nowt += node[i].t1;
            }
        }else
        {
            q.push(node[i].t1);
            ans++;
            nowt += node[i].t1;
        }
    }
    cout << q.size() << endl;
    return 0;
}