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

int t, n;
struct Athlete
{
    int r1, r2, r3, r4, r5;
    int pos;
    bool const operator<(Athlete b) const
    {
        int win = 0;
        if (r1 < b.r1)
            win++;
        if (r2 < b.r2)
            win++;
        if (r3 < b.r3)
            win++;
        if (r4 < b.r4)
            win++;
        if (r5 < b.r5)
            win++;
        if (win >= 3)
            return true;
        return false;
    }
    bool const operator==(Athlete b) const
    {
        int win = 0;
        if (r1 == b.r1)
            win++;
        if (r2 == b.r2)
            win++;
        if (r3 == b.r3)
            win++;
        if (r4 == b.r4)
            win++;
        if (r5 == b.r5)
            win++;
        if (win == 5)
            return true;
        return false;
    }
    void get()
    {
        // cout << "12211";
        cin >> r1 >> r2 >> r3 >> r4 >> r5;
    }
};

void work()
{
    cin >> n;
    if (n == 1)
    {
        Athlete t;
        t.get();
        cout << 1 << endl;
        return;
    }
    vector<Athlete> V;
    for (int i = 1; i <= n; i++)
    {
        Athlete temp;
        temp.get();
        temp.pos = i;
        V.push_back(temp);
    }
    sort(V.begin(), V.end());
    Athlete maxA = V[0];
    Athlete tempA = maxA;
    for (auto i : V)
    {
        if (i < tempA)
            tempA = i;
        // tempA = max(tempA, i);
    }
    // cout << maxA.pos << " " << tempA.pos << Endl;
    if (maxA.pos == tempA.pos)
    {
        cout << maxA.pos << endl;
        return;
    }
    cout << -1 << endl;
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