#include <bits/stdc++.h>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m, cnt;
int g[N][N];
int dist[N];
int pre[N];
bool st[N];
string sites[N];
int strPos, targetPos;

struct site
{
    string name;
    string address;
    string otherMessage;
} sit[N];

int getId(string nowS)
{
    for (int i = 1; i <= cnt; i++)
        if (sites[i] == nowS)
            return i;
    sites[++cnt] = nowS;
    return cnt;
}

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    memset(pre, 0, sizeof pre);
    memset(st, 0, sizeof st);
    dist[strPos] = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF)
            return INF;

        if (i)
            res += dist[t];
        st[t] = true;
        // cout << " nowt " << t << endl;
        for (int j = 1; j <= n; j++)
        {
            if (dist[j] > g[t][j])
            {
                dist[j] = g[t][j];
                pre[j] = t;
            }
        }
    }
    stack<int> temp;
    int nowPos = targetPos;
    while (nowPos != 0)
    {
        temp.push(nowPos);
        nowPos = pre[nowPos];
    }
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    return res;
}

int main()
{
    printf("�����볡�����͵�·��:\n");
    scanf("%d %d", &n, &m);

    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++)
    {
        printf("�������%d���������,��ַ,���:\n", i);
        char s1[N];
        char s2[N];
        char s3[N];
        scanf("%s %s %s", s1, s2, s3);
        getId(s1);
        sit[getId(s1)].name = s1;
        sit[getId(s1)].address = s2;
        sit[getId(s1)].otherMessage = s3;
    }
    printf("�������·���ӵ������ص㼰�仨�Ѵ���:\n");
    while (m--)
    {
        char s1[N];
        char s2[N];
        int t3;
        scanf("%s %s %d", s1, s2, &t3);
        getId(s1);
        getId(s2);
        g[getId(s1)][getId(s2)] = g[getId(s2)][getId(s1)] = min(g[getId(s1)][getId(s2)], t3);
    }
    printf("�ڽӾ���:\n");
    printf("    ");
    for (int i = 1; i <= n; i++)
        printf("%4s", sites[i].c_str());
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%4s", sites[i].c_str());
        for (int j = 1; j <= n; j++)
            printf("%4d", g[i][j] > 0x3f ? 0 : g[i][j]);
        printf("\n");
    }
    while (1)
    {
        
        printf("\n���� 'q ��������' ��ѯ������Ϣ\n");
        printf("���� 'p ����A ����B' ��ѯ���·��\n");
        printf("���� 'exit' �˳�\n\n");
        string opt, t1, t2;
        cin >> opt;
        if (opt == "exit")
            break;
        if (opt == "q")
        {
            cin >> t1;
            if (sit[getId(t1)].name.size() == 0)
            {
                cout << "����ľ�������" << endl;
                continue;
            }
            cout << "��������:" << sit[getId(t1)].name << endl
                 << "�����ַ:" << sit[getId(t1)].address << endl
                 << "������" << sit[getId(t1)].otherMessage << endl;
        }
        if (opt == "p")
        {
            cin >> t1 >> t2;
            strPos = getId(t1);
            targetPos = getId(t2);
            printf("���·��:");
            int t = prim();
            printf("\n��С����:%d\n", t);
        }
    }
    return 0;
}