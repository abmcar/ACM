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
int appleHigh[Maxn],bodyHigh;
int ans;

int main()
{
    Buff;
    for(int i = 1; i <= 10; i++)
        cin >> appleHigh[i];
    cin >> bodyHigh;
    for(int i = 1; i <= 10; i++)
        if(appleHigh[i] <= bodyHigh+30)
            ans++;
    cout << ans;
    return 0;
}