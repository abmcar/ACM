#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;
int d1, m1, y1;
int d2, m2, y2;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int day, int month, int year)
{
    if (month < 1 || month > 12 || d1 > days[month] + int(month == 2 && year % 4 == 0) || d1 < 0)
        return false;
    return (year + 18 < y1 || year + 18 == y1 && m1 < m1 || year + 18 == y1 && month == m1 && day <= d1);
}

int main()
{
    Buff;
    scanf("%d. %d. %d", &d1, &m1, &y1);
    scanf("%d. %d. %d", &d2, &m2, &y2);
    return 0;
}