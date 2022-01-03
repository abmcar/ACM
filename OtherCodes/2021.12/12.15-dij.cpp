#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m, targetPos, cntS;
int g[N][N];
int costTime[N][N], costDis[N][N], costMoney[N][N];
int dist[N];
bool st[N];
string sites[N];


// 字符串转数字,对于每一个字符串获取唯一数字id
int getId(string nowS)
{
    for (int i = 1; i <= cntS; i++)
        if (sites[i] == nowS)
            return i;
    sites[++cntS] = nowS;
    return cntS;
}


// dijkstra求最短路,传入距离数组
int dijkstra(int dis[N][N])
{
    // pre[i] 为最短路径上i的上一个节点
    int pre[N];
    // pres用于临时储存最短路径
    int pres[N];
    // cnt表示最短路径上有多少个点
    int cnt = 0;
    // 初始化数组
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    memset(pre, 0, sizeof pre);
    memset(pres, 0, sizeof pres);
    dist[1] = 0;
    // dijkstra求最短路
    for (int i = 0; i < n - 1; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        for (int j = 1; j <= n; j++)
            if (dist[j] > dist[t] + dis[t][j])
            {
                dist[j] = dist[t] + dis[t][j];
                pre[j] = t;
            }

        st[t] = true;
    }
    // 如果达不到targetPos 返回-1
    if (dist[targetPos] == 0x3f3f3f3f)
        return -1;
    // while循环求路径
    int nowNode = targetPos;
    while (nowNode != 0)
    {
        pres[cnt++] = nowNode;
        nowNode = pre[nowNode];
    }
    // 输出路径
    for (int i = cnt - 1; i >= 0; i--)
        printf("%s ", sites[pres[i]].c_str());
    printf("\n");
    // 返回最小花费
    return dist[targetPos];
}

int main()
{
    printf("输入地点数和道路数\n");
    scanf("%d %d", &n, &m);
    printf("输入目标地点\n");
    char tempTarget[N];
    scanf("%s", tempTarget);
    // 初始化距离为最大值
    memset(costDis, 0x3f, sizeof costDis);
    memset(costMoney, 0x3f, sizeof costMoney);
    memset(costTime, 0x3f, sizeof costTime);
    printf("输入%d条道路连接的位置以及其里程，花费，所需时间\n", m);
    while (m--)
    {
        int a, b, c1, c2, c3;
        char s1[N];
        char s2[N];
        scanf("%s %s", s1, s2);
        scanf("%d %d %d", &c1, &c2, &c3);
        a = getId(s1);
        b = getId(s2);
        // printf("%s %s %d %d\n", s1, s2, a, b);
        // 只取最短的距离
        costDis[a][b] = costDis[b][a] = min(costDis[a][b], c1);
        costMoney[a][b] = costMoney[b][a] = min(costMoney[a][b], c2);
        costTime[a][b] = costTime[b][a] = min(costTime[a][b], c3);
    }
    targetPos = getId(tempTarget);

    printf("最短里程路径:\n");
    int nowNode = dijkstra(costDis);
    if (nowNode == -1)
        printf("未找到可用路径\n");
    else
        printf("最短里程：%d\n", nowNode);


    printf("最短花费路径:\n");
    nowNode = dijkstra(costMoney);
    if (nowNode == -1)
        printf("未找到可用路径\n");
    else
        printf("最短里程：%d\n", nowNode);


    printf("最短时间路径:\n");
    nowNode = dijkstra(costTime);
    if (nowNode == -1)
        printf("未找到可用路径\n");
    else
        printf("最短时间：%d\n", nowNode);

        
    return 0;
}
/* 

3 3
CC
AA BB 2 2 2
BB CC 1 1 1
AA CC 4 4 4


 */