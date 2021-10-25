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
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e4+10;
const ll Mod = 1e9+7;
int n;
bool islucky[Maxn];

void prework()
{
    queue<int> tempnum;
    tempnum.push(4);
    tempnum.push(7);
    while(!tempnum.empty())
    {
        int nownum = tempnum.front();
        tempnum.pop();
        if(nownum > 1000)
            continue;
        int nextnum1 = nownum*10 + 4;
        int nextnum2 = nownum*10 + 7;
        tempnum.push(nextnum1);
        tempnum.push(nextnum2);
        int base = nownum;
        while(nownum <= 1000)
        {
            islucky[nownum] = true;
            nownum += base;
        }
    }
}

int main()
{
    Buff;
    prework();
    cin >> n;
    if(islucky[n] == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}