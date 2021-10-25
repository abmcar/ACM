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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e8 + 10;
const ll Mod = 1e9 + 7;

bool vis[Maxn], isPrime[Maxn];
int primes[Maxn];
bool ok[Maxn];
int num[Maxn];
// vector<int> primes;
int cnt;

void getPrimes()
{
    for (int i = 2; i <= 1e8; i++)
    {
        if (!vis[i])
        {
            isPrime[i] = true;
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= 100000000/i; j++)
        {
            vis[primes[j] * i] = true;
            if (isPrime[i])
                ok[primes[j] * i] = true;
            if (i % primes[j] == 0) 
                break;
        }
        // int temp = 1;
        // // primes.push_back(i);
        // for (int j = i; j <= 1e8; j=j+i)
        // {
        //     vis[j] = true;
        //     if (isPrime[temp])
        //         ok[j] = true;
        //     temp++;
        // }
    }
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    clock_t strTime = clock();
    getPrimes();
    for (int i = 1; i <= 1e8; i++)
    {
        num[i] = num[i-1];
        if (ok[i])
            num[i]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        // cout << num[r] << endl;
        cout << num[r] - num[l-1] << endl;
    }
    // cout << primes.size() << endl;
    // cout << cnt << endl;
    // cout << clock() - strTime << endl;
    return 0;
}