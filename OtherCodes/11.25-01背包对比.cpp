#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const int MaxNum = 100;
const ll Mod = 1e9 + 7;

int n, totCost, nowAns;
int cost[Maxn], value[Maxn];
bool vis[Maxn];
int pre[Maxn];
double bu;
vector<int> ansV;

struct Node
{
    double unitValue;
    int oriId;
    bool operator<(Node b) const
    {
        return unitValue > b.unitValue;
    }
};

struct qNode
{
    int id, cost, value, bestValue;
    vector<int> nowStat;
    void print()
    {
        cout << id << ' ' << cost << " " << value << " " << bestValue << endl;
    }
};

void genData()
{
    srand(time(0));
    totCost = rand() % MaxNum * n;
    if (totCost >= 5000)
        totCost = 5000;
    for (int i = 1; i <= n; i++)
    {
        cost[i] = rand() % MaxNum + 1;
        value[i] = rand() % MaxNum + 1;
    }
}

void printInfo()
{
    cout << "当前物品数和最大容纳重量" << endl;
    cout << n << " " << totCost << endl;
    cout << "物品重量:" << endl;
    for (int i = 1; i <= n; i++)
        cout << cost[i] << ' ';
    cout << endl;
    cout << "物品价值" << endl;
    for (int i = 1; i <= n; i++)
        cout << value[i] << ' ';
    cout << endl;
}

int dp()
{
    clock_t strTime = clock();
    vector<int> f(totCost + 10);
    vector<vector<int>> V(totCost + 10);
    for (int i = 1; i <= n; i++)
        for (int j = totCost; j >= cost[i]; j--)
        {
            if (f[j - cost[i]] + value[i] > f[j])
            {
                f[j] = f[j - cost[i]] + value[i];
                vector<int> oldV = V[j - cost[i]];
                oldV.push_back(i);
                V[j] = oldV;
            }
        }
    cout << "动态规划法得到价值:";
    cout << f[totCost] << endl;
    map<int, int> M;
    for (int it : V[totCost])
        M[it] = true;
    cout << "动态规划法得到的物品序列:";
    for (int i = 1; i <= n; i++)
        cout << M[i] << " ";
    cout << endl;
    return clock() - strTime;
}

void dfs(int nowNode, int otherCost, int nowValue, vector<int> nowV)
{
    if (nowValue+otherCost*bu <= nowAns)
        return;
    if (nowValue > nowAns)
    {
        nowAns = nowValue;
        ansV = nowV;
    }
    for (int i = nowNode + 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (cost[i] > otherCost)
            continue;
        vis[i] = true;
        vector<int> tempV = nowV;
        tempV.push_back(i);
        dfs(i, otherCost - cost[i], nowValue + value[i], tempV);
        vis[i] = false;
    }
}

int solve1()
{
    clock_t strTime = clock();

    for (int i = 1; i <= n; i++)
    {
        pre[i] = -1, vis[i] = false;
        bu = max(bu, value[i] * 1.0 / cost[i]);
    }
    nowAns = 0;
    ansV.clear();
    vector<int> tempV;
    dfs(0, totCost, 0, tempV);
    cout << "回溯法得到价值:";
    cout << nowAns << endl;
    map<int, bool> M;
    for (int it : ansV)
        M[it] = true;
    cout << "回溯法得到的物品序列:";
    for (int i = 1; i <= n; i++)
        cout << M[i] << " ";
    cout << endl;
    return clock() - strTime;
}

int getUp(int id, int nowCost, int nowValue, vector<Node> unitV)
{
    for (int i = id; i <= n; i++)
    {
        if (nowCost < cost[unitV[i].oriId])
            continue;
        nowCost = nowCost - cost[unitV[i].oriId];
        nowValue += value[unitV[i].oriId];
    }
    return nowValue;
}

int solve2()
{
    clock_t strTime = clock();
    vector<Node> unitValues(n + 1);
    for (int i = 1; i <= n; i++)
    {
        unitValues[i].unitValue = value[i] * 1.0 / cost[i];
        unitValues[i].oriId = i;
    }
    sort(unitValues.begin() + 1, unitValues.end());
    int nowBestValue = 0;
    int finAns = 0;
    vector<int> ansV;
    queue<qNode> qN;
    qNode strNode{0, totCost, 0, 0, ansV};
    qN.push(strNode);
    while (!qN.empty())
    {
        qNode nowNode = qN.front();
        qN.pop();
        if (nowNode.id > n)
            continue;
        finAns = max(finAns, nowNode.value);
        nowNode.bestValue = getUp(nowNode.id, nowNode.cost, nowNode.value, unitValues);
        if (nowNode.bestValue >= nowBestValue)
        {
            qNode nextNode = nowNode;
            if (nextNode.cost < cost[unitValues[nextNode.id].oriId])
                continue;
            nowBestValue = nowNode.bestValue;
            nextNode.value = nextNode.value + value[unitValues[nextNode.id].oriId];
            nextNode.cost = nextNode.cost - cost[unitValues[nextNode.id].oriId];
            nextNode.nowStat.push_back(unitValues[nextNode.id].oriId);
            nextNode.id++;
            qN.push(nextNode);
            ansV = nextNode.nowStat;
        }
        qNode nextNode = nowNode;
        nextNode.id++;
        qN.push(nextNode);
    }
    cout << "分支限界法得到价值:";
    cout << nowAns << endl;
    map<int, bool> M;
    for (int it : ansV)
        M[it] = true;
    cout << "分支限界法得到的物品序列:";
    for (int i = 1; i <= n; i++)
        cout << M[i] << " ";
    cout << endl;
    return clock() - strTime;
}

signed main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cout << "输入背包物品数" << endl;
    cin >> n;
    // n = 2000;
    genData();
    printInfo();
    if (n <= 25)
    {
        int t1 = dp();
        int t2 = solve1();
        int t3 = solve2();
        cout << "动态规划耗时:" << t1 << endl;
        cout << "回溯耗时:" << t2 << endl;
        cout << "分支限界耗时:" << t3 << endl;
    }
    else
    {

        int t1 = dp();
        // int t2 = solve1();
        int t3 = solve2();
        cout << "动态规划耗时:" << t1 << endl;
        // cout << "回溯耗时:" << t2 << endl;
        cout << "分支限界耗时:" << t3 << endl;
    }
    return 0;
}