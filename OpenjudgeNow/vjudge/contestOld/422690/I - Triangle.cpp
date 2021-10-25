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
int a,b,n,x;

int main()
{
    Buff;
    cin >> a >> b >> n;
    for(int i = -1000; i <= 1000; i++)
        if(a*pow(i,n) == b)
        {
            cout << i << endl;
            return 0;
        }
    cout << "No solution" << endl;
    return 0;
}