#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
map<string,int> mName;
int n;
int expA,expB,expC;
int numA,numB,numC;
int bestA,bestB,bestC;
ll maxn,minn,ans1,ans2;
bool likeOther[10][10];
int nowTeam[10];
int bestTeam[10];
bool used[10];
vector<int> teamA,teamB,teamC;

void prework()
{
    mName["Anka"] = 1;
    mName["Chapay"] = 2;
    mName["Cleo"] = 3;
    mName["Troll"] = 4;
    mName["Dracul"] = 5;
    mName["Snowy"] = 6;
    mName["Hexadecimal"] = 7;
}

void dfs(int Team,int num)
{
    // cout << Team << " " << num << endl;
    if(Team == 4)
    {
        ll tempLike = 0;
        for(int i = 1; i <= 7; i++)
        for(int j = 1; j <= 7; j++)
            if(likeOther[i][j])
            if(nowTeam[i] == nowTeam[j])
                tempLike++;
        ans2 = max(ans2,tempLike);
        // if(ans2 == tempLike)
        // {
        // for(int i = 1; i <= 7; i++)
        //     cout << nowTeam[i] << endl;
        // cout << endl;

        // }
        // cout << tempLike << endl;
        return;
    }
    if(Team == 1)
    {
        for(int i = 1; i <= 7; i++)
            if(!used[i])
            {
                used[i] = true;
                nowTeam[i] = 1;
                if(num+1 == bestA)
                    dfs(Team+1,0);
                else
                    dfs(Team,num+1);
                used[i] = false;
            }
    }
    if(Team == 2)
    {
        for(int i = 1; i <= 7; i++)
            if(!used[i])
            {
                used[i] = true;
                nowTeam[i] = 2;
                if(num+1 == bestB)
                    dfs(Team+1,0);
                else
                    dfs(Team,num+1);
                used[i] = false;
            }
    }
    if(Team == 3)
    {
        for(int i = 1; i <= 7; i++)
            if(!used[i])
            {
                used[i] = true;
                nowTeam[i] = 3;
                if(num+1 == bestC)
                    dfs(Team+1,0);
                else
                    dfs(Team,num+1);
                used[i] = false;
            }
    }
}

int main()
{
    Buff;
    prework();
    cin >> n;
    ans1 = 1e10;
    for(int i = 1; i <= n; i++)
    {
        string a,b,c;
        cin >> a >> b >> c;
        likeOther[mName[a]][mName[c]] = true;
    }
    cin >> expA >> expB >> expC;
    for(numA = 1; numA <= 5; numA++)
    for(numB = 1; numA+numB <= 6; numB++)
    {
        numC = 7 - numA - numB;
        maxn = 0;
        minn = 1e10;
        maxn = max(expA/numA,max(expB/numB,expC/numC));
        minn = min(expA/numA,min(expB/numB,expC/numC));
        if(maxn-minn < ans1 || (maxn-minn == ans1 && minn != 1))
        {
            ans1 = maxn-minn;
            bestA = numA;
            bestB = numB;
            bestC = numC;
        }
    }
    dfs(1,0);
    cout << ans1 << " " << ans2 << endl;
    return 0;
}