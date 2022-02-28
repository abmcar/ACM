#include <bits/stdc++.h>

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

string oriS;
int nowd;
map<char, char> M;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    M['C'] = '1';
    M['D'] = '2';
    M['E'] = '3';
    M['F'] = '4';
    M['G'] = '5';
    M['A'] = '6';
    M['B'] = '7';
    cin >> oriS;
    for (int i = 0; i < oriS.size(); i++)
    {
        if (oriS[i] == '<')
            nowd++;
        else if (oriS[i] == '>')
            nowd--;
        else
        {
            cout << M[oriS[i]];
            for (int j = 1; j <= abs(nowd); j++)
                cout << "*."[nowd > 0];
        }
    }
    return 0;
}