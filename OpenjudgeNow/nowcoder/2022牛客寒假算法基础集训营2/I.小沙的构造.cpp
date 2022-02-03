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

int n, m;

string dc = "*+-.08:=^_WTYUIOAHXVM|<>\/[]{}()";
map<char, char> M, MM;

void pre()
{
    M['"'] = '"';
    // M['!'] = '!';
    M['\''] = '\'';
    M['*'] = '*';
    M['+'] = '+';
    M['-'] = '-';
    M['.'] = '.';
    M['0'] = '0';
    M['8'] = '8';
    M[':'] = ':';
    M['='] = '=';
    M['^'] = '^';
    M['_'] = '_';
    M['W'] = 'W';
    M['T'] = 'T';
    M['Y'] = 'Y';
    M['U'] = 'U';
    M['I'] = 'I';
    M['O'] = 'O';
    M['A'] = 'A';
    M['H'] = 'H';
    M['X'] = 'X';
    M['V'] = 'V';
    M['M'] = 'M';
    M['|'] = '|';
    MM['<'] = '>';
    MM['\\'] = '/';
    MM['['] = ']';
    MM['{'] = '}';
    MM['('] = ')';
    // MM['p'] = 'q';
    // MM['b'] = 'd';
    // MM['b'] = 'd';
}
// abcdefghijklmnopqrstuvwxyz

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    pre();
    // cout << M.size();
    // for (int i = 1; i <= )
    string ori1 = "";
    string ori2 = "";
    int cnt = 0;
    map<char, bool> us;
    if (n % 2)
        m--;
    for (auto it : MM)
    {
        if (cnt == m || cnt + 1 == m)
            break;
        us[it.first] = true;
        cnt += 2;
        ori1 = ori1 + it.first;
        ori2 = it.second + ori2;
    }
    if (cnt < m)
        for (auto it : M)
        {
            us[it.first] = true;
            cnt++;
            ori1 = ori1 + it.first;
            ori2 = it.second + ori2;
            if (cnt == m)
                break;
        }
    while (ori1.size() < n / 2)
    {
        if (us['('])
        {
            ori1 = ori1 + "(";
            ori2 = ")" + ori2;
        }
        else
        {
            ori1 = ori1 + "\"";
            ori2 = "\"" + ori2;
        }
    }
    if (n % 2)
        ori1 = ori1 + "!";
    // cout << cnt << endl;
    if (ori1.size() + ori2.size() != n || cnt != m)
        cout << -1 << endl;
    else
        cout << ori1 + ori2 << endl;
    // string s = ori1 + ori2;
    // reverse(s.begin(),s.end());
    // cout << s << endl;
    return 0;
}