#include <iostream>
#include <queue>
#include <stack>
#include <map>
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

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
string luckString;
map<string,int> subString;
int maxn;
int main()
{
    Buff;
    cin >> luckString;
    int num4,num7;
    num4 = num7 = 0;
    for(int i = 0; i < luckString.size(); i++)
    {
        if(luckString[i] == '4')
            num4++;
        if(luckString[i] == '7')
            num7++;
    }
    if(num4+num7 == 0)
    {
        cout << "-1" << endl;
        return 0;
    }
    if(num4 >= num7)
        cout << "4" << endl;
    else
        cout << "7" << endl;
    return 0;
    // for(int i = 0; i < luckString.size(); i++)
    // {
    //     string nowString = "";
    //     int nowPos = i;
    //     while(luckString[nowPos] == '4' || luckString[nowPos] == '7')
    //     {
    //         nowString = nowString + luckString[nowPos];
    //         subString[nowString]++;
    //         nowPos++;
    //     }
    // }
    // for(map<string,int>::iterator it = subString.begin(); it != subString.end(); it++)
    //     maxn = max(maxn,it->second);
    // for(map<string,int>::iterator it = subString.begin(); it != subString.end(); it++)
    //     if(it->second == maxn)
    //     {
    //         cout << it->first << endl;
    //         return 0;
    //     }
    // cout << "-1" << endl;
    return 0;
}