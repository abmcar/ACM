#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int k,n;
int ans;
int nowMultiple = 1;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> k >> n;
    while(n != 0)
    {
        int nownum = n % 2;
        ans += nownum*nowMultiple;
        nowMultiple *= k;
        n = n/2;
    }
    cout << ans;
    return 0;
}
/*
100 / 2
50 0
25 0
12 1
6 0
3 0
1 1
0 1
1+6+9+81
*/