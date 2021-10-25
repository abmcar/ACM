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

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int n;
int rk[Maxn];
int father[Maxn];
int hall[Maxn];

int find(int son)
{
    if(father[son] == son)
        return son;
    int temp = father[son];
    father[son] = find(father[son]);
    rk[son] += rk[temp];
    return father[son];
}

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= 30010; i++)
    {
        father[i] = i;
        rk[i] = 0;
        hall[i] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        char tempChar;
        cin >>  tempChar;
        if(tempChar == 'M')
        {
            int t1,t2;
            cin >> t1 >> t2;
            if(find(t1) == find(t2))
                continue;
            int fa1 = find(t1);
            int fa2 = find(t2);
            rk[fa1] += hall[fa2];
            hall[fa2] += hall[fa1];
            father[fa1] = fa2;
        }else
        {
            int t3;
            cin >> t3;
            find(t3);
            cout << rk[t3] << endl;
        }
    }
    return 0;
}