#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug
#define int long long

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

vector<int> nums[10];
vector<int> totN;

bool isPrime(ll num)
{
    if (num == 1)
        return false;
    for (ll i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

void pre()
{
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
            if (isPrime(i + j))
                nums[i].push_back(j);
    }
}

void dfs(int nowNum, int ok1)
{
    if (nowNum > 20000000000LL)
        return;
    if (ok1)
        totN.push_back(nowNum);
    for (int i = 0; i < nums[nowNum % 10LL].size(); i++)
    {
        if (nums[nowNum % 10][i] == 1LL)
            dfs(nowNum * 10LL + 1LL, true);
        else
            dfs(nowNum * 10LL + nums[nowNum % 10LL][i], ok1);
    }
}

int getNum(int x)
{
    if (x == 0)
        return 0;
    int pos = lower_bound(totN.begin(), totN.end(), x) - totN.begin();
    while (totN[pos] > x)
        pos--;
    // if (totN[pos] != x)
    pos++;
    return pos;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    pre();
    dfs(1, true);
    for (int i = 2; i <= 9; i++)
        dfs(i, false);
    sort(totN.begin(), totN.end());
    int l, r;
    for (int i = 0; i <= 9; i++)
    {
        cout << i << "   ";
        for (auto it : nums[i])
            cout << it << " ";
        cout << endl;
    }
    cin >> l >> r;
    // cout << getNum(l) << endl;
    // cout << getNum(r) << endl;
    cout << getNum(r) - getNum(l - 1) << endl;
    // for (auto it : totN)
    // {
    //     if (it > 100)
    //         break;
    //     cout << it << endl;
    // }
    // cout << totN.size() << endl;
    return 0;
}