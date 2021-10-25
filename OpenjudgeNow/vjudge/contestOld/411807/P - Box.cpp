#include<iostream>
#include<algorithm>

using namespace std;

struct rectangle
{
    int l,r;
    void s1()
    {
        int temp = min(l,r);
        l = max(l,r);
        r = temp;
    }
}rec[10];

bool cmp(rectangle a, rectangle b)
{
    if(a.r == b.r)
        return a.l < b.l;
    return a.r < b.r;
}

bool check1(rectangle a, rectangle b)
{
    if(a.l != b.l || a.r != b.r)
        return false;
    return true;
}

int temp;

int main()
{
    while(cin >> rec[1].l)
    {
    cin >> rec[1].r;
    for(int i = 2; i <= 6; i++)
        cin >> rec[i].l >> rec[i].r;
    for(int i = 1; i <= 6; i++)
        rec[i].s1();
    sort(rec+1,rec+7,cmp);
    // for(int i = 1; i <= 6; i++)
    //     cout << rec[i].r << " " << rec[i].l << endl;
    bool ok = 1;
    for(int i = 1; i <= 6; i += 2)
    if(check1(rec[i],rec[i+1]) == 0)
        ok = 0;
    if(rec[1].r != rec[3].r || rec[3].l != rec[5].l)
        ok = 0;
    if(rec[1].l == rec[1].r && check1(rec[3],rec[5]) == 0)
        ok = 0;
    // if(rec[3].l == rec[3].r && check1(rec[1],rec[5]) == 0)
    //     ok = 0;
    if(rec[6].l == rec[6].r && check1(rec[3],rec[1]) == 0)
        ok = 0;
    if(ok == 0)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << "POSSIBLE" << endl;
    }
    return 0;
}