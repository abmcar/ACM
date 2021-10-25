#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;

struct qj
{
    int a,b;
};
qj q[23333];

bool cmp(qj ta,qj tb)
{
    if(ta.a == tb.a)
        return ta.b < tb.b;
    return ta.a < tb.a;
}

void work()
{
    int nowright = -2333;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        cin >> q[i].a >> q[i].b;
    sort(q+1,q+1+n,cmp);
    for(int i = 1; i <= n; i++)
    {
        if(q[i].a > nowright)
        {
            //cout << q[i].a << " " << nowright << endl;
            ans++;
            nowright = q[i].b;
        }
    }
    cout << ans << endl;
}

int main()
{
    while(cin >> n)
        work();
    return 0;
}