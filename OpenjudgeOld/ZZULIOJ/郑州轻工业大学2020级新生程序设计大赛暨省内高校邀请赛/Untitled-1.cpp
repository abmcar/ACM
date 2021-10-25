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

string S;

int main()
{
    Buff;
    cin >> S;
    if(S[S.size()-1] == '0' && (S[S.size()-2]-'0') % 2 == 0)
    {
        cout << "0";
        return 0;
    }
    return 0;
}