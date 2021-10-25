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
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

stack<int> num;
stack<char> op;

unordered_map<char, int> h{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval()
{
    int a = num.top();
    num.pop();

    int b = num.top();
    num.pop();

    char p = op.top();
    op.pop();

    int r = 0;

    if (p == '+')
        r = b + a;
    if (p == '-')
        r = b - a;
    if (p == '*')
        r = b * a;
    if (p == '/')
        r = b / a;

    num.push(r);
}

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + s[j] - '0';
                j++;
            }
            num.push(x);
            i = j - 1;
        }

        else if (s[i] == '(')
        {
            op.push(s[i]);
        }

        else if (s[i] == ')')
        {
            while (op.top() != '(')
                eval();
            op.pop();
        }
        else
        {
            while (op.size() && h[op.top()] >= h[s[i]])
                eval();
            op.push(s[i]);
        }
    }
    while (op.size())
        eval();
    cout << num.top() << endl;
    return 0;
}
