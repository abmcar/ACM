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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n;
string S;
map<int, int> M;
map<char, int> charToInt;
int ans;

int main()
{
    Buff;
    cin >> n;
    cin >> S;
    int cnt = 0;
    for (int i = 'a'; i <= 'z'; i++)
        charToInt[(char)i] = ++cnt;
    for (int i = 'A'; i <= 'Z'; i++)
        charToInt[(char)i] = ++cnt;
    for (int i = '0'; i <= '9'; i++)
        charToInt[(char)i] = ++cnt;
    if (n > cnt)
    {
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
        M[charToInt[S[i]]]++;
    for (int i = 1; i < cnt; i++)
    {
        if (M[i] > 1)
        {
            ans += M[i] - 1;
            M[i + 1] += M[i] - 1;
            M[i] = 1;
        }
    }
    if (M[cnt] > 1)
    {
        // cout << "pass\n";
        ans += M[cnt] - 1;
        M[1] += M[cnt] - 1;
        M[cnt] = 1;
    }
    for (int i = 1; i < cnt; i++)
    {
        // cout << i << " " << M[i] << endl;
        if (M[i] > 1)
        {
            ans += M[i] - 1;
            M[i + 1] += M[i] - 1;
            M[i] = 1;
        }
    }
    // cout << charToInt['a'] << endl;
    // cout << cnt << endl;
    cout << ans;
    return 0;
}
/*
abc99 0
abc0a 1
abbc 2
abcc 3
abcd 4
*/