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

int num[10];
int premutation[10];
int ans;
map<int, bool> M;

void test(int t1, int t2, int t3, int t4)
{
    for (int i1 = 1; i1 <= 3; i1++)
        for (int i2 = 1; i2 <= 3; i2++)
            for (int i3 = 1; i3 <= 3; i3++)
            {
                int nowNum = 0;
                {
                    if (i1 == 1)
                        nowNum = t1 + t2;
                    if (i1 == 2)
                        nowNum = t1 - t2;
                    if (i1 == 3)
                        nowNum = t1 * t2;
                }
                {
                    if (i2 == 1)
                        nowNum += t3;
                    if (i2 == 2)
                        nowNum = nowNum - t3;
                    if (i2 == 3)
                    if (i1 == 3)
                        nowNum *= t3;
                    else
                    {
                        if (i1 == 1)
                            nowNum = t1 + t2 * t3;
                        else
                            nowNum = t1 - t2 * t3;
                    }
                }
                {
                    if (i3 == 1)
                        nowNum += t4;
                    if (i3 == 2)
                        nowNum = nowNum - t4;
                    if (i3 == 3)
                    if (i1 == 3 && i2 == 3)
                        nowNum *= t4;
                    else
                    {
                        if (i1 == 3)
                        {
                            if (i2 == 1)
                                nowNum = t1 * t2 + t3 * t4;
                            else
                                nowNum = t1 * t2 - t3 * t4;
                        }else
                        if (i2 == 3)
                        {
                            if (i1 == 1)
                                nowNum = t1 + t2 * t3 * t4;
                            else
                                nowNum = t1 - t2 * t3 * t4;
                        }else
                        if (i1 == 1)
                        {
                            if (i2 == 1)
                                nowNum = t1 + t2 + t3 * t4;
                            else
                                nowNum = t1 + t2 - t3 * t4;
                        }else
                        if (i2 == 2)
                        {
                            if (i2 == 1)
                                nowNum = t1 - t2 + t3 * t4;
                            else
                                nowNum = t1 - t2 - t3 * t4;
                        }
                    }
                }
                // if (nowNum == 0)
                //     cout << "!" << endl;
                if (nowNum < 0)
                    continue;
                if (!M[nowNum])
                {
                    M[nowNum] = true;
                    ans++;
                    // cout << nowNum << endl;
                    // cout << t1 << " " << t2 << " " << t3 << " " << t4 << endl;
                }
            }
}

void test(int t1, int t2, int t3)
{
    for (int i1 = 1; i1 <= 3; i1++)
        for (int i2 = 1; i2 <= 3; i2++)
        {
            int nowNum = 0;
            {
                if (i1 == 1)
                    nowNum = t1 + t2;
                if (i1 == 2)
                    nowNum = t1 - t2;
                if (i1 == 3)
                    nowNum = t1 * t2;
            }
            {
                if (i2 == 1)
                    nowNum += t3;
                if (i2 == 2)
                    nowNum = nowNum - t3;
                if (i2 == 3)
                if (i1 == 3)
                    nowNum *= t3;
                else
                {
                    if (i1 == 1)
                        nowNum = t1 + t2 * t3;
                    else
                        nowNum = t1 - t2 * t3;
                }
            }
            if (nowNum < 0)
                continue;
            if (!M[nowNum])
            {
                M[nowNum] = true;
                ans++;
                // cout << nowNum << endl;
            }
        }
}

void test(int t1, int t2)
{
    for (int i1 = 1; i1 <= 3; i1++)
    {
        int nowNum = 0;
        {
            if (i1 == 1)
                nowNum = t1 + t2;
            if (i1 == 2)
                nowNum = t1 - t2;
            if (i1 == 3)
                nowNum = t1 * t2;
        }
        if (nowNum < 0)
            continue;
        if (!M[nowNum])
        {
            M[nowNum] = true;
            ans++;
            // cout << nowNum << endl;
        }
    }
}

int main()
{
    Buff;
    for (int i = 1; i <= 4; i++)
        cin >> num[i], premutation[i] = i;
    while (next_permutation(premutation + 1, premutation + 5))
    {
        test(num[premutation[1]], num[premutation[2]], num[premutation[3]], num[premutation[4]]);
        test(num[premutation[1]] * 10 + num[premutation[2]], num[premutation[3]], num[premutation[4]]);
        test(num[premutation[1]] * 10 + num[premutation[2]], num[premutation[3]] * 10 + num[premutation[4]]);
        test(num[premutation[1]] * 100 + num[premutation[2]] * 10 + num[premutation[3]], num[premutation[4]]);
    }
    cout << ans << endl;
    return 0;
}