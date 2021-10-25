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
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t;
int s, n;

int len(int x)
{
    int nowLen = 0;
    while (x)
    {
        nowLen++;
        x = x / 10;
    }
    return nowLen;
}

int getNum(String tempString)
{
    int Num = 0;
    for (char i : tempString)
        Num = Num * 10 + i - '0';
    return Num;
}

void work()
{
    String oriString;
    cin >> oriString >> n;
    s = getNum(oriString);
    int tempN = 0;
    for (char nowChar : oriString)
        tempN += nowChar - '0';
    if (tempN >= n)
    {
        int nowN = 0;
        for (int i = 0; i < oriString.size(); i++)
        {
            for (int j = '0'; j < oriString[i]; j++)
            {
                if (nowN == n - 1)
                {
                    cout << s << endl;
                    return;
                }
                // if (nowN == n)
                // {
                //     cout << endl;
                //     return;
                // }
                cout << 1;
                for (int k = i; k < oriString.size() - 1; k++)
                    cout << "0";
                cout << " ";
                s = s - 1 * pow(10, oriString.size() - 1);
                nowN++;
            }
        }
    }
    else
    {
        vector<int> ans;
        int nowN = 0;
        for (int i = 0; i < oriString.size(); i++)
        {
            for (int j = '0'; j < oriString[i]; j++)
            {
                // if (nowN == n - 1)
                // {
                //     cout << s << endl;
                //     return;
                // }
                // if (nowN == n)
                // {
                //     cout << endl;
                //     return;
                // }
                // cout << 1;
                // for (int k = i; k < oriString.size() - 1; k++)
                //     cout << "0";
                // cout << " ";
                ans.push_back(pow(10,oriString.size()-i-1));
                s = s - pow(10, oriString.size() - i-1);
                nowN++;
            }
        }
        while (nowN < n)
        {
            ans[ans.size()-1] = ans[ans.size()-1]/10;
            for (int i = 1; i <= 9; i++)
            {
                ans.push_back(ans[ans.size()-1]);
                nowN++;
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            if (i == n-1)
            {
                int temp = ans[i];
                for (int j = i+1; j < ans.size(); j++)
                    temp += ans[j];
                cout << temp << endl;
                return;
            }
            cout << ans[i] << " ";
        }
    }
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