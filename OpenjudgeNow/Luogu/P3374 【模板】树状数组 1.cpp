#include <iostream>
#include <algorithm>
#define Maxn (int)1e6 + 10
using namespace std;

int n, m;
int ans[Maxn];

int lowbit(int k)
{
    return k & -k;
}

int add(int x, int k)
{
    while (x <= n)
    {
        ans[x] += k;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int nowans = 0;
    while (x != 0)
    {
        nowans += ans[x];
        x -= lowbit(x);
    }
    return nowans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        add(i, temp);
    }
    for (int i = 1; i <= m; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos, k;
            cin >> pos >> k;
            add(pos, k);
        }
        if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l - 1) << endl;
        }
    }
    return 0;
}