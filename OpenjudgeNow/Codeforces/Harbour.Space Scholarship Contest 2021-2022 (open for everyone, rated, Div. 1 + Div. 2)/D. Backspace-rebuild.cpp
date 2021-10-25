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

int t;
string s1, s2;

void work()
{
    cin >> s1 >> s2;
    int nowPos = 0;
    int finPos = 0;
    int len1 = s1.size();
    int len2 = s2.size();
    for (int i = (len1-len2)%2; i < len1; i++)
    {
        if (nowPos < len2)
        if (s1[i] == s2[nowPos])
        {
            finPos = i;
            nowPos++;
            continue;
        }
        i++;
    }
    if ((len1 - finPos) % 2 == 1)
    if (nowPos == len2)
    {
        cout << "YES" << Endl;
        return;
    }
    cout << "NO" << Endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}