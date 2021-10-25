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
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

String temp1 = "";

bool check(String nowString)
{
    for (char nowChar : nowString)
        if (nowChar != 'u' && nowChar != 'm')
        if ( (nowChar >= 'a' && nowChar <= 'z')
            || (nowChar >= 'A' && nowChar <= 'Z')
            || (nowChar >= '0' && nowChar <= '9')
            )
            return false;
    for (int i = 0; i < nowString.size(); i++)
        if (nowString[i] != 'u' && nowString[i] != 'm')
        {
            nowString.erase(i);
            i--;
        }
    return true;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    String tempString;
    while (cin >> tempString)
    {
        if (check(tempString))
            temp1 += tempString;
    }
    for (int i = 0; i < temp1.size()-1; i = i + 7)
    {
        int nowNum = 0;
        int cnt = 0;
        for (int j = i+6; j >= i; j--)
        {
            if (temp1[j] == 'u')
                nowNum += pow(2,cnt);
            cnt++;
        }
        // cout << nowNum << endl;
        cout << (char) nowNum;
    }
    return 0;
}                              