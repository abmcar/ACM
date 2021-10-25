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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf ll_MAX
#define endl "\n"

using namespace std;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll n, k;
string oriString;
map<char,bool> M;
ll ans;

int main()
{
    Buff;
    cin >> n >> k >> oriString;
    for (ll i = 1; i <= k; i++)
    {
        char tempChar;
        cin >> tempChar;
        M[tempChar] = true;
    }
    for (ll i = 0; i < oriString.size(); i++)
    {
        if (M[oriString[i]])
        {
            ll nowSize = 0;
            while (M[oriString[i]] && i < oriString.size())
            {
                i++;
                nowSize++;
            }
            ans += nowSize*(nowSize+1)/2;
        }
    }
    cout << ans << endl;
    return 0;
}