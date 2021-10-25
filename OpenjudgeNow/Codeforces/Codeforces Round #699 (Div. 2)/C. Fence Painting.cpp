#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#define ll long long

using namespace std;

const int Maxn = 1e5+10;
const ll Mod = 1e9+7;
int t,n,m;
int anum[Maxn];
int bnum[Maxn];
int cnum[Maxn];
int ans[Maxn];

vector<int> needPaintPos[Maxn],unchangePaintPos[Maxn];
map<int,int> offerPaint,unchangeColor;

void work()
{
    cin >> n >> m;
    int needPaintNum = 0;
    int offerPaintNum = 0;
    offerPaint.clear();
    unchangeColor.clear();
    for(int i = 1; i <= n; i++)
    {
        cin >> anum[i];
        unchangeColor[anum[i]]++;
        if(unchangePaintPos[anum[i]].size() != 0)
            unchangePaintPos[anum[i]].clear();
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> bnum[i];
        if(needPaintPos[bnum[i]].size() != 0)
            needPaintPos[bnum[i]].clear();
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> cnum[i];
        if(needPaintPos[cnum[i]].size() != 0)
            needPaintPos[cnum[i]].clear();
        if(unchangePaintPos[cnum[i]].size() != 0)
            unchangePaintPos[cnum[i]].clear();
    }
    for(int i = 1; i <= n; i++)
    {
        if(anum[i] != bnum[i])
        {
            needPaintPos[bnum[i]].push_back(i);
            unchangeColor[anum[i]]--;
            needPaintNum++;
        }else
            unchangePaintPos[anum[i]].push_back(i);
    }
    int temppos;
    if(needPaintPos[cnum[m]].size() == 0)
    {
        if(unchangeColor[cnum[m]] != 0)
        {
            temppos = unchangePaintPos[cnum[m]][0];
            ans[m] = temppos;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }else
    {
        temppos = needPaintPos[cnum[m]][0];
        ans[m] = temppos;
        offerPaint[cnum[m]]++;
        offerPaintNum++;
    }
    for(int i = m-1; i >= 1; i--)
    {
        if(needPaintPos[cnum[i]].size() > offerPaint[cnum[i]])
        {
            ans[i] = needPaintPos[cnum[i]][offerPaint[cnum[i]]];
            offerPaint[cnum[i]]++;
            offerPaintNum++;
        }else
        {
            ans[i] = temppos;
        }
    }

    if(offerPaintNum < needPaintNum)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
        work();
    return 0;
}