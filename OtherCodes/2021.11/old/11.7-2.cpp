#include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define endl "\n"
#define Endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e7 + 7;

int t, n;
struct Node
{
    int value, key;
    int x, y;
} e[Mod];
int h[Mod], ne[Mod], idx;

int find(int x)
{
    // cout << "find " << x << endl;
    int k = (x % Mod + Mod) % Mod;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i].key == x)
        {
            // cout << x << " " << e[i].value << endl;
            ll temp = e[i].value;
            e[i].value = 0;
            return temp;
        }
    return 0;
}

int find(int x, int y)
{
    ll tempNum = (x * 114514 + y) % Mod;
    // cout << "find " << tempNum << endl;
    int k = (tempNum % Mod + Mod) % Mod;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i].key == tempNum && e[i].x == x && e[i].y == y)
        {
            // cout << "result " << tempNum << " " << e[i].value << endl;
            ll temp = e[i].value;
            e[i].value = 0;
            return temp;
        }
    return 0;
}

void insert(int x)
{
    // cout << "insert " << x << endl;
    int k = (x % Mod + Mod) % Mod;
    if (h[k] != -1)
        for (int i = h[k]; i != -1; i = ne[i])
        {
            // cout << i << endl;
            if (e[i].key == x)
            {
                e[i].value++;
                return;
            }
        }
    e[idx].key = x;
    e[idx].value = 1;
    ne[idx] = h[k];
    h[k] = idx++;
}

void insert(int x, int y)
{
    ll tempNum = (x * 114514 + y) % Mod;
    // cout << "insert " << tempNum << endl;
    int k = (tempNum % Mod + Mod) % Mod;
    if (h[k] != -1)
        for (int i = h[k]; i != -1; i = ne[i])
        {
            // cout << i << endl;
            if (e[i].key == tempNum && e[i].x == x && e[i].y == y)
            {
                e[i].value++;
                return;
            }
        }
    e[idx].key = tempNum;
    e[idx].value = 1;
    e[idx].x = x;
    e[idx].y = y;
    ne[idx] = h[k];
    h[k] = idx++;
}

void clear()
{
    memset(h, -1, sizeof h);
    memset(ne, 0, sizeof ne);
    for (int i = 1; i <= n; i++)
        e[i].value = e[i].value = 0;
    // memset(e, 0, sizeof 0);
    idx = 0;
}

ll cal(ll num)
{
    return num * (num - 1) / 2;
}

int posX[Maxn], posY[Maxn];

void work()
{
    ll ans = 0;
    cin >> n;
    clear();
    for (int i = 1; i <= n; i++)
        cin >> posX[i] >> posY[i];
    for (int i = 1; i <= n; i++)
        insert(posX[i]);
    for (int i = 1; i <= n; i++)
        ans += cal(find(posX[i]));
    clear();
    for (int i = 1; i <= n; i++)
        insert(posY[i]);
    for (int i = 1; i <= n; i++)
        ans += cal(find(posY[i]));
    clear();
    for (int i = 1; i <= n; i++)
        insert(posX[i], posY[i]);
    for (int i = 1; i <= n; i++)
        ans = ans - cal(find(posX[i], posY[i]));
    // cout << idx << endl;
    cout << ans << endl;
}

signed main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}