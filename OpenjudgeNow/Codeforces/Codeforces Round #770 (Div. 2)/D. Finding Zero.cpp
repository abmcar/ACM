#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
// #define endl "\n"
// #define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;
int lastAns;
int lastOut;
unordered_map<int, bool> used;

int query(int i, int j, int k)
{
    cout << "? " << i << " " << j << " " << k << endl;
    cin >> lastAns;
    return lastAns;
}

void answer(int i, int j)
{
    cout << "! " << i << " " << j << endl;
}

void solve(vector<int> &nowNum)
{
    vector<pair<int, int>> nowAns(4);
    vector<int> newNum;
    nowAns[0] = {query(nowNum[1], nowNum[2], nowNum[3]), nowNum[0]};
    nowAns[1] = {query(nowNum[0], nowNum[2], nowNum[3]), nowNum[1]};
    nowAns[2] = {query(nowNum[1], nowNum[0], nowNum[3]), nowNum[2]};
    nowAns[3] = {query(nowNum[1], nowNum[2], nowNum[0]), nowNum[3]};
    sort(nowAns.begin(), nowAns.end());
    for (int i = 0; i < 4; i++)
        if (nowAns[0].second == nowNum[i] || nowAns[1].second == nowNum[i])
            newNum.push_back(nowNum[i]);
        else
            lastOut = nowNum[i];
    nowNum = newNum;
}

void work()
{
    used.clear();
    cin >> n;
    vector<int> nowNum;
    nowNum.push_back(1);
    nowNum.push_back(2);
    nowNum.push_back(3);
    nowNum.push_back(4);
    solve(nowNum);
    for (int i = 5; i <= n; i++)
    {
        nowNum.push_back(i);
        if (nowNum.size() == 4)
            solve(nowNum);
    }
    if (nowNum.size() == 3)
    {
        nowNum.push_back(lastOut);
        solve(nowNum);
    }
    // for (auto it : nowNum)
    //     cout << it << " ";
    // cout << endl;
    answer(nowNum[0], nowNum[1]);
}

signed main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}