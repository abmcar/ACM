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

vector<int> t[10];

int main()
{
    Buff;
    int now = 49;
    int nowfir = 1;
    for(int i = 1; i <= 7; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            t[i].push_back(now);
            now--;
        }
        for(int j = 1; j <= 3; j++)
        {
            t[i].push_back(nowfir);
            nowfir++;
        }
    }
    // for(int i = 1; i <= 7; i++)
    // {
    //     for(int j = 0; j < 7; j++)
    //         cout << t[i][j] << " ";
    //     cout << endl;
    // }
    cout << 34;
    return 0;
}