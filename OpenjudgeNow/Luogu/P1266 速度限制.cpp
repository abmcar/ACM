#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
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

int n, m, d;
vector<int> g[Maxn], l[Maxn], v[Maxn];
double dis[Maxn][Maxn];
int pre[Maxn][Maxn];
int preV[Maxn][Maxn];
int finV;
bool inQ[Maxn][Maxn];

struct Node
{
    int pos, v;
    bool const operator<(Node b) const
    {
        return pos < b.pos;
    }
    bool const operator==(Node b) const
    {
        if(pos == b.pos && v == b.v)
            return true;
        return false;
    }
};
// unordered_map<Node, Node> M;
Node nodes[Maxn][Maxn];

void spfa(int strNode)
{
    queue<int> qN, qV;
    qN.push(strNode);
    qV.push(70);
    inQ[strNode][70] = true;
    dis[strNode][70] = 0;
    while (!qN.empty())
    {
        int nowNode = qN.front();
        int nowV = qV.front();
        qN.pop();
        qV.pop();
        // cout << nowNode << " " << nowV << " " << dis[nowNode][nowV]<< endl;
        if(nowNode == d)
            continue;
        inQ[nowNode][nowV] = false;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            int nextV = v[nowNode][i];
            int nextL = l[nowNode][i];
            if (nextV == 0)
                nextV = nowV;
            double nextT = dis[nowNode][nowV] + ((double)nextL / (double)nextV);
            // cout << "pass #1 " << nowNode << " " << nextNode << " " << nextV << " " << nextL << " " << nextT << " " << endl;
            if (dis[nextNode][nextV] > nextT)
            {
                // cout << "pass #2 " << nowNode << " " << nextNode << " " << nextV << " " << nextL << " " << nextT << " " << endl;
                if(nextNode == 6 && nextV == 70)
                {
                    // cout << nowNode << " " << nowV << "          !!!" << endl;
                }
                Node nex = {nextNode, nextV};
                Node nown = {nowNode, nowV};
                nodes[nextNode][nextV] = nown;
                dis[nextNode][nextV] = nextT;
                if (!inQ[nextNode][nextV])
                {
                    inQ[nextNode][nextV] = true;
                    qN.push(nextNode);
                    qV.push(nextV);
                }
            }
        }
    }
}

int main()
{
    Buff;
    cin >> n >> m >> d;
    d++;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 666; j++)
            dis[i][j] = 1e9;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        g[t1 + 1].push_back(t2 + 1);
        v[t1 + 1].push_back(t3);
        l[t1 + 1].push_back(t4);
    }
    spfa(1);
    double tempmin = 1e9;
    for (int i = 1; i <= 500; i++)
        if (dis[d][i] < tempmin)
        {
            tempmin = min(tempmin, dis[d][i]);
            finV = i;
        }
    nodes[1][70].pos = -1;
    // cout << tempmin << " " << finV << endl;
    stack<Node> S;
    Node temp = {d, finV};
    // cout << nodes[6][70].pos << " " << nodes[6][70].v << endl;
    while(temp.pos != 1)
    {
        S.push(temp);
        temp = nodes[temp.pos][temp.v];
        // cout << temp.pos << " " << temp.v << endl;
    }
    cout << "0 ";
    while (!S.empty())
    {
        cout << S.top().pos-1 << " ";
        S.pop();
    }
    return 0;
}