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

string tempString;
int ans, lastPos = -2;
bool ok = false;
int main()
{
    Buff;
    cin >> tempString;
    for (int i = 0; i < tempString.size(); i++)
    {
        if (tempString[i] == '1')
        {
            if (lastPos == i-1)
                lastPos = i;
            else
            {
                ans++;
                lastPos = i;
                if (i != tempString.size()-1)
                {
                    if (tempString[i+1] == '0')
                        ok = true;
                }else
                if (i == tempString.size()-1)
                    ok = true;
            }
        }else
        {
            if (i != 0 && i != tempString.size()-1)
            {
                if (tempString[i-1] == '1' && tempString[i+1] == '1')
                    ok = true;
            }
        }
    }

    if (ok)
        ans--;
    cout << ans;
    return 0;
}