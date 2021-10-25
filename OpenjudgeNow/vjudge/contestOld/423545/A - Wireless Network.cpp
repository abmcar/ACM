#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
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
#define endl "\n"

using namespace std;

const int Maxn = 1e4+10;
const ll Mod = 1e9+7;
int n,d;
map<pair<int,int>,int> M;
bool repired[Maxn];
int posX[Maxn];
int posY[Maxn];
int father[Maxn];

int find(int son)
{
    if(father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

int main()
{
    Buff;
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
    {
        father[i] = i;
        cin >> posX[i] >> posY[i];
        pair<int,int> pos;
        pos.first = posX[i];
        pos.second = posY[i];
        M[pos] = i;
    }
    char opt;
    while(cin >> opt)
    {
        int temp;
        if(opt == 'O')
        {
            cin >> temp;
            pair<int,int> nowpos;
            nowpos.first = posX[temp];
            nowpos.second = posY[temp];
            for(int i = 1; i <= n; i++)
            {
                int dis = (posX[temp]-posX[i])*(posX[temp]-posX[i]) + (posY[temp]-posY[i])*(posY[temp]-posY[i]);
                if(repired[i])
                if(dis <= d*d)
                if(find(temp) != find(i))
                    father[find(temp)] = find(i);
            }
            repired[temp] = true;
        }else
        {
            int t1,t2;
            cin >> t1 >> t2;
            if(find(t1) == find(t2))
                cout << "SUCCESS" << endl;
            else
                cout << "FAIL" << endl;
            // cout << find(t1) << " " << find(t2) << endl;
        }
    }
    return 0;
}