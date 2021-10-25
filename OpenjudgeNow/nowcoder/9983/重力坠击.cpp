#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#define ll long long

using namespace std;

const int Maxn = 23;
const ll Mod = 1e9+7;
int n,k,R;
int x[Maxn],y[Maxn],r[Maxn],pos[Maxn];
vector<int> hitpos[Maxn][Maxn];
int ans;

double getL(int posx, int posy, int nowpos)
{
    double nowl = (posx-x[nowpos])*(posx-x[nowpos]) + (posy-y[nowpos])*(posy-y[nowpos]);
    return sqrt(nowl);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> k >> R;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
        x[i] += 7;
        y[i] += 7;
        pos[i] = i;
    }
    for(int i = 0; i <= 14; i++)
    for(int j = 0; j <= 14; j++)
    for(int tk = 1; tk <= n; tk++)
        if(R+r[tk] >= getL(i,j,tk))
            hitpos[i][j].push_back(tk);
    for(int x1 = 0; x1 <= 14; x1++)
    for(int y1 = 0; y1 <= 14; y1++)
    {
        if(hitpos[x1][y1].size() == 0)
            continue;
        for(int x2 = 0; x2 <= 14; x2++)
        for(int y2 = 0; y2 <= 14; y2++)
        {
            if(hitpos[x2][y2].size() == 0)
                continue;
            if(x2 == x1 && y2 == y1)
                continue;
            for(int x3 = 0; x3 <= 14; x3++)
            for(int y3 = 0; y3 <= 14; y3++)
            {
                if(x3 == x2 && y3 == y2)
                    continue;
                if(x3 == x1 && y3 == y1)
                    continue;
                if(k == 2)
                    x3 = 14, y3 = 14;
                if(k == 1)
                    x2 = 14, y2 = 14;
                set<int> s;
                for(int i = 0; i < hitpos[x1][y1].size(); i++)
                    s.insert(hitpos[x1][y1][i]);
                if(k == 1)
                {
                    ans = max(ans,(int)s.size());
                    continue;
                }
                for(int i = 0; i < hitpos[x2][y2].size(); i++)
                    s.insert(hitpos[x2][y2][i]);
                if(k == 2)
                {
                    ans = max(ans,(int)s.size());
                    continue;
                }
                for(int i = 0; i < hitpos[x3][y3].size(); i++)
                    s.insert(hitpos[x3][y3][i]);
                ans = max(ans,(int)s.size());
                if(ans == n)
                {
                    cout << n;
                    return 0;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
//14*14*3*10