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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int q;
string s, t;

bool check(int strPos, int deep)
{
    if (s.size() - strPos < t.size() - deep)
        return false;
    if ((s.size() - strPos - t.size() + deep) % 2 == 0)
        return false;
    int nowPos = deep;
    int finPos;
    if (nowPos >= t.size())
    {
        if ((s.size() - strPos) % 2 == 0)
            return false;
        return true;
    }
    for (int i = strPos + 1; i < s.size(); i++)
    {
        if (s.size() - i < t.size() - nowPos)
            return false;
        if (nowPos < t.size())
        if (s[i] == t[nowPos])
        {
            int temp;
            vector<int> V;
            for (int j = i; j < s.size(); j+=2)
                if (s[j] == t[nowPos])
                    V.push_back(j), temp = j;
            for (int j = 0; j < V.size(); j++)
                if (check(V[j], nowPos + 1))
                    return true;
            i = temp;
            nowPos++;
            finPos = i;
            continue;
        }
        i++;
    }
    if (nowPos == t.size())
    {
        if ((s.size() - finPos) % 2 == 0)
            return false;
        return true;
    }
    return false;
}

void work()
{
    cin >> s >> t;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == t[0])
    //     {
            if (check(0,0))
            {
                cout << "YES" << Endl;
                return;
            }
    //         break;
    //     }
    // }
    cout << "NO" << endl;
    // bool firChar = true;
    // bool flag = false;
    // int nowPos = 0;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == t[nowPos])
    //     {
    //         firChar = false;
    //         nowPos++;
    //         // i++;
    //         // cout << i << endl;
    //         if (nowPos == t.size())
    //         {
    //             // cout << "1111" << endl;
    //             if ((s.size() - i) % 2 == 1)
    //                 flag = true;
    //         }
    //     }
    //     else
    //     if (!firChar)
    //         i++;
    // }
    // firChar = true;
    // flag = false;
    // nowPos = 0;
    // for (int i = 1; i < s.size(); i++)
    // {
    //     if (s[i] == t[nowPos])
    //     {
    //         firChar = false;
    //         nowPos++;
    //         // i++;
    //         // cout << i << endl;
    //         if (nowPos == t.size())
    //         {
    //             // cout << "1111" << endl;
    //             if ((s.size() - i) % 2 == 1)
    //                 flag = true;
    //         }
    //     }
    //     else
    //     if (!firChar)
    //         i++;
    // }
    // if (flag)
    //     cout << "YES" << Endl;
    // else
    //     cout << "NO" << endl;
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