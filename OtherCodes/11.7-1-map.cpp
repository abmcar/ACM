#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int Maxn = 1e6 + 10;
const ll base = 114514;
const ll Mod = 23333333;

int n;
int num[5][Maxn];

ll ans = 0;

signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unordered_map<int, int> M;
    cin >> n;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= n; j++)
            cin >> num[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            M[num[4][i] - num[1][j]]++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans += M[num[2][i] * num[3][j]];
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