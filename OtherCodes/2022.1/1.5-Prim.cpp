#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e7 + 10;
const int N = 2333;

// 点数和边数
int n, m;
// 邻接矩阵
int dis[N][N];
// Prim距离
int nowDis[N];
// 是否选过
bool ok[N];

int main()
{
    // 输入及初始化数组
    cout << "输入点数和边数" << endl;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        nowDis[i] = Maxn, ok[i] = false;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dis[i][j] = Maxn;
    int arg1, arg2, arg3;
    cout << "输入边的端点和距离" << endl;
    while (m--)
    {
        cin >> arg1 >> arg2 >> arg3;
        dis[arg1][arg2] = min(dis[arg1][arg2], arg3);
        dis[arg2][arg1] = min(dis[arg2][arg1], arg3);
    }
    // Prim求最小生成树
    int nowCost = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!ok[j] && (t == -1 || nowDis[t] > nowDis[j]))
                t = j;
        if (i && nowDis[t] == Maxn)
        {
            nowCost = Maxn;
            break;
        }
        if (i != 0)
            nowCost += nowDis[t];
        ok[t] = true;
        for (int j = 1; j <= n; j++)
            nowDis[j] = min(nowDis[j], dis[t][j]);
    }
    // 输出
    cout << "邻接矩阵:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << (dis[i][j] == Maxn ? 0 : dis[i][j]) << " ";
        cout << endl;
    }
    if (nowCost == Maxn)
        cout << "不存在最小生成树" << endl;
    else
        cout << "最小代价:" << nowCost << endl;
    return 0;
}

/* 
6 10
1 2 1
2 3 2
3 4 3
4 5 4
5 6 5
1 6 4
2 4 3
3 5 2
4 6 1
1 5 999

 */