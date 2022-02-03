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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int n, m;
vector<string> s;
unordered_map<string, int> bd[Maxn];
string sql;
string temp = "SELECT COUNT(*) FROM Table GROUP BY ";

signed main()
{
    // cout << temp.size() << endl;
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    s.resize(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> bd[i][s[j]];
    string ts;
    while (cin >> ts)
        sql = sql + " " + ts;
    // cout << sql << endl;
    sql = sql.erase(0, 37);
    sql = sql.erase(sql.size() - 1);
    // cout << sql << endl;
    vector<string> targetS;
    int nowPos = 0;
    do
    {
        if (sql.find(",") == string::npos)
        {
            targetS.push_back(sql);
            break;
        }
        string nowS = sql.substr(nowPos, sql.find(","));
        sql = sql.erase(0, sql.find(",") + 1);
        targetS.push_back(nowS);
        if (sql.find(",") == string::npos)
            targetS.push_back(sql);
    } while (sql.find(",") != string::npos);
    vector<int> nowV[Maxn];
    map<vector<int>, int> ans;
    for (int i = 1; i <= n; i++)
    {
        for (string nowS : targetS)
            nowV[i].push_back(bd[i][nowS]);
        ans[nowV[i]]++;
    }
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it.second << " ";
    // vector<string> a, b;
    // a.push_back("123321");
    // a.push_back("123");
    // b.push_back("123");
    // b.insert(b.begin(), "123321");
    // cout << (a == b) << endl;
    return 0;
}