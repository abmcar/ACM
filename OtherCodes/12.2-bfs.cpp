#include <bits/stdc++.h>

using namespace std;

int t, n, ans;
int dis[200][200];
int ok[200];

void init()
{
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ok[i] = false;
        for (int j = 1; j <= n; j++)
            dis[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ans;
            if (ans == 0)
                break;
            dis[i][ans] = 1;
        }
    }
    ans = 0;
}

void work()
{
    for (int i = 1; i <= n; i++)
        for (int t1 = 1; t1 <= n; t1++)
            for (int t2 = 1; t2 <= n; t2++)
                if (dis[t1][i] && dis[i][t2])
                    dis[t1][t2] = true;
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        if (ok[i])
            continue;
        ans++;
        ok[i] = 1;
        int temp = 1;
        while (1)
        {
            if (dis[i][temp] && dis[temp][i])
                ok[temp] = 1;
            temp++;
            if (temp == n + 1)
                break;
        }
    }
    // cout << "!!!" << ans << endl;
    cout << ans << endl;
}

int main()
{
    cin >> t;
    while (t--)
    {
        init();
        work();
        print();
    }
    return 0;
}