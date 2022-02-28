#include <bits/stdc++.h>

using namespace std;

int totX, totY;
int n;
vector<int> nX, nY;
int target, tX, tY;
int lx, rx, dy;
int ansX, ansY;

signed main()
{
    cin >> totX >> totY;
    cin >> n;
    nX.resize(n + 1);
    nY.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nX[i] >> nY[i];
    cin >> target >> tX >> tY;
    for (int i = 1; i < target; i++)
        lx += nX[i];
    for (int i = target; i <= n; i++)
        rx += nX[i];
    for (int i = 1; i <= n; i++)
        dy = max(dy, nY[i]);
    ansX = tX - lx;
    ansY = tY;
    if (ansX <= 0)
        ansX = 0;
    if (tX + rx > totX)
        ansX = ansX - ((tX + rx) - totX);
    if (ansY + dy > totY)
        ansY = ansY - ((ansY + dy) - totY);
    for (int i = 1; i <= n; i++)
    {
        cout << ansX << " " << ansY << endl;
        ansX += nX[i];
    }
    return 0;
}