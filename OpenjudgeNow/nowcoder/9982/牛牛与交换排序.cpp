#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int n;
int num[Maxn];
int nowleft;
int length;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(nowleft = 1; nowleft <= n; nowleft++)
        if(num[nowleft] == nowleft)
            continue;
        else
            break;
    if(nowleft == n+1)
    {
        cout << "yes" << endl << "1";
        return 0;
    }
    cout << nowleft << endl;
    for(int i = nowleft+1; i <= n; i++)
        if(num[i] == nowleft)
            length = i-nowleft+1;
    // cout << length << endl;
    reverse(num+nowleft,num+nowleft+length);
    // for(int i = 1; i < nowleft+length; i++)
    //     cout << num[i] << endl;
    // for(int i = nowleft; i < nowleft+length-1; i++)
    //     if(num[i] != i)
    //     {
    //         cout << i << endl;
    //         cout << "no";
    //         return 0;
    //     }
    while(nowleft + length - 1<= n)
    {
        if(num[nowleft] == nowleft)
        {
            nowleft++;
            continue;
        }
        if(num[nowleft+length-1] == nowleft)
            reverse(num+nowleft,num+nowleft+length);
        else
        {
            cout << "no";
            return 0;
        }
    }
    for(int i = 1; i <= n; i++)
        if(num[i] != i)
        {
            // cout << i << " " << num[i] << endl;
            cout << "no";
            return 0;
        }
    cout << "yes" << endl << length;
    return 0;
}