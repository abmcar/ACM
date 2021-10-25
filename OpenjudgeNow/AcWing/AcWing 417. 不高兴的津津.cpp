#include <iostream>
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

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int ans;
int maxtime;
int timea,timeb;

int main()
{
    Buff;
    for(int i = 1; i <= 7; i++)
    {
        cin >> timea >> timeb;
        if(timea + timeb > 8)
        {
            if(timea + timeb > maxtime)
            {
                maxtime = timea + timeb;
                ans = i;
            }
        }
    }
    cout << ans;
    return 0;
}