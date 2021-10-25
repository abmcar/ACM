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

int t;
ll n,m;
bool fir;
bool sed;

int main()
{
    Buff;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        fir = false;
        sed = false;
        if(n % 3 == 0)
            fir = 1;
        if(m % 2 == 0)
            sed = 1;
        if(fir)
        {
            if(!sed)
            {
                cout << "Alice" << endl;
                continue;
            }
        }else
        {
            if(sed)
            {
                cout << "Alice" << endl;
                continue;
            }
        }
        n--;
        fir = false;
        sed = false;
        if(n % 3 == 0)
            fir = 1;
        if(m % 2 == 0)
            sed = 1;
        if(fir)
        {
            if(!sed)
            {
                cout << "Bob" << endl;
                continue;
            }
        }else
        {
            if(sed)
            {
                cout << "Bob" << endl;
                continue;
            }
        }
        cout << "Alice" << endl;
    }
    return 0;
}
/*
0 b
1 a
2 a
3 b
4 a

*/