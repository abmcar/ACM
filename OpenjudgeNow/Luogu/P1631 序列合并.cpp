#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

#define Maxn (int)1e5 + 10

using namespace std;

int numa[Maxn], numb[Maxn];
int n;
struct Node
{
    int posa, posb;
    int val;
    bool operator<(const Node a) const
    {
        return this->val > a.val;
    }
    void getval()
    {
        val = numa[posa] + numb[posb];
    }
};
priority_queue<Node, vector<Node>> q;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> numa[i];
    for (int i = 1; i <= n; i++)
        cin >> numb[i];
    for (int i = 1; i <= n; i++)
    {
        Node node1, node2;
        node1.posa = node2.posb = 1;
        node1.posb = node2.posa = i;
        node1.getval();
        node2.getval();
        q.push(node1);
        if (i == 1)
            continue;
        q.push(node2);
    }
    for (int i = 1; i <= n; i++)
    {
        Node node = q.top();
        q.pop();
        cout << node.val << " ";
        node.posa++;
        node.posb++;
        if (node.posa > n || node.posb > n)
            continue;
        node.getval();
        q.push(node);
    }
    return 0;
}