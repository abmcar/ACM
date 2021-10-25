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
#include <unordered_map>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int num[Maxn];
unordered_map<int,int> M1, M2;
int nowPos = 1;

struct Quest
{
    int p, x;
    bool const operator< (Quest b) const
    {
        return p < b.p;
    }
}quest[Maxn];

int main()
{
    Buff;
    // cout << (1 xor 5) << endl;
    cin >> n >> m;
    for (int i = 1; i <= Maxn; i++)
    {
        M1[(1 xor i)] = i;
        M2[(2 xor i)] = i;
    }
    for (int i = 1; i <= m; i++)
        cin >> quest[i].p >> quest[i].x;
    sort(quest+1, quest+1+m);
    quest[0].p = 1;
    for (int i = 1; i <= m; i++)
    {
        int nowP = quest[i].p;
        int nowX = quest[i].x;
        // if (quest[i-1].x == 0)
        // {
        //     for (int j = nowPos; j < nowP-1; j++)
        //         num[j] = 1, quest[i-1].x = quest[i-1].x xor 1;
        // }
        if (nowX == 0)
        {
            if (quest[i-1].x == 0)
                if ((nowP - quest[i-1].p + 1) % 2 == 1)
                {
                    cout << "-1" << endl;
                    return 0;
                }else
                {
                    for (int i = nowPos; i <= nowP; i++)
                        num[i] = 1;
                    nowPos = nowP + 1;
                    continue;
                }
            if ((nowP - quest[i-1].p) % 2 == 1)
            {
                cout << "-1" << endl;
                return 0;
            }else
            {
                num[nowPos] = quest[i-1].x;
                for (int i = nowPos+1; i <= nowP; i++)
                    num[i] = 1;
                nowPos = nowP + 1;
                continue;
            }
        }
        if (nowP == nowPos)
        {
            // cout << "#1 " << nowP << endl;
            if (quest[i-1].x == 0)
            {
                num[nowPos] = nowX;
                nowPos = nowP+1;
                continue;
            }
            int temp = 1;
            bool ok = false;
            while(temp xor quest[i-1].x < nowX + 10)
            {
                if (temp xor quest[i-1].x == nowX)
                {
                    ok = true;
                    num[nowP] = temp;
                    nowPos = nowP+1;
                    break;
                }
                temp++;
            }
            if (!ok)
            {
                cout << "-1" << endl;
                return 0;
            }
        }
        if ((nowP - nowPos + 1) % 2 == 0 && quest[i-1].x != 0)
        {
            // cout << "#2 " << nowP << " " << nowPos << endl;
            num[nowPos] = quest[i-1].x;
            for (int j = nowPos+1; j < nowP; j++)
                num[j] = 1;
            num[nowP] = nowX;
            nowPos = nowP+1;
        }else
        {
            // cout << "#3 " << nowP << " " << nowPos << " " << quest[i-1].x << endl;
            if (quest[i-1].p == 0)
            {
                if (M1[nowX] != 0)
                    quest[i-1].x = 1;
                else
                if (M2[nowX] != 0)
                    quest[i-1].x = 2;
                else
                {
                    cout << "-1" << endl;
                    return 0;
                }
            }
            num[nowPos] = quest[i-1].x;
            for (int j = nowPos+1; j < nowP-1; j++)
                num[j] = 1;
            if (M1[nowX] != 0)
            {
                num[nowP-1] = 1;
                num[nowP] = M1[nowX];
                nowPos = nowP+1;
                continue;
            }
            if (M2[nowX] != 0)
            {
                num[nowP-1] = 1;
                num[nowP] = M2[nowX];
                nowPos = nowP+1;
                continue;
            }
            cout << "-1" << endl;
            return 0;
        }
    }
    for (int i = nowPos; i <= n; i++)
        num[i] = 1;
    for (int i = 1; i <= n; i++)
        cout << num[i] << " ";
    return 0;
}