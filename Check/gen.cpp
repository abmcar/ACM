#include <bits/stdc++.h>

using namespace std;

mt19937 mt_rand(chrono::system_clock::now().time_since_epoch().count());

const int N = 1e5 + 1;

int main()
{
    // freopen("1.txt", "w", stdout);
    int n = 1000, m = 1000;
    cout << n << ' ' << m << '\n';
    for(int i = 1; i <= m; ++i)
    {
        int op = mt_rand() % 2 + 1;
        int x = mt_rand() % 1024 + 1;
        int l = mt_rand() % n + 1;
        int r = mt_rand() % n + 1;
        int val;
        while(r < l)
        {
            r = mt_rand() % n + 1;
        }
        if(op == 1)
        {
            val = mt_rand() % N;
            cout << op << ' ' << x << ' ' << l << ' ' << r << ' ' << val << '\n';
        }
        else
        {
            cout << op << ' ' << x << ' ' << l << ' ' << r << '\n';
        }
    } 
    return 0;
}
