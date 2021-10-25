#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define Maxn (int)1e5+10
using namespace std;

struct Node
{
    int val;
    int pos;
    bool operator<(const Node a) const
    {
        return this->val > a.val;
    }
    // bool operator>(const Node a) const
    // {
    //     return this->val < a.val;
    // }
};
int n,m;
int A[Maxn],B[Maxn],C[Maxn];
int F[Maxn];
priority_queue<Node,vector<Node> > q;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
        F[i] = 1;
        Node node;
        node.val = A[i]*F[i]*F[i]+B[i]*F[i]+C[i];
        node.pos = i;
        q.push(node);
    }
    for(int i = 1; i <= m; i++)
    {
        Node node = q.top();
        q.pop();
        cout << node.val << " ";
        F[node.pos]++;
        int temppos = node.pos;
        node.val = A[temppos]*F[temppos]*F[temppos]+B[temppos]*F[temppos]+C[temppos];
        q.push(node);
    }
    return 0;
}