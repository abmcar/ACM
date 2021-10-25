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

const int Maxn = 1e4+10;
const ll Mod = 1e9+7;

int n,a,b;
string S;
int ans[Maxn];
char maxChar;
int maxNum;

int main()
{
    Buff;
    cin >> n >> a >> b;
    cin >> S;
    for(int i = 0; i < S.size(); i++)
        ans[S[i]]++;
    for(int i = 'A'; i <= 'Z'; i++)
    {
        // cout << ans[i] << " " << ans[i+32] << " " << (char)i << endl;
        if(maxNum < ans[i]*a+ans[i+32]*b)
        {
            maxNum = ans[i]*a+ans[i+32]*b;
            maxChar = (char)i;
        }
    }
    cout << maxChar;
    return 0;
}