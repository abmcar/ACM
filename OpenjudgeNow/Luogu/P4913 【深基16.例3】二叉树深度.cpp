#include<iostream>
#include<algorithm>
#define Maxn (int)1e6+10
using namespace std;

struct node
{
    int data,left,right;
    int dep;
    int father;
}Node[Maxn];
int n;
int maxdep;

void dfs(int pos)
{
    if(pos == 0)
        return;
    if(Node[pos].left != 0)
    Node[Node[pos].left].dep += Node[pos].dep + 1;
    if(Node[pos].right != 0)
    Node[Node[pos].right].dep += Node[pos].dep + 1;
    maxdep = max(maxdep,Node[Node[pos].right].dep);
    maxdep = max(maxdep,Node[Node[pos].left].dep);
    dfs(Node[pos].left);
    dfs(Node[pos].right);
}

int main()
{
    //freopen("a.out","w",stdout);
    cin >> n;
    Node[1].dep = 1;
    for(int i = 1; i <= n; i++)
    {
        int templ,tempr;
        cin >> templ >> tempr;
        Node[i].left = templ;
        Node[i].right = tempr;
    }
    dfs(1);
    cout << maxdep;
    return 0;
}