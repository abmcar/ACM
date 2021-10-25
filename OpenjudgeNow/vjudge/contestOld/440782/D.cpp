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
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t;
map<int,int> M;
int n, m;
string s1, s2, s3;
int ans;

// void dfs(int deep, int pos, int now)
// {
//     // cout << deep << " " << pos << " " << now << endl;
//     if (deep == s3.size())
//     {
//         ans = min(ans,now);
//         return;
//     }
//     for (int i = pos; i < s1.size(); i++)
//         if (s1[pos] == s3[deep])
//             dfs(deep+1,i,now+s2[pos]-'0');
// }

void work()
{
    // ans = 1e5;
    map<char,int> M;
    map<char,bool> MM;
    cin >> n >> m;
    cin >> s1 >> s2 >> s3;
    ans = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        // cout << MM[s1[i]] << endl;
        if (!MM[s1[i]])
        {
            MM[s1[i]] = true;
            M[s1[i]] = (s2[i] - '0');
            // cout << M[s1[i]] << endl;
        }else
        {
            M[s1[i]] = min(M[s1[i]], (s2[i] - '0'));
        }
    }
    for (int i = 0; i < s3.size(); i++)
    if(!MM[s3[i]])
    {
        ans += 1e5;
        break;
    }else
        ans += M[s3[i]];
    
    // dfs(0,0,0);
    if (ans >= 1e5)
        ans = -1;
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}