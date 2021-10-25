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
int n;

void work()
{
    cin >> n;
    map<int,int> M;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        M[temp]++;
    }
    int maxn = 0;
    for(map<int,int>::iterator it = M.begin(); it != M.end(); it++)
        maxn = max(maxn,it->second);
    if(n-maxn >= maxn)
    {
        if(n % 2 == 0)
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }
    else
        cout << n-2*(n-maxn) << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}