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

int t, a, b;
string originString;

bool check(string tempS)
{
    int n = tempS.size()-1;
    for (int i = 1; i <= n; i++)
        if (originString[i] != originString[n-i+1] || originString[i] == '?')
            return false;
    return true;
}

void work()
{
    cin >> b >> a;
    cin >> originString;
    int n = originString.size();
    originString = "A" + originString;
    for (int i = 1; i <= n; i++)
    {
        if (originString[i] == '1')
            a--;
        if (originString[i] == '0')
            b--;
    }
    if (a < 0 || b < 0)
    {
        cout << "-1" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (originString[i] == '?')
        {
            if (originString[n-i+1] == '?')
                continue;
            if (originString[n-i+1] == '1' && a > 0)
            {
                originString[i] = '1';
                a--;
            }else
            {
                if (b > 0)
                {
                    originString[i] = '0';
                    b--;
                }
            }
        }
    }
    // if (a % 2 == 1 || b % 2 == 1)
    // {
    //     if (originString[(n+1)/2] != '?')
    //     {
    //         cout << "-1" << endl;
    //         return;
    //     }
    // }
    for (int i = 1; i <= n; i++)
        if (originString[i] == '?')
        {
            if (a > 0)
            {
                originString[i] = '1';
                originString[n-i+1] = '1';
                a -= 2;
                if (i == n-i+1)
                    a++;
                if (a < 0)
                {
                    originString[i] = '?';
                    originString[n-i+1] = '?';
                    a += 2;
                }
            }else
            {
                if (b > 0)
                {
                    originString[i] = '0';
                    originString[n-i+1] = '0';
                    b -= 2;
                    if (i == n-i+1)
                        b++;
                    if (b < 0)
                    {
                        originString[i] = '?';
                        originString[n-i+1] = '?';
                        b += 2;
                    }
                }
            }
        }
    if (!check(originString))
    {
        cout << "-1" << endl;
        return ;
    }
    for (int i = 1; i <= n; i++)
        cout << originString[i];
    cout << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}