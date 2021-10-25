#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;
int num[Maxn];
int f[Maxn];
int n;
vector<int> vn[Maxn];
int pos[Maxn];

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i], vn[num[i]].push_back(i), pos[i] = vn[num[i]].size() - 1;
    for (int i = 2; i <= n; i++)
        if(pos[i] == 0)
            f[i] = f[i-1];
        else
            f[i] = max(f[i - 1], f[vn[num[i]][pos[i] - 1]] + 1);
    cout << f[n];
    return 0;
}
/*
f[n] = f[n-1] + 1
       f[n-1]
      
*/