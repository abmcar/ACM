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

bool isPrime[210000];
bool vis[210000];
int cnt;
int t;

void init()
{
    for (int i = 2; i <= 100000; i++)
    {
        if (vis[i] == false)
        {
            vis[i] = true;
            isPrime[i] = true;
            cnt++;
            // cout << i << endl;
            for (int j = 2; j * i <= 100000; j++)
                vis[i*j] = true;
        }
    }
}

void work()
{
    int temp;
    cin >> temp;
    String oriString;
    cin >> oriString;
    for (char nowChar : oriString)
    {
        if (!isPrime[nowChar - '0'])
        {
            cout << 1 << endl << nowChar << endl;
            return;
        }
    }
    for (int i1 = 0; i1 < oriString.size(); i1++)
    for (int i2 = i1+1; i2 < oriString.size(); i2++)
    {
        char nowChar1 = oriString[i1];
        char nowChar2 = oriString[i2];
        int tempNum = (nowChar1-'0')*10 + nowChar2 - '0';
        if (!isPrime[tempNum])
        {
            cout << 2 << endl << tempNum << endl;
            return;
        }
    }
    for (int i1 = 0; i1 < oriString.size(); i1++)
    for (int i2 = i1+1; i2 < oriString.size(); i2++)
    for (int i3 = i2+1; i3 < oriString.size(); i3++)
    {
        char nowChar1 = oriString[i1];
        char nowChar2 = oriString[i2];
        char nowChar3 = oriString[i3];
        int tempNum = (nowChar1-'0')*100 + (nowChar2 - '0') * 10 + (nowChar3 - '0');
        if (!isPrime[tempNum])
        {
            cout << 3 << endl << tempNum << endl;
            return;
        }
    }
    for (int i1 = 0; i1 < oriString.size(); i1++)
    for (int i2 = i1+1; i2 < oriString.size(); i2++)
    for (int i3 = i2+1; i3 < oriString.size(); i3++)
    for (int i4 = i3+1; i4 < oriString.size(); i4++)
    {
        char nowChar1 = oriString[i1];
        char nowChar2 = oriString[i2];
        char nowChar3 = oriString[i3];
        char nowChar4 = oriString[i4];
        int tempNum = (nowChar1-'0')*1000 + (nowChar2 - '0') * 100 + (nowChar3 - '0') * 10 + (nowChar4 - '0') * 1;
        if (!isPrime[tempNum])
        {
            cout << 4 << endl << tempNum << endl;
            return;
        }
    }
    // for (char nowChar1 : oriString)
    // for (char nowChar2 : oriString)
    // for (char nowChar3 : oriString)
    // for (char nowChar4 : oriString)
    // for (char nowChar5 : oriString)
    // {
    //     int tempNum = (nowChar1-'0')*10000 + (nowChar2 - '0') * 1000 + (nowChar3 - '0') * 100 + (nowChar4- '0') * 10 + (nowChar5-'0')*1;
    //     if (!isPrime[tempNum])
    //     {
    //         cout << 5 << endl << tempNum << endl;
    //         return;
    //     }
    // }
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    init();
    cin >> t;
    while (t--)
        work();
    // cout << cnt;
    return 0;
}