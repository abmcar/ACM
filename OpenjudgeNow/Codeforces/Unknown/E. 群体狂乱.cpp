#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#define ll long long
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl "\n"

class atker
{
public:
    int atk, hp, nowpos;
    bool isAlive;
    void skill_Atk(vector<atker> &db, int pos);
    // bool isAlive();
};

// bool atker::isAlive()
// {

// }

void atker::skill_Atk(vector<atker> &db, int pos)
{
    db[pos].hp = db[pos].hp - atk;
    hp = hp - db[pos].atk;
    if (db[pos].hp <= 0)
        db[pos].isAlive = false;
    if (hp <= 0)
        isAlive = false;
}

atker atkers[10];
int p[7];
int n;
double totn[10], tota[10];
bool unDead[10];
int totAtk = 0;


void dfs(vector<atker> t1, vector<int> nowP, int now, double tempD)
{
    // cout << now << "  pass " <<  tempD << endl;
    // int totAlive = 0;
    // for (int i = 0; i < n; i++)
    //     if (t1[i].isAlive())
    //         totAlive++;
    // cout << allDead << endl;
    if (now == n+1)
    {
        // cout << "try fin" << endl;
        for (int i = 0; i < n; i++)
        {
            // totn[i] += tempD;
            if (t1[i].isAlive)
                tota[i] += tempD;
            // cout << "end: " << totn[i] << " " <<  tota[i] << endl;
        }
        return;
    }
    // for (int i = 0; i < n; i++)
    //     if (t1[i].hp <= 0)
    //         t1[i].atk = 0;
    // cout << now << "  pass " <<  nowP[now-1] << endl;
    // cout << "pass" << endl;
    double nextb = 0;
    for (int i = 0; i < n; i++)
    {
        if (!t1[i].isAlive)
            continue;
        if (i == nowP[now-1]-1)
            continue;
        if (unDead[i+1])
            continue;
        nextb++;
    }
    if (!t1[nowP[now-1]-1].isAlive || nextb <= 0)
    {
        dfs(t1,nowP,now+1,tempD);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!t1[i].isAlive)
            continue;
        if (i == nowP[now-1]-1)
            continue;
        vector<atker> nowAtker = t1;
        // cout << "before atk:" << tempD<< endl;
        // cout << nowAtker[nowP[now-1]-1].hp << " " <<nowAtker[i].hp <<endl;
        nowAtker[nowP[now-1]-1].skill_Atk(nowAtker, i);
        // cout << nowP[now-1]-1 << " atk " << i << endl;
        // cout << "atk finish" <<endl;
        // cout << nowAtker[nowP[now-1]-1].hp << " " <<nowAtker[i].hp <<endl;
        dfs(nowAtker,nowP,now+1,(tempD/nextb));
    }
}

int maxAtk = 0;

int main()
{
    Buff;
    cin >> n;
    double strD = 1;
    for (int i = 1; i <= n; i++)
        cin >> atkers[i].atk >> atkers[i].hp, p[i] = i, strD *= i, atkers[i].isAlive = true, totAtk+= atkers[i].atk, maxAtk = max(maxAtk,atkers[i].atk);
    if (n == 6)
    {
        for (int i = 1; i <= n; i++)
        {
            if (atkers[i].atk != maxAtk)
            {
                if (totAtk - atkers[i].atk + maxAtk< atkers[i].hp)
                    unDead[i] = true;
            }else
            {
                int nextMax = 0;
                for (int j = 1; j <= n; j++)
                {
                    if (i == j)
                        continue;
                    nextMax = max(nextMax,atkers[j].atk);
                }
                if (totAtk - atkers[i].atk +nextMax < atkers[i].hp)
                    unDead[i] = true;
            }
        }
    }
    do
    {
        vector<atker> tempV;
        vector<int> V;
        for (int i = 1; i <= n; i++)
            V.push_back(p[i]), tempV.push_back(atkers[i]);
        dfs(tempV,V,1,1/strD);
    }while (next_permutation(p+1,p+1+n));
    for (int i = 0; i < n; i++)
    {
        if (unDead[i])
            cout << 1 << endl;
        else
            cout << tota[i] << endl;
    }
    return 0;
}