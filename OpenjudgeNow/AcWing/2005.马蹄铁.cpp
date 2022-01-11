#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;

int n;
char g[N][N];
bool st[N][N];
int ans;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int l, int r)
{
    st[x][y] = true;

    if (l == r)
    {
        ans = max(ans, l + r);
        st[x][y] = false;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if (a >= 0 && a < n && b >= 0 && b < n && !st[a][b])
        {
            if (g[x][y] == ')' && g[a][b] == '(')
                continue;
            if (g[a][b] == '(')
                dfs(a, b, l + 1, r);
            else
                dfs(a, b, l, r + 1);
        }
    }

    st[x][y] = false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> g[i];

    if (g[0][0] == '(')
        dfs(0, 0, 1, 0);

    cout << ans << endl;
    return 0;
}