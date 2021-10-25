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
#include <cstddef>
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
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int sons[Maxn][26], cnt[Maxn], idx;

class Message
{
public:
    Message() {};
    String WRONG_MESSAGE = "WRONG";
    String CORRECT_MESSAGE = "OK";
    String REPEAT_MESSAGE = "REPEAT";
};

class MessageSender
{
public:
    static void SendMessage(String string)
    {
        cout << string << endl;
    }
};

void insert(String string)
{
    int nowNode = 0;
    for (char i : string)
    {
        int nextChar = i - 'a';
        if (!sons[nowNode][nextChar])
            sons[nowNode][nextChar] = ++idx;
        nowNode = sons[nowNode][nextChar];
    }
    cnt[nowNode]++;
}

int query(String string)
{
    int nowNode = 0;
    for (char i : string)
    {
        int nextChar = i - 'a';
        if (!sons[nowNode][nextChar])
            return 0;
        nowNode = sons[nowNode][nextChar];
    }
    return cnt[nowNode];
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    Message message;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        String string;
        cin >> string;
        insert(string);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        String string;
        cin >> string;
        int qAns = query(string);
        if (qAns == 0)
            MessageSender::SendMessage(message.WRONG_MESSAGE);
        if (qAns == 1)
        {
            MessageSender::SendMessage(message.CORRECT_MESSAGE);
            insert(string);
        }
        if (qAns > 1)
            MessageSender::SendMessage(message.REPEAT_MESSAGE);
    }
    return 0;
}