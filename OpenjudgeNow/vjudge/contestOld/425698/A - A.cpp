#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

string s1,s2;
int ans;

int main()
{
    Buff;
    while(cin >> s1)
    {
        ans = 0;
        if(s1 == "#")
            break;
        cin >> s2;
        for(int i = 0; i < s1.size()-s2.size()+1; i++)
        {
            string temp = s1.substr(i,s2.size());
            if(temp == s2)
            {
                ans++;
                i = i + s2.size()-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}