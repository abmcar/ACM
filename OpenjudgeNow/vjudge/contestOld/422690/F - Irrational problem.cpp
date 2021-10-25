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
int p1,p2,p3,p4,a,b;
int ans;

int main()
{
    Buff;
    cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
    for(int i = a; i <= b; i++)
        if(((i % p1) % p2) % p3 % p4 == i)
            ans++;
    cout << ans;
    return 0;
}