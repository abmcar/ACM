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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int t, n;
int ans;
string inputStrings[Maxn];
int inputX[Maxn], inputY[Maxn];

int getAns(string originString)
{
    if (originString.size() == 4)
        return 0;
    int temp = 0;
    for (int i = 4; originString[i] != ')'; i++)
    {
        temp *= 10;
        temp += originString[i] - '0';
    }
    return temp;
}

void init()
{
    string ansString;
    cin >> n >> ansString;
    ans = getAns(ansString);
    string temp;
    cin >> temp;
    for (int i = 1; i <= n; i++)
        getline(cin, inputStrings[i]);
    inputStrings[1] = temp + inputStrings[1];
    for (int i = 1; i <= n; i++)
    {
        if (inputStrings[i][0] == 'F')
        {
            if (inputStrings[i][4] == 'n')
            {
                inputX[i] = -1;
                int temp = 0;
                if(inputStrings[i][6] == 'n')
                {
                    inputY[i] = -1;
                    continue;
                }
                for (int j = 6; j < inputStrings[i].size(); j++)
                {
                    temp *= 10;
                    temp += inputStrings[i][j] - '0';
                }
                inputY[i] = temp;
            }
            else
            {
                int temp = 0;
                int j;
                for (j = 4; inputStrings[i][j] != ' '; j++)
                {
                    temp *= 10;
                    temp += inputStrings[i][j] - '0';
                }
                inputX[i] = temp;
                // cout << temp << " ";
                if (inputStrings[i][inputStrings[i].size() - 1] == 'n')
                    inputY[i] = -1;
                else
                {
                    j++;
                    temp = 0;
                    for(; j < inputStrings[i].size(); j++)
                    {
                        temp *= 10;
                        temp += inputStrings[i][j] - '0';
                    }
                    inputY[i] = temp;
                }
                // cout <<temp <<endl;
            }
        }
    }
}

void clear()
{
    // memset(inputStrings,0,sizeof(inputStrings));
    memset(inputX, 0, sizeof(inputX));
    memset(inputY, 0, sizeof(inputY));
}

bool isERR()
{
    if (n % 2 == 1)
        return false;
    stack<char> S;
    map<char, bool> M;
    for (int i = 1; i <= n; i++)
    {
        if (inputStrings[i][0] == 'F')
        {
            // cout << M[inputStrings[i][2]] << endl;
            if (M[inputStrings[i][2]] == true)
                return false;
            S.push(inputStrings[i][2]);
            M[inputStrings[i][2]] = true;
        }
        else
        {
            if (S.empty())
                return false;
            M[S.top()] = false;
            // cout << S.top() << endl;
            S.pop();
        }
    }
    if (!S.empty())
        return false;
    return true;
}

bool check()
{
    int nowAns = 0;
    bool isEnd = false;
    stack<int> S;
    for (int i = 1; i <= n; i++)
    {
        if (inputStrings[i][0] == 'E')
        {
            S.pop();
        }
        else
        {
            if (inputX[i] != -1 && inputY[i] != -1)
            {
                if(inputX[i] > inputY[i])
                {
                    S.push(-1);
                    continue;
                }
                if (S.empty())
                    S.push(0);
                else
                    S.push(S.top());
                continue;
            }
            if(inputX[i] == -1 && inputY[i] == -1)
            {
                if (S.empty())
                    S.push(0);
                else
                    S.push(S.top());
                continue;
            }
            if (inputX[i] == -1)
            {
                S.push(-1);
                continue;
            }
            else
            {
                if (S.empty())
                {
                    S.push(1);
                    nowAns = max(nowAns, 1);
                    continue;
                }
                if (S.top() == -1)
                    S.push(-1);
                else
                    S.push(S.top() + 1);
                nowAns = max(nowAns, S.top());
            }
        }
    }
    if (ans == nowAns)
        return true;
    // cout << ans << " " << nowAns << endl;
    return false;
}

void work()
{
    clear();
    init();
    if (!isERR())
    {
        cout << "ERR" << endl;
        return;
    }
    if (check())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}