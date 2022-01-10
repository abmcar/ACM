#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
#define tALL(v) v.begin(), v.end()
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;
int t, n, m;

void work()
{
    cin >> n;
    vector<int> nums(n);
    vector<int> unuse, targetNum;
    map<int, bool> M;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (!M[nums[i]] && nums[i] <= n)
            M[nums[i]] = true;
        else
            unuse.push_back(nums[i]);
    }
    sort(tALL(unuse));
    for (int i = 1; i <= n; i++)
    {
        if (M[i])
            continue;
        targetNum.push_back(i);
    }
    // cout << unuse.size() << " " << targetNum.size() << endl;
    for (int i = 0; i < unuse.size(); i++)
    {
        int nowNum = unuse[i];
        int tarNum = targetNum[i];
        if ((nowNum-1) / 2 < tarNum)
        {
            cout << "-1" << endl;
            return;
        }
    }
    cout << unuse.size() << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}