#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m, targetPos, cntS;
int g[N][N];
int costTime[N][N], costDis[N][N], costMoney[N][N];
int dist[N];
bool st[N];
string sites[N];


// �ַ���ת����,����ÿһ���ַ�����ȡΨһ����id
int getId(string nowS)
{
    for (int i = 1; i <= cntS; i++)
        if (sites[i] == nowS)
            return i;
    sites[++cntS] = nowS;
    return cntS;
}


// dijkstra�����·,�����������
int dijkstra(int dis[N][N])
{
    // pre[i] Ϊ���·����i����һ���ڵ�
    int pre[N];
    // pres������ʱ�������·��
    int pres[N];
    // cnt��ʾ���·�����ж��ٸ���
    int cnt = 0;
    // ��ʼ������
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    memset(pre, 0, sizeof pre);
    memset(pres, 0, sizeof pres);
    dist[1] = 0;
    // dijkstra�����·
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
    // ����ﲻ��targetPos ����-1
    if (dist[targetPos] == 0x3f3f3f3f)
        return -1;
    // whileѭ����·��
    int nowNode = targetPos;
    while (nowNode != 0)
    {
        pres[cnt++] = nowNode;
        nowNode = pre[nowNode];
    }
    // ���·��
    for (int i = cnt - 1; i >= 0; i--)
        printf("%s ", sites[pres[i]].c_str());
    printf("\n");
    // ������С����
    return dist[targetPos];
}

int main()
{
    printf("����ص����͵�·��\n");
    scanf("%d %d", &n, &m);
    printf("����Ŀ��ص�\n");
    char tempTarget[N];
    scanf("%s", tempTarget);
    // ��ʼ������Ϊ���ֵ
    memset(costDis, 0x3f, sizeof costDis);
    memset(costMoney, 0x3f, sizeof costMoney);
    memset(costTime, 0x3f, sizeof costTime);
    printf("����%d����·���ӵ�λ���Լ�����̣����ѣ�����ʱ��\n", m);
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
        // ֻȡ��̵ľ���
        costDis[a][b] = costDis[b][a] = min(costDis[a][b], c1);
        costMoney[a][b] = costMoney[b][a] = min(costMoney[a][b], c2);
        costTime[a][b] = costTime[b][a] = min(costTime[a][b], c3);
    }
    targetPos = getId(tempTarget);

    printf("������·��:\n");
    int nowNode = dijkstra(costDis);
    if (nowNode == -1)
        printf("δ�ҵ�����·��\n");
    else
        printf("�����̣�%d\n", nowNode);


    printf("��̻���·��:\n");
    nowNode = dijkstra(costMoney);
    if (nowNode == -1)
        printf("δ�ҵ�����·��\n");
    else
        printf("�����̣�%d\n", nowNode);


    printf("���ʱ��·��:\n");
    nowNode = dijkstra(costTime);
    if (nowNode == -1)
        printf("δ�ҵ�����·��\n");
    else
        printf("���ʱ�䣺%d\n", nowNode);

        
    return 0;
}
/* 

3 3
CC
AA BB 2 2 2
BB CC 1 1 1
AA CC 4 4 4


 */