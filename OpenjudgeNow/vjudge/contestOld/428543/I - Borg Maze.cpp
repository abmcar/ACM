#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int t, r, c;
char bd[Maxn][Maxn];
int nx[5] = {0, 1, 0, -1, 0};
int ny[5] = {0, 0, 1, 0, -1};
map<pair<int, int>, int> M;

void get(int *nodeSum, int posX[], int posY[])
{
    int tempN = 0;
    cin >> c >> r;
    string temp;
    for (int i = 1; i <= r; i++)
    {
        cin >> bd[i][1];
        getline(cin, temp);
        for (int j = 1; j <= temp.size(); j++)
            bd[i][j + 1] = temp[j - 1];
        for (int j = temp.size() + 2; j <= c; j++)
            bd[i][j] = ' ';
        for (int j = 1; j <= c; j++)
            if (bd[i][j] == 'S' || bd[i][j] == 'A')
            {
                posX[++tempN] = i, posY[tempN] = j;
                pair<int,int> p(i,j);
                M[p] = tempN;
            }
    }
    *nodeSum = tempN;
}

bool nowUsed[Maxn][Maxn];
void bfs(int strNode, int dis[], bool used[], int nodeX[], int nodeY[])
{
    // cout << "pass #1" << endl;
    queue<int> qX, qY, qT;
    memset(nowUsed, false, sizeof(nowUsed));
    qX.push(nodeX[strNode]);
    qY.push(nodeY[strNode]);
    qT.push(0);
    while (!qX.empty())
    {
        int nowx = qX.front();
        int nowy = qY.front();
        int nowt = qT.front();
        qX.pop();
        qY.pop();
        qT.pop();
        // cout << nowx << " " << nowy << " " << nowt << endl;
        if (bd[nowx][nowy] == 'A' || bd[nowx][nowy] == 'S')
        {
            pair<int,int> p(nowx,nowy);
            int pos = M[p];
            dis[pos] = min(dis[pos], nowt);
        }
        for (int i = 1; i <= 4; i++)
        {
            int nextx = nowx + nx[i];
            int nexty = nowy + ny[i];
            int nextt = nowt + 1;
            if (nextx > r || nexty > c || nextx < 1 || nexty < 1)
                continue;
            if (bd[nextx][nexty] == '#')
                continue;
            if (nowUsed[nextx][nexty])
                continue;
            nowUsed[nextx][nexty] = true;
            qX.push(nextx);
            qY.push(nexty);
            qT.push(nextt);
        }
    }
}

void work()
{
    int ans, n;
    int dis[Maxn];
    bool used[Maxn];
    int nodeX[Maxn], nodeY[Maxn];
    ans = n = 0;
    memset(nodeX, 0, sizeof(nodeX));
    memset(nodeY, 0, sizeof(nodeY));
    M.clear();
    get(&n, nodeX, nodeY);
    for (int i = 1; i <= n; i++)
        dis[i] = Inf, used[i] = false;
    dis[1] = 0;
    used[1] = true;
    bfs(1, dis, used, nodeX, nodeY);
    for (int i = 1; i < n; i++)
    {
        int minDis = Inf;
        int minPos;
        for (int j = 1; j <= n; j++)
        {
            if (used[j])
                continue;
            if (dis[j] < minDis)
            {
                minDis = dis[j];
                minPos = j;
            }
        }
        ans += minDis;
        used[minPos] = true;
        bfs(minPos, dis, used, nodeX, nodeY);
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}