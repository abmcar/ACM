#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 2e6 + 7;

long long num[Maxn], tot;
long long n, m;

long long lowbit(long long x)
{
    return x & -x;
}

void update(long long now, long long k)
{
    while(now)
    {
        num[now] += k;
        now = now - lowbit(now);
    }
}

long long query(int x)
{
    long long ans = 0;
    while (x < Maxn)
    {
        ans = ans + num[x];
        x = x + lowbit(x);
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        long long opt;
        long long tempX;
        cin >> opt;
        if (opt)
        {
            cin >> tempX;
            long long ans = tot - query(tempX);
            cout << ans << endl;
        }
        else
        {
            long long l, r, k;
            cin >> l >> r >> k;
            k = k * (r - l + 1);
            tot = tot + k;
            if (l > 1)
                update(l - 1, -k);
            update(r, k);
        }
    }
    return 0;
}