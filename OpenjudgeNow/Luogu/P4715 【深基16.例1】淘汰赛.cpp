#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

struct node
{
    int num,pos;
};
queue<node> q;
int n;

node maxnode(node a,node b)
{
    if(a.num > b.num)
        return a;
    return b;
}

node minnode(node a,node b)
{
    if(a.num < b.num)
        return a;
    return b;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= pow(2,n); i++)
    {
        node tempnode;
        cin >> tempnode.num;
        tempnode.pos = i;
        q.push(tempnode);
    }
    for(int i = 1; i < n ; i++)
    {
        queue<node> tq;
        while(!q.empty())
        {
            node tempa = q.front();
            q.pop();
            node tempb = q.front();
            q.pop();
            node tempc = maxnode(tempa,tempb);
            tq.push(tempc);
        }
        while(!tq.empty())
            q.push(tq.front()),tq.pop();
    }
    node tempa = q.front();
    q.pop();
    node tempb = q.front();
    q.pop();
    node tempc = minnode(tempa,tempb);
    cout << tempc.pos;
    return 0;
}