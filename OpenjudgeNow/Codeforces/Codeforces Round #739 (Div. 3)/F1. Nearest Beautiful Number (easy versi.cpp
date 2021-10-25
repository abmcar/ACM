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

int t, k;
ll n;

String toString(ll num)
{
    String nowString = "";
    while (num)
    {
        char nowChar = num % 10 + '0';
        num = num / 10;
        nowString = nowChar + nowString;
    }
    return nowString;
}

void work()
{
    cin >> n >> k;
    String tempString = toString(n);
    String string = toString(n);
    if (k == 1)
    {
        bool isAdd = false;
        for (int i = 0; i < string.size(); i++)
            if (string[i] != string[0])
            {
                if (string[i] > string[0])
                    isAdd = true;
                break;
            }
        if (isAdd)
            string[0]++;
        for (int i = 0; i < string.size(); i++)
            string[i] = string[0];
        cout << string << endl;
    }else
    {
        int pos = -1;
        bool isAdd = false;
        for (int i = 0; i < string.size(); i++)
        {
            if (string[i] != string[0])
            {
                for (int j = i + 1; j < string.size(); j++)
                    if (string[j] != string[i])
                    {
                        if (string[j] > string[i])
                            isAdd = true;
                        break;   
                    }
                if (isAdd && string[i]+1 == string[0])
                {
                    isAdd = false;
                    pos = i + 1;
                    break;
                    // continue;
                }
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            for (int i = 0; i < string.size(); i++)
                string[i] = string[0];
            cout << string << endl;
        }else
        {
            if (isAdd)
            {
                string[pos] = string[pos] + 1;
                char tempChar = string[pos];
                for (int i = 0; i < pos; i++)
                {
                    if (string[i] <= string[0] && string[i] <= string[pos])
                        string[i] = min(string[0],(char)(string[pos] ));
                    else
                        string[i] = string[0];
                }
                for (int i = pos+1; i < string.size(); i++)
                        string[i] = min(string[0],(char)(string[pos]));
                for (int i = 0; i < string.size(); i++)
                {
                    if (string[i] > tempString[i])
                    {
                        for (int j = i+1; j <= string.size(); j++)
                            string[j] = min(string[0],tempChar);
                        break;
                    }
                }
                cout << string << endl;
            }else
            {
                for (int i = 0; i < pos; i++)
                { 
                    if (string[i] <= string[0] && string[i] <= string[pos])
                        string[i] = min(string[0],(char)(string[pos] ));
                    else
                        string[i] = string[0];
                }
                for (int i = pos; i < string.size(); i++)
                {
                    if (string[i] <= string[0] && string[i] <= string[pos])
                        string[i] = min(string[0],(char)(string[pos] ));
                    else
                        string[i] = string[pos];
                }
                char tempChar = string[pos];
                for (int i = 0; i < string.size(); i++)
                {
                    if (string[i] > tempString[i])
                    {
                        for (int j = i+1; j <= string.size(); j++)
                            string[j] = min(string[0],tempChar);
                        break;
                    }
                }
                cout << string << endl;
            }
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