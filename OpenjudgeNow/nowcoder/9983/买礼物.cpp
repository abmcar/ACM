#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 5e5+10;
const ll Mod = 1e9+7;
int num[Maxn];
int fpre[Maxn],faft[Maxn];
int n,q;
int presize[Maxn];
int aftsize[Maxn];
vector<int> vn[Maxn*2];
int needchange;
vector<int> needclear;

void updata()
{
    memset(fpre,0,sizeof(fpre));
    memset(faft,0,sizeof(faft));
    for(int i = 0; i < needclear.size(); i++)
        vn[needclear[i]].clear();
    for(int i = 1; i <= n; i++)
    {
        if(num[i] == -1)
        {
            fpre[i] += fpre[i-1];
            continue;
        }
        vn[num[i]].push_back(i);
        if(vn[num[i]].size() != 1)
            fpre[i]++;
        fpre[i] += fpre[i-1];
    }
    fpre[n+1] = fpre[n];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = 1; i <= n; i++)
    {
        if(num[i] == -1)
        {
            fpre[i] += fpre[i-1];
            continue;
        }
        vn[num[i]].push_back(i);
        if(vn[num[i]].size() != 1)
            fpre[i]++;
        else
            needclear.push_back(num[i]);
        fpre[i] += fpre[i-1];
    }
    fpre[n+1] = fpre[n];
    for(int nowq = 1; nowq <= q; nowq++)
    {
        int type;
        cin >> type;
        if(type == 2)
        {
            int l,r;
            cin >> l >> r;
            if(needchange != 0)
                updata(),needchange = 0;
            int tnum = fpre[n]-(fpre[n-(l-1)+1]-fpre[n-l+1])-(fpre[r+1]-fpre[r]);
            // cout << fpre[n] << " " << faft[l-1] << " " << faft[l] << " " << fpre[r+1] << " " << fpre[r] << endl;
            if(tnum != 0)
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }else
        {
            int a;
            cin >> a;
            num[a] = -1;
            needchange = 1;
        }
    }
    return 0;
}
/*
0 0 1 2 3
3 2 1 0 0
*/