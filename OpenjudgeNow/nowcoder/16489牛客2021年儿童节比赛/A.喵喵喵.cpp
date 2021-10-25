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

string originString;
string optString;
int k;
ll num1, num2, num3;

int main()
{
    Buff;
    cin >> originString >> k >> optString;
    for (int i = 0; i < originString.size(); i++)
    {
        if (originString[i] == 'n')
        {
            num1++;
            continue;
        }
        if (originString[i] == 'y')
        if (i+1 < originString.size())
        if (originString[i+1] == 'a')
        {
            num2++;
            i++;
            continue;
        }
        num3++;
    }
    // cout << num1 << endl << num2 << endl << num3 << endl;
    for (int i = 0; i < k; i++)
        if (optString[i] == 'N')
        {
            num2 += num1;
            num2 = num2 % Mod;
        }else
        {
            num1 += num2;
            num2 = 0;
            num1 = num1 % Mod;
        }
    cout << (num1+num2*2+num3)%Mod << endl;
    return 0;
}