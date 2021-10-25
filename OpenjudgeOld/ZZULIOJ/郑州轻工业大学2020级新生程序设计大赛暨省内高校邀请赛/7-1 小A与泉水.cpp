#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

ll base[64];
bool check(int num)
{
    for(int i = 1; i <= 32; i++)
        if(base[i] == num)
            return true;
    return false;
}

int getLow(int num)
{
    if(check(num))
        return -1;
    int temp = 1;
    while(num != 0)
    {
        if(num % 2 == 1)
            break;
        temp++;
        num = num/2;
    }
    return temp;
}


// int getAns(int num)
// {
//     int temp = 0;
//     if(check(num))
//         return 0;
//     while(!check(num))
//     {
//         // cout << num << " " << getLow(num) << " " <<base[getLow(num)] << endl;
//         num += base[getLow(num)];
//         temp++;
//     }
//     return temp;
// }

int getAns(ll num)
{
    int temp = 0;
    while(!check(num))
    {
        temp++;
        for(int i = 32; i >= 1; i--)
        {
            if(base[i] > num)
                continue;
            if(num % base[i] == 0)
            {
                num = num + base[i];
                break;
            }
        }
    }
    return temp;
}

int t;

int main()
{
    Buff;
    base[1] = 1;
    for(int i = 2;  base[i-1] <= 2e9; i++)
        base[i] = base[i-1] * 2;
    cin >> t;
    while(t--)
    {
        ll temp;
        cin >> temp;
        cout << getAns(temp) << endl;
    }
    return 0;
}
/*

1 0
2 0
3 1
4 0
5 2
6 1
7 1
8 0
9 3
10 2
11 2
12 1
13 2
14 1
15 1
16 0

*/