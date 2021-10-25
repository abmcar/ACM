#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
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
ll num[Maxn];
ll preans[Maxn];

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        preans[i] = preans[i-1] + num[i];
    }
    for(int i = n; i >= 0; i--)
    {
        for(int j = 1; j <= n-i+1; j++)
            if((preans[j+i-1]-preans[j-1]) % 7 == 0)
            {
                cout << i << endl;
                return 0;
            }
    }
    return 0;
}