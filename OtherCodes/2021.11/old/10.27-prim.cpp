#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int Maxn = 1e3 + 10;
const int INF = 0x3f3f3f3f;

int totCost, n;
int country[Maxn][Maxn];
int buildCost[Maxn][Maxn], destroyCost[Maxn][Maxn];
int cost[Maxn][Maxn], dis[Maxn];
bool vis[Maxn];

void getArray(string nowString, int nowArray[Maxn][Maxn])
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        char nowChar, nowCost;
        for (int j = 1; j <= n; j++)
        {
            nowChar = nowString[cnt++];
            if (nowChar >= '0' && nowChar <= '1')
                nowCost = nowChar - '0';
            else if (nowChar >= 'a' && nowChar <= 'z')
                nowCost = nowChar - 'a' + 26;
            else
                nowCost = nowChar - 'A';
            nowArray[i][j] = nowCost;
        }
        cnt++;
    }
}

void get()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == ',')
        {
            n = i;
            break;
        }
    }
    getArray(s1, country);
    getArray(s2, buildCost);
    getArray(s3, destroyCost);
}

void preWork()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (country[i][j] == 1)
            {
                totCost += destroyCost[i][j];
                cost[i][j] = destroyCost[i][j] * -1;
            }
            else
                cost[i][j] = buildCost[i][j];
        }
    totCost = totCost / 2;
}

int prim()
{
    memset(dis, 0x3f, sizeof dis);
    int res = totCost;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && (t == -1 || dis[t] > dis[j]))
                t = j;
        if (i)
            res += dis[t];
        vis[t] = true;
        for (int j = 1; j <= n; j++)
            dis[j] = min(dis[j], cost[t][j]);
    }
    return res;
}

int main()
{
    get();
    preWork();
    cout << prim() << endl;
    return 0;
}