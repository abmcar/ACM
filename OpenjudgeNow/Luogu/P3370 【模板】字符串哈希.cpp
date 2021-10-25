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
// import <iostream>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod1 = 1234567897;
const ll Mod2 = 9876543213;
const ll prime = 2015105601;
const ll base = 131;

struct Hash
{
    ll val1, val2;
    bool const operator<(Hash b) const
    {
        return val1 < b.val1;
    }
    bool const operator==(Hash b) const
    {
        return (val1 == b.val1) && (val2 == b.val2);
    }
} hashs[Maxn];

ll getHash1(string temp)
{
    ll hash1 = 0;
    for (int i = 0; i < temp.size(); i++)
        hash1 = hash1 * base % Mod1 + temp[i] + prime;
    return hash1;
}

ll getHash2(string temp)
{
    ll hash2 = 0;
    for (int i = 0; i < temp.size(); i++)
        hash2 = hash2 * base % Mod2 + temp[i] + prime;
    return hash2;
}

int n, ans;
string tempString;
int main()
{
    Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tempString;
        hashs[i].val1 = getHash1(tempString);
        hashs[i].val2 = getHash2(tempString);
    }
    sort(hashs + 1, hashs + 1 + n);
    for (int i = 1; i <= n; i++)
        if (hashs[i] == hashs[i - 1])
            continue;
        else
            ans++;
    cout << ans;
    return 0;
}