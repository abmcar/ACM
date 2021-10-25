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

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
string temp;
int tans;

int main()
{
    Buff;
    getline(cin,temp);
    for(int i = 0; i < temp.size(); i++)
        if(temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
            tans++;
    if(tans != 5)
    {
        cout << "NO";
        return 0;
    }
    tans = 0;
    getline(cin,temp);
    for(int i = 0; i < temp.size(); i++)
        if(temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
            tans++;
    if(tans != 7)
    {
        cout << "NO";
        return 0;
    }
    tans = 0;
    getline(cin,temp);
    for(int i = 0; i < temp.size(); i++)
        if(temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
            tans++;
    if(tans != 5)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}