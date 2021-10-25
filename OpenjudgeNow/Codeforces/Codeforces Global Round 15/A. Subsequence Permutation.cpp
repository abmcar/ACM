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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;
string oriString;

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n >> oriString;
        map<char,int> M;
        for (char i : oriString)
            M[i]++;
        int nowPos = 0;
        for (pair<char,int> it : M)
        {
            for (int i = 1; i <= it.second; i++)
            {
                if (oriString[nowPos] != it.first)
                    ans++;
                nowPos++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}