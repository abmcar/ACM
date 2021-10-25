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

int n;
int ans;

void work()
{
    ans = 0;
    vector<int> V;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        V.push_back(temp);
    }
    while (V.size() != 0)
    {
        if (V.size() == 1)
        {
            ans += V[0];
            break;
        }
        int nowMin = 1e9;
        for (int i = 0; i < V.size(); i+=2)
        {
            if (V[i] == 0)
                continue;
            if (i == V.size()-1)
                continue;
            nowMin = min(nowMin, V[i]);
        }
        ans += nowMin;
        for (int i = 0; i < V.size(); i+=2)
        {
            if (V[i] == 0)
                continue;
            if (i == V.size()-1)
                continue;
            V[i] = V[i] - nowMin;
        }
        // for (auto it = V.begin(); it != V.end();)
        // {
        //     if (*it == 0)
        //         V.erase(it);
        //     else
        //         it++;
        // }
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    while (cin >> n && n)
        work();
    return 0;
}