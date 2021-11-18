#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int Maxn = 1e6 + 10;
const ll Mod = 7777777;

int n;
int num[5][Maxn];
struct Node
{
    int value, key;
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
            return e[i].value;
        }
    return 0;
}

void insert(int x)
{
    // cout << "insert " << x << endl;
    int k = (x % Mod + Mod) % Mod;
    if (h[k] != -1)
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i].key == x)
        {
            e[i].value++;
            return;
        }
    e[idx].key = x;
    e[idx].value = 1;
    ne[idx] = h[k];
    h[k] = idx++;
}


ll ans = 0;

signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= n; j++)
            cin >> num[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            insert(num[4][i] - num[1][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans += find(num[2][i] * num[3][j]);
    cout << ans << endl;
}
/*
3
-4 5 3
2 2 1
8 4 2
4 7 3
bc = d-a
*/