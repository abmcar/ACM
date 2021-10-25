#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[2333];
int b[2333];
int nowtime;

struct qd
{
    int endtime;
    int usetime;
    int strtime;
    void getstr()
    {
        strtime = endtime - usetime;
        return;
    }
    void input(int num)
    {
        endtime = a[num];
        usetime = b[num];
        getstr();
    }
};
qd q[2333];

bool cmp(qd ta,qd tb)
{
    return ta.strtime < tb.strtime;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
        q[i].input(i);
    sort(q+1,q+1+n,cmp);
    for(int i = 1; i <= n; i++)
    {
        if(nowtime > q[i].strtime)
        {
            cout << "Unforgivable Curses";
            return 0;
        }
        nowtime += q[i].usetime;
    }
    cout << "Tarantollegra";
    return 0;
}