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

int n, m, k;
string nums;
vector<int> colors;
unordered_map<int, int> colorMap;

int find(int color)
{
    if (colorMap[color] == color)
        return color;
    colorMap[color] = find(colorMap[color]);
    return colorMap[color];
}

void work()
{
    int strPos = 0;
    int nowPos = 0;
    int nowColor = colors[0];
    string ans = nums;
    while (nowPos < n)
    {
        // for (int i = 0; i < n; i++)
        //     cout << find(i) << " ";
        // cout << endl;
        // cout << "color " << nowPos << " " << colors[nowPos] << " " << nowColor << endl;
        if (colors[nowPos] == nowColor)
        {
            nowPos++;
            continue;
        }
        else
        {
            // cout << strPos << " " << nowPos << " " << nowColor << endl;
            sort(ans.begin() + strPos, ans.begin() + nowPos, greater<char>());
            strPos = nowPos;
            nowColor = colors[nowPos];
            nowPos++;
        }
    }
    // cout << strPos << " " << nowPos << " " << nowColor << endl;
    sort(ans.begin() + strPos, ans.begin() + nowPos, greater<char>());
    int finAns = 0;
    for (char nowChar : ans)
    {
        int nowNum = nowChar - '0';
        finAns = (finAns * 10 + nowNum) % Mod;
    }
    cout << finAns << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m >> k;
    cin >> nums;
    colors.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> colors[i];
    }
    work();
    while (k--)
    {
        int t1, t2;
        cin >> t1 >> t2;
        for (int i = 0; i < n; i++)
            if (colors[i] == t1)
                colors[i] = t2;
        work();
    }
    return 0;
}