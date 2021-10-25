#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#define Maxn (int)1e6+10
#define ll long long

using namespace std;

int k;
int leftn,rightn;
int nowans;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> k;
    if(k == 0)
    {
        cout << "(";
        return 0;
    }
    leftn = rightn = sqrt(k);
    nowans = leftn*rightn;
    if(nowans == k)
    {
        for(int i = 1; i <= leftn; i++)
            cout << "(";
        for(int i = 1; i <= leftn; i++)
            cout << ")";
        return 0;
    }
    while((k-nowans)<leftn)
    {
        leftn--;
        nowans = leftn*rightn;
    }
    for(int i = 1; i <= leftn; i++)
        cout << "(";
    for(int i = 1; i <= rightn; i++)
        cout << ")";
    for(int i = 1; i+leftn+nowans <= k; i++)
        cout << "(";
    cout << ")";
    // cout << leftn+rightn+k-leftn-nowans;
    return 0;
}
/*0
l*r+(l+1)*a1 = k
l*r + (r+1)*a1 + (l+1)*a2 = k;
()()((()
*/