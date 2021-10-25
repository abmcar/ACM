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

int t, n;

void work()
{
    cin >> n;
    map<int,int> M1,M2;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (M1[temp] == 0)
            M2[temp] = i;
        M1[temp]++;
    }
    for (map<int,int>::iterator it = M1.begin(); it != M1.end(); it++)
    {
        if (it->second == 1)
            cout << M2[it->first] << endl;
    }
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}