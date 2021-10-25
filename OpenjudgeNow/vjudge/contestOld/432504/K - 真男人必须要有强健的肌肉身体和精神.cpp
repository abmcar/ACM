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

int t;
string originString;
map<char,int> M;

bool check()
{
    stack<int> S;
    for (int i = 0; i <= originString.size()-1; i++)
    {
        int nowNum = M[originString[i]];
        // cout << nowNum << " " << originString[i] << "  ";
        if (nowNum == 1)
            S.push(1);
        else
        {
            if (S.empty())
                return false;
            S.pop();
        }
    }
    // cout << endl;
    if (S.empty())
        return true;
    return false;
    
}

void work()
{
    M.clear();
    cin >> originString;
    M[originString[0]] = 1;
    int cnt = originString.size()-1;
    while (originString[0] == originString[cnt] && cnt > 0)
        cnt--;
    M[originString[cnt]] = -1;
    // cout << cnt << " !!! " << originString[cnt] << " " << M[originString[cnt]] << endl;
    if (M['A'] == 0)
    {
        // cout << 'Q' << endl;
        M['A'] = 1;
        if (check())
        {
            cout << "YES" << endl;
            return;
        }
        M['A'] = -1;
        if (check())
        {
            cout << "YES" << endl;
            return;
        }
    }
    if (M['B'] == 0)
    {
        M['B'] = 1;
        if (check())
        {
            cout << "YES" << endl;
            return;
        }
        M['B'] = -1;
        if (check())
        {
            cout << "YES" << endl;
            return;
        }
    }
    if (M['C'] == 0)
    {
        M['C'] = 1;
        if (check())
        {
            cout << "YES" << endl;
            return;
        }
        M['C'] = -1;
        if (check())
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}