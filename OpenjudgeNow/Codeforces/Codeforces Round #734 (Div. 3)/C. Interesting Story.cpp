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
#include <unordered_map>
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

int t, n, ans;

void work()
{
    unordered_map<char, vector<string>> M, uM;
    unordered_map<char, vector<int>> M1, M2, uM1, uM2;
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string tempString;
        cin >> tempString;
        int a, b, c, d, e;
        a = b = c = d = e = 0;
        for (int i = 0; i < tempString.size(); i++)
        {
            if (tempString[i] == 'a')
                a++;
            if (tempString[i] == 'b')
                b++;
            if (tempString[i] == 'c')
                c++;
            if (tempString[i] == 'd')
                d++;
            if (tempString[i] == 'e')
                e++;
        }
        int tot = a + b + c + d + e;
        if (2 * a >= tot)
            M['a'].push_back(tempString), M1['a'].push_back(a), M2['a'].push_back(tot-a);
        else
            uM['a'].push_back(tempString), uM1['a'].push_back(a), uM2['a'].push_back(tot-a);
        if (2 * b >= tot)
            M['b'].push_back(tempString), M1['b'].push_back(b), M2['b'].push_back(tot-b);
        else
            uM['b'].push_back(tempString), uM1['b'].push_back(b), uM2['b'].push_back(tot-b);
        if (2 * c >= tot)
            M['c'].push_back(tempString), M1['c'].push_back(c), M2['c'].push_back(tot-c);
        else
            uM['c'].push_back(tempString), uM1['c'].push_back(c), uM2['c'].push_back(tot-c);
        if (2 * d >= tot)
            M['d'].push_back(tempString), M1['d'].push_back(d), M2['d'].push_back(tot-d);
        else
            uM['d'].push_back(tempString), uM1['d'].push_back(d), uM2['d'].push_back(tot-d);
        if (2 * e >= tot)
            M['e'].push_back(tempString), M1['e'].push_back(e), M2['e'].push_back(tot-e);
        else
            uM['e'].push_back(tempString), uM1['e'].push_back(e), uM2['e'].push_back(tot-e);
    }
    for (char nowChar = 'a'; nowChar <= 'e'; nowChar++)
    {
        int mostNum = 0;
        int otherNum = 0;
        int nowAns = 0;
        for (int i = 0; i < M[nowChar].size(); i++)
        {
            mostNum += M1[nowChar][i];
            otherNum += M2[nowChar][i];
            nowAns++;
        }
        // cout << mostNum << " " << otherNum << " " << nowAns << endl;
        if (mostNum == otherNum)
            continue;
        vector<int> V;
        int nowD = mostNum - otherNum;
        for (int i = 0; i < uM[nowChar].size(); i++)
            V.push_back(uM2[nowChar][i] - uM1[nowChar][i]);
        sort(V.begin(),V.end());
        for (int i = 0; i < V.size(); i++)
        {
            // cout << nowAns << " " << nowD << "  " << V[i] << " vi" << endl;
            nowD = nowD - V[i];
            if (nowD <= 0)
            {
                ans = max(ans, nowAns);
                break;
            }
            nowAns++;
        }
        if (nowD > 0)
        {
            cout << n << endl;
            return;
        }
    }
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