#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int cnt, n;
bool flag;

void clear()
{
    cnt = 1;
    flag = false;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while (cin >> n)
    {
        if (n == 0)
            break;
        clear();
        stack<int> S;
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            if (flag)
                continue;
            if (temp >= cnt)
            {
                for (int j = cnt; j < temp; j++)
                    S.push(j);
                cnt = temp + 1;
            }
            else
            {
                if (S.top() == temp)
                    S.pop();
                else
                {
                    cout << "No" << endl;
                    flag = 1;
                    // break;
                }
            }
        }
        if (!flag)
            cout << "Yes" << endl;
    }
    return 0;
}