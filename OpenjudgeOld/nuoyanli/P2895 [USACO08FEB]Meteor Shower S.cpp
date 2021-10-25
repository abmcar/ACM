#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int bd[400][400];
int used[400][400];
int nextx[5] = {0, 0, 1, 0, -1};
int nexty[5] = {0, 1, 0, -1, 0};
int ans = 1e8;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tx, ty, t;
        cin >> tx >> ty >> t;
        if(t == 0)
            t = -1;
        bd[tx][ty] = t;
    }
    queue<int> qx, qy, qt;
    qx.push(0);
    qy.push(0);
    qt.push(0);
    used[0][0] = -1;
    while (!qx.empty())
    {
        int nowx = qx.front();
        int nowy = qy.front();
        int nowt = qt.front();
        qx.pop();
        qy.pop();
        qt.pop();
        // cout << "nowfront:" << nowx << " " << nowy << " " << nowt << endl;
        int issafe = 1;
        for (int i = 0; i <= 4; i++)
        {
            int newx = nowx + nextx[i];
            int newy = nowy + nexty[i];
            if (newx < 0 || newy < 0)
                continue;
            if (bd[newx][newy] != 0)
                issafe = 0;
        }
        if (issafe)
        {
            ans = min(nowt, ans);
            continue;
        }
        for (int i = 1; i <= 4; i++)
        {
            int newx = nowx + nextx[i];
            int newy = nowy + nexty[i];
            int newt = nowt + 1;
            if (newx < 0 || newy < 0 || newx > 310 || newy > 310)
                continue;
            // cout << nowx << " " << nowy << " " << nowt << " ";
            // cout << newx << ' ' << newy << ' ' << newt << endl;
            bool unable = 0;
            for (int j = 0; j <= 4; j++)
                if (newx + nextx[j] <= 310 && newx + nextx[j] >= 0 && newy + nexty[j] >= 0 && newy + nexty[j] <= 310)
                    if (bd[newx + nextx[j]][newy + nexty[j]] <= newt)
                    {
                        if (bd[newx + nextx[j]][newy + nexty[j]] == 0)
                            continue;
                        // cout << newx+nextx[j] << " " << newy+nexty[j] << endl;
                        unable = 1;
                        break;
                    }
            if (unable)
                continue;
            if (used[newx][newy] != 0 && used[newx][newy] <= newt)
                continue;
            // cout << "push:" << newx << ' ' << newy << ' ' << newt << endl;
            qx.push(newx);
            qy.push(newy);
            qt.push(newt);
            used[newx][newy] = newt;
        }
    }
    if (ans == 1e8)
        ans = -1;
    cout << ans;
    return 0;
}