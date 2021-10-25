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
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

map<string,bool> s1,s2,s;
int n,m;
int now = 1;

int main()
{
    Buff;
    cin >> n >> m;
    // cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++)
    {
        string tempString;
        cin >> tempString;
        s1[tempString] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        string tempString;
        cin >> tempString;
        s2[tempString] = true;
    }
    int n1 = s1.size();
    int n2 = s2.size();
    for (auto i = s1.begin(); i != s1.end(); i++)
    {
        if (s2[i->first] == true)
        {
            if(now == 1)
            {
                now = 2;
                n2--;
            }else
            {
                now = 1;
                n1--;
            }
        
        }
    }
    if (n1 > n2) 
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}