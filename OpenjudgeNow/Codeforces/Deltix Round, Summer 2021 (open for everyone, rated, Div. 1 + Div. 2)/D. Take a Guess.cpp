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
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const ll Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

ll n, k;

ll nu[Maxn];
ll num1[Maxn], num2[Maxn];
ll oriNum;
ll oriNum1;

ll getNum(ll pos)
{
    ll tempNum = num1[pos];
    for (ll i = 0; (1<<i) <= tempNum; i++)
        if (tempNum & (1<<i))
        {
            if (num2[pos] & (1<<i))
                continue;
            if (oriNum & (1<<i))
                tempNum = tempNum - (1 << i);
        }
    return tempNum;
}

int main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    ll nums[] = {0,1,6,4,2,3,4,4};
    cin >> n >> k;
    for (ll i = 1; i < n; i++)
    {
        cout << "or " << i << " " << i+1 << endl;
        cin >> num1[i];
        // num1[i] = nums[1] | nums[i];
        cout << "and " << i << " " << i+1 << endl;
        // num2[i] = nums[1] & nums[i];
        cin >> num2[i];
        nu[i] = num1[i] + num2[i];
    }
    // oriNum1 = num1[2];
    // for (ll i = 3; i <= n; i++)
    //     oriNum1 = oriNum1 & num1[i];
    // ll oriNum2 = num2[2];
    // for (ll i = 2; i <= n; i++)
    //     oriNum2 = oriNum2 | num2[i];
    // oriNum = oriNum1 & oriNum2;
    int t1, t2;
    cout << "and 1 3" << endl;
    cin >> t1;
    cout << "or 1 3" << endl;
    cin >> t2;
    // t1 += t2;
    vector<ll> Nums;
    Nums.push_back((nu[1]-nu[2]+t1+t2)/2);
    for (int i = 2; i <= n; i++)
        Nums.push_back(nu[i-1]-Nums[i-2]);
    // Nums.push_back(oriNum);
    // for (ll i = 2; i <= n; i++)
    //     Nums.push_back(getNum(i));
    sort(Nums.begin(),Nums.end());
    cout << "finish "<< Nums[k-1] << Endl;
    // cout << oriNum << endl;
    // cout << (1 << 10);
    return 0;
}