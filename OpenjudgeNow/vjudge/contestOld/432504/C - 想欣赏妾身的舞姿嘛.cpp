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

const int Maxn = 1e5 + 10;
const ll Mod = 1000000007;

string originString;
string tempString;
ll dp[Maxn][20];

int main()
{
    Buff;
    cin >> originString >> tempString;
    // if (originString == tempString)
    // {
    //     cout << "1";
    //     return 0;
    // }
    // for (int j = originString.size()-1; j >= 0; j--)
    //     if (originString[j] < 97)
    //         originString[j] += 32;
    // for (int j = tempString.size()-1; j >= 0; j--)
    //     if (tempString[j] < 97)
    //         tempString[j] += 32;
    // cout << originString << " " << tempString << endl;
    for (int j = originString.size()-1; j >= 0; j--)
    {
        dp[j][tempString.size()-1] = dp[j+1][tempString.size()-1];
        if (originString[j] == tempString[tempString.size()-1])
            dp[j][tempString.size()-1]++;
    }
    for (int i = tempString.size()-2; i >= 0; i--)
    {
        for (int j = originString.size()-1; j >= 0; j--)
        {
            dp[j][i] = dp[j+1][i];
            if (originString[j] == tempString[i])
                dp[j][i] = (dp[j][i] + dp[j+1][i+1]) % Mod;
        }
    }
    cout << dp[0][0] % Mod;
    return 0;
}