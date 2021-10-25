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

int x,y;

bool isprime(int num)
{
    for(int i = 2; i*i <= num; i++)
        if(num % i == 0)
            return false;
    return true;
}

int main()
{
    Buff;
    while(cin >> x >> y)
    {
        if(x == 0 && y == 0)
            break;
        bool ok = true;
        for(int i = x; i <= y; i++)
            if(!isprime(i*i+i+41))
                ok = false;
        if(ok)
            cout << "OK" << endl;
        else
            cout << "Sorry" << endl;
    }
    return 0;
}