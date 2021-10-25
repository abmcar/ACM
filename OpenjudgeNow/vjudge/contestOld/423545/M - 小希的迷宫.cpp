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

using namespace std;

const int Maxn = 100010;
const ll Mod = 1e9+7;
int father[Maxn];
int ta,tb;
int ff;
bool ok = true;

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
    for(int i = 0; i <= Maxn; i++)
    father[i] = i;
    while(cin >> ta >> tb)
    {
        if(ta == -1 && tb == -1)
            return 0;
        if(ta == 0 && tb == 0)
        {
            for(int i = 1; i <= 100000; i++)
                if(find(i) != find(ff) && find(i) != i)
                    ok = false;
            if(ok)
                cout << "Yes\n";
            else
                cout << "No\n";
            for(int i = 0; i <= Maxn; i++)
                father[i] = i;
            ok = true;
            continue;
        }
        if(!ok)
            continue;
        if(find(ta) == find(tb))
        {
            // cout << ta << " " << tb << "\n";
            ok = false;
            continue;
        }
        ff = ta;
        if(ta == tb)
            continue;
        father[find(ta)] = find(tb);
    }
    return 0;
}