#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
// #include <unordered_map>
// #include <unordered_set>
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int pos[33];

vector<int> V[33];
int n;
void rePlace1(int id)
{
    // cout << "test1" << endl;
    int nowPos = pos[id];
    bool ok = true;
    for (int i = 0; i < V[nowPos].size(); i++)
    {
        if (V[nowPos][i] == id)
        {
            ok = false;
            continue;
        }
        if (ok)
            continue;
        else
        {
            int nowId = V[nowPos][i];
            V[nowId].push_back(nowId);
            pos[nowId] = nowId;
            V[nowPos][i] = -1;
        }
    }
    while (V[nowPos][V[nowPos].size() - 1] == -1)
        V[nowPos].pop_back();
}

void move(int id1, int id2)
{
    // cout << "move " << id1 << " " << id2 << endl;
    int nowPos = pos[id1];
    V[nowPos].pop_back();
    pos[id1] = pos[id2];
    V[pos[id2]].push_back(id1);
}

void opt1(int id1, int id2)
{
    rePlace1(id1);
    rePlace1(id2);
    move(id1, id2);
}

void opt2(int id1, int id2)
{
    rePlace1(id1);
    move(id1, id2);
}

void opt3(int id1, int id2)
{
    rePlace1(id2);
    if (pos[id1] == pos[id2])
        return;
    int nowPos = pos[id1];
    while (V[nowPos][V[nowPos].size() - 1] != id1)
        move(V[nowPos][V[nowPos].size() - 1], n);
    move(id1, id2);
    for (int i = V[n].size() - 1; i >= 0; i--)
        move(V[n][i], id2);
}

void opt4(int id1, int id2)
{
    if (pos[id1] == pos[id2])
        return;
    int nowPos = pos[id1];
    while (V[nowPos][V[nowPos].size() - 1] != id1)
        move(V[nowPos][V[nowPos].size() - 1], n);
    move(id1, id2);
    for (int i = V[n].size() - 1; i >= 0; i--)
        move(V[n][i], id2);
}

int main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        if (i != n)
        V[i].push_back(i);
        pos[i] = i;
    }
    String nowOpt1, nowOpt2;
    int nowId1, nowId2;
    while (cin >> nowOpt1)
    {
        if (nowOpt1 == "quit")
            break;
        cin >> nowId1 >> nowOpt2 >> nowId2;
        if (nowOpt1 == "move" && nowOpt2 == "onto")
            opt1(nowId1, nowId2);
        else if (nowOpt1 == "move" && nowOpt2 == "over")
            opt2(nowId1, nowId2);
        else if (nowOpt1 == "pile" && nowOpt2 == " onto")
            opt3(nowId1, nowId2);
        else
            opt4(nowId1, nowId2);
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        for (int j = 0; j < V[i].size(); j++)
            cout << " " << V[i][j];
        // for (int nowNum : V[i])
        //     cout << " " << nowNum;
        cout << endl;
    }
    return 0;
}