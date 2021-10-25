#include <iostream>

using namespace std;

int n, m;
bool used[233333];
struct node
{
    int pre, next;
};
node students[200000];

int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    cin >> n;
    students[1].pre = 0;
    students[1].next = 100001;
    students[0].next = 1;
    students[100001].pre = 1;
    for (int i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p;
        if (p == 0)
        {
            students[students[k].pre].next = i;
            students[i].next = k;
            students[i].pre = students[k].pre;
            students[k].pre = i;
        }
        else
        {
            students[students[k].next].pre = i;
            students[i].pre = k;
            students[i].next = students[k].next;
            students[k].next = i;
        }
    }
    
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if(used[x] == 1)
            continue;
        used[x] = 1;
        students[students[x].pre].next = students[x].next;
        students[students[x].next].pre = students[x].pre;
    }
    for (int i = students[0].next; students[i].next != 100001; i = students[i].next)
        cout << i << " ";
    cout << students[100001].pre;
    cout << endl;
    return 0;
}
//1 1 2 6 24