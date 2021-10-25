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
string oriS;
map<char,int> M;

void work()
{
    M.clear();
    cin >> oriS;
    int num1, num2;
    num1 = num2 = 0;
    for (int i = 0; i < oriS.size(); i++)    
        M[oriS[i]]++;
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (M[i] == 1)
            num1++;
        if (M[i] >= 2)
            num2++;
    }
    int ans = num2 + num1/2;
    cout << ans << endl;
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