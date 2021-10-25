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
// #include <unordered_map>
// #include <unordered_set>
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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

stack<String> s1, s2;

class Browser
{
private:
    stack<String> frontStack, backStack;
    String nowUrl = "Null";
    static String IGNORED;
    bool nowUrlIsEmpty()
    {
        if (nowUrl == "Null")
            return true;
        return false;
    }

    bool frontStackIsEmpty()
    {
        if (frontStack.empty())
            return true;
        return false;
    }

    bool backStackIsEmpty()
    {
        if (backStack.empty())
            return true;
        return false;
    }

    void frontStackClear()
    {
        while (!frontStack.empty())
            frontStack.pop();
    }

public:
    Browser()
    {
        IGNORED = "Ignored";
    }

    String back()
    {
        if (backStackIsEmpty())
            return IGNORED;
        frontStack.push(nowUrl);
        nowUrl = backStack.top();
        backStack.pop();
        return nowUrl;
    }

    String forward()
    {
        if (frontStackIsEmpty())
            return IGNORED;
        backStack.push(nowUrl);
        nowUrl = frontStack.top();
        frontStack.pop();
        return nowUrl;
    }

    String visit(String url)
    {
        if (!nowUrlIsEmpty())
            backStack.push(nowUrl);
        nowUrl = url;
        frontStackClear();
        return nowUrl;
    }
};

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    Browser browser;
    // browser.visit("http://www.acm.org/");
    String opt;
    while (cin >> opt)
    {
        if (opt == "BACK")
            cout << browser.back() << endl;
        else if (opt == "FORWARD")
            cout << browser.forward() << endl;
        else if (opt == "VISIT")
        {
            String newUrl;
            cin >> newUrl;
            cout << browser.visit(newUrl) << endl;
        }else if (opt == "QUIT")
            break;
    }
    return 0;
}