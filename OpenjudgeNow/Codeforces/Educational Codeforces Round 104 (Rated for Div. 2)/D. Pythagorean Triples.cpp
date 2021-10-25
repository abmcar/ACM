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
int t,n;

void work()
{
    cin >> n;
    int ans = 0;
    for(int i = 3; (i*i+1)/2 <= n; i += 2)
        ans++;
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}


/*

c*c - b*b = b + c
c*c - c = b*b + b
(c-1)*c = b*(b+1)
c*c = a*a + b*b
12
3
23 
5
16
25 12 13
5
49 24 25
81 40 41
*/