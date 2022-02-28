#include <bits/stdc++.h>

using namespace std;

int n, m, q;
string bd[10010];
string oriOpt;
int nowX, nowY;
unordered_map<char, int> dx, dy;

signed main()
{
    dx['W'] = -1;
    dx['S'] = 1;
    dy['A'] = -1;
    dy['D'] = 1;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> bd[i];
        bd[i] = "-" + bd[i];
    }
    cin >> oriOpt;
    nowX = nowY = 1;
    for (char it : oriOpt)
    {
        int nextX = nowX + dx[it];
        int nextY = nowY + dy[it];
        if (nextX > n || nextX < 1 || nextY > m || nextY < 1)
            continue;
        if (bd[nextX][nextY] == '1')
            continue;
        nowX = nextX;
        nowY = nextY;
    }
    cout << nowX << " " << nowY << endl;
    return 0;
}