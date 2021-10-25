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
#include <unordered_map>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 4e5 + 10;
const ll Mod = 1e9 + 7;

int t, n, k;
int a[Maxn], b[Maxn];

void work()
{

    unordered_map<int,bool> M;
    unordered_map<int, vector<int> > MV;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        M[a[i]] = true;
        MV[a[i]].push_back(i);
    }
    int totNum = 0;
    for (unordered_map<int,bool>::iterator it = M.begin(); it != M.end(); it++)
    {
        if (MV[it->first].size() >= k)
        {
            int nowCnt = 1;
            for (int i = 0; i < MV[it->first].size(); i++)
            {
                if (nowCnt == k+1)
                    break;
                // cout << "color " << nowCnt << " " << MV[it->first][i] << " " << a[MV[it->first][i]] << endl;
                b[MV[it->first][i]] = nowCnt++;
            }
        }else
            totNum += MV[it->first].size();
    }
    // for (int i = 1; i <= n; i++)
    //     cout << b[i] << " ";
    // cout << endl;
    int totTimes = totNum / k;
    // cout << "    " << totNum << " " << totTimes << " " << k << Endl;
    int nowTimes = 0;
    int nowColor = 1;
    bool isEnd = false;
    if (totTimes > 0)
    for (unordered_map<int,bool>::iterator it = M.begin(); it != M.end(); it++)
    {
        if (MV[it->first].size() < k)
        {
            for (int i = 0; i < MV[it->first].size(); i++)
            {
                b[MV[it->first][i]] = nowColor++;
                if (nowColor == k+1)
                {
                    nowColor = 1;
                    nowTimes++;
                    if (nowTimes == totTimes)
                    {
                        isEnd = true;
                        break;
                    }
                }
            }
            if (isEnd)
                break;
        }
    }
    // cout << nowColor << "      color" << endl;
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ", b[i] = a[i] = 0;
    cout << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}