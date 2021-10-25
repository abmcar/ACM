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
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

bool check1(String nowS, String nowP)
{
    String newS = nowS;
    String newP = nowP;
    if (newS[0] >= '0' && newS[0] <= '9')
    {
        newS.erase(0);
        if (newS == newP)
            return true;
    }

    return false;
}

bool check2(String nowS, String nowP)
{
    String newS = nowS;
    String newP = nowP;
    if (newS[newS.size() - 1] >= '0' && newS[newS.size() - 1] <= '9')
    {
        newS.erase(newS.size() - 1);
        // cout << newS << endl;
        // newP = newP  newS[newS.size()-1];
        if (newS == newP)
            return true;
    }
    return false;
}

bool check3(String nowS, String nowP)
{
    String newS = nowS;
    String newP = nowP;
    for (int i = 0; i < newS.size(); i++)
    {
        if (newS[i] >= 'a' && newS[i] <= 'z')
            newS[i] += 'A' - 'a';
        else if (newS[i] >= 'A' && newS[i] <= 'Z')
            newS[i] += 'a' - 'A';
    }
    // cout << newS << endl;
    if (newS == newP)
        return true;
    return false;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    String s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2 || check1(s1, s2) || check2(s1, s2) || check3(s1, s2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}