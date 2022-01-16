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

void work()
{
    string s;
    cin >> s;
    vector<int> nums;
    for (char it : s)
        nums.push_back(it - '0');
    int pos = 0;
    for (int i = s.size() - 1; i >= 1; i--)
    {
        int nowNum = nums[i] + nums[i - 1];
        if (nowNum >= 10)
        {
            pos = i - 1;
            break;
        } 
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (pos == i)
        {
            cout << nums[i] + nums[i + 1];
            i++;
        }
        else
            cout << nums[i];
    }
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