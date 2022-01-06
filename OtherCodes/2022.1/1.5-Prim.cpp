#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e7 + 10;
const int N = 2333;

// �����ͱ���
int n, m;
// �ڽӾ���
int dis[N][N];
// Prim����
int nowDis[N];
// �Ƿ�ѡ��
bool ok[N];

int main()
{
    // ���뼰��ʼ������
    cout << "��������ͱ���" << endl;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        nowDis[i] = Maxn, ok[i] = false;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dis[i][j] = Maxn;
    int arg1, arg2, arg3;
    cout << "����ߵĶ˵�;���" << endl;
    while (m--)
    {
        cin >> arg1 >> arg2 >> arg3;
        dis[arg1][arg2] = min(dis[arg1][arg2], arg3);
        dis[arg2][arg1] = min(dis[arg2][arg1], arg3);
    }
    // Prim����С������
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
    // ���
    cout << "�ڽӾ���:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << (dis[i][j] == Maxn ? 0 : dis[i][j]) << " ";
        cout << endl;
    }
    if (nowCost == Maxn)
        cout << "��������С������" << endl;
    else
        cout << "��С����:" << nowCost << endl;
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