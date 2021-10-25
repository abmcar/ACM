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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int q;
string s1, s2;
vector<int> V1,V2;
void work()
{
    cin >> s1 >> s2;
    int nowPos2 = 0;
    int nowPos1 = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 1; i+j <= s1.size(); j++)
        {
            string nowS = s1;
            string tempS = s1;
            nowS = nowS.substr(i,j);
            tempS = tempS.substr(0,i+j-1);
            reverse(tempS.begin(),tempS.end());
            // cout << nowS << " " << tempS << endl;
            string finS = nowS + tempS;
            // cout << finS << Endl;
            if (finS.find(s2) != string::npos)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> q;
    while (q--)
        work();
    return 0;
}