#include <iostream>
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

using namespace std;

const int Maxn = 55;
const ll Mod = 1e9+7;
bool isPrimes[Maxn];
bool used[Maxn];
int n,m;

int main()
{
    Buff;
    for(int i = 2; i <= Maxn; i++)
    {
        if(used[i])
            continue;
        isPrimes[i] = true;
        for(int j = i; j <= Maxn; j+=i)
            used[j] = true;
    }
    cin >> n >> m;
    if(isPrimes[m] == false)
    {
        cout << "NO" << endl;
        return 0;
    }
    for(int i = n+1; i < m; i++)
        if(isPrimes[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    return 0;
}