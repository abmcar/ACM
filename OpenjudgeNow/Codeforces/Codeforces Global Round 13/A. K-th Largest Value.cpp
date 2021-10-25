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

const int Maxn = 1e5+10;
const ll Mod = 1e9+7;
int n,q;
int t;
int num[Maxn];
int num1;

int main()
{
    Buff;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        if(num[i] == 1)
            num1++;
    }
    for(int i = 1; i <= q; i++)
    {
        int opt;
        int pos;
        cin >> opt >> pos;
        if(opt == 1)
        {
            if(num[pos] == 1)
            {
                num[pos] = 0;
                num1--;
            }else
            {
                num[pos] = 1;
                num1++;
            }
        }else
        {
            if(num1 >= pos)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}
