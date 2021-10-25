#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
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

map<int,bool> M;
ll n;

int main()
{
    Buff;
    ll k = 1;
    for(; k <= 1e9; k++)
    {
        if(k*(k+1)/2 > 1e9)
            break;
        M[k*(k+1)/2] = true;
        // cout << k*(k+1)/2 << endl;
    }
    // cout << M.size() << endl;
    cin >> n;
    for(map<int,bool>::iterator i = M.begin(); i != M.end(); i++)
    {
        // cout << i->first << " " << n-(i->first) << " " <<  M[n-(i->first)] << endl;
        if(n-(i->first) < i->first)
            break;
        if(M[n-i->first] == true)
        {
            // cout << i->first << endl;
            cout << "YES";
            return 0;
        }
    }
    // cout << M.size() << endl;
    cout << "NO";
    return 0;
}