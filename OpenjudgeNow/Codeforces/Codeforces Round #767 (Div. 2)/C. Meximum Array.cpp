#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;

// void fun(vector<int> &nums, int end)
// {
//     // for (int it : nums)
//     //     cout << it << " ";
//     // cout << endl;
//     for (int i = 0; i < end; i++)
//         nums.erase(nums.begin());
//     // cout << "Mex:" << 0 << " " << end << endl;
// }

void work()
{
    cin >> n;
    vector<int> nums(n);
    vector<int> ans;
    unordered_map<int, int> M;
    for (int i = 0; i < n; i++)
        cin >> nums[i], M[nums[i]]++;
    int cnt = 0;
    while (cnt < n)
    {
        unordered_map<int, bool> tempM;
        int nowMex = 0;
        for (int j = cnt; j < n; j++)
        {
            tempM[nums[j]] = true;
            M[nums[j]]--;
            cnt = j + 1;
            while (tempM[nowMex])
                nowMex++;
            if (M[nowMex] == 0)
                break;
        }
        ans.push_back(nowMex);
    }
    cout << ans.size() << endl;
    for (int it : ans)
        cout << it << " ";
    cout << endl;
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