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
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int n;
int maxL, totL, target;
bool used[Maxn];
bool isEnd;
int preNext[Maxn];
int tempDeep;
vector<int> V;

void init()
{
    cin >> n;
    for(int i = 1; i <= n ;i++)
    {
        int temp;
        cin >> temp;
        if(temp > 50)
            continue;
        V.push_back(temp);
        maxL = max(maxL,temp);
        totL += temp;
    }
    // cout << V.size() << endl;
    // cout << "pass #1" << endl;
    sort(V.begin(),V.end(),greater<int>());
    preNext[V.size()-1] = V.size()-1;
    for(int i = V.size()-2; i >= 0; i--)
        if(V[i] == V[i+1])
            preNext[i] = preNext[i+1];
        else
            preNext[i] = i;
}

bool dfs(int deep, int nowpos, int nowless)
{
    // cout << "start dfs:" << deep << " " << nowpos << " " << nowless << endl;
    if(isEnd)
        return true;
    if(deep == tempDeep && nowless == 0)
    {
        // for(int i = 0; i < V.size(); i++)
        //     cout << used[i] << " ";
        // cout << endl;
        isEnd = true;
        return true;
    }
    if(nowless == 0)
        return dfs(deep+1,1,target);
    if(V[V.size()-1] > nowless)
        return false;
    int nextpos = lower_bound(V.begin()+nowpos,V.end(),nowless,greater<int>()) - V.begin();
    // nextpos = preNext[nextpos];
    for(int i = nextpos; i < V.size();i++)
    {
        if(used[i])
            continue;
        used[i] = true;
        if(dfs(deep,i,nowless-V[i]))
            return true;
        used[i] = false;
        if(nowless == V[i] || nowless == target)
            return false;
        i = preNext[i];
        // if(i == V.size()-1)
        //     continue;
    }
    return false;
}

void work()
{
    // cout << totL << endl;
    // cout << "pass #2" << endl;
    for(int i = maxL; i <= totL/2; i++)
        if(totL % i != 0)
            continue;
        else
        {
            target = i;
            // cout << i << " " << totL/target << endl;
            used[0] = true;
            tempDeep = totL/target;
            if(dfs(1,0,target-V[0]))
            {
                cout << i << endl;
                return;
            }
            used[0] = false;
        }
    cout << totL << endl;
}

int main()
{
    Buff;
    init();
    work();
    return 0;
}