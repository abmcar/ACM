#include<iostream>
#include<algorithm>
#include<cmath>
#define Maxn (int)1e6

using namespace std;

int nx[4] = {0,1,0,-1};
int ny[4] = {1,0,-1,0};
int n,m;
int num[Maxn];
int minn = 1e8;
int maxn = 0;

struct Node
{
    int val;
    bool operator<(const Node b)const
    {
        return val > b.val;
    }
    // bool operator>(const Node b)const
    // {
    //     return val <>> b.val;
    // }
    void get()
    {
        cin >> val;
    }
}node[Maxn];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        node[i].get(),minn = min(minn,node[i].val),maxn = max(maxn,node[i].val);
    sort(node,node+n);
    for(int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        if(temp < minn)
        {
            cout << "-1" << endl;
            continue;
        }
        if(temp >= maxn)
        {
            cout << maxn << endl;
            continue;
        }
        // if(num[(*upper_bound(num,num+n,temp))] == temp)
        // {
        //     cout << temp << endl;
        //     continue;
        // }
        // cout << num[upper_bound(num,num+n,temp)-num] << "test" << endl;
        Node tn;
        tn.val = temp;
        cout << node[lower_bound(node,node+n,tn)-node].val << endl;
    }
    return 0;
}