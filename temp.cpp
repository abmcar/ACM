#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    vector<pair<int,int>> tempV;
    tempV.push_back({1,2});
    tempV.push_back({2,3});
    for_each(tempV.begin(),tempV.end(),[](pair<int,int> x){
        cout << x.first << endl;
    });
    return 0;
}