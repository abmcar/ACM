#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int t;

void work()
{
    string temp;
    int finx,finy;
    int u,d,r,l;
    int rightn = 0;
    cin >> finx >> finy;
    cin >> temp;
    u = d = r = l = 0;
    for(int i = 0; i < temp.size(); i++)
    {
        if(temp[i] == 'U')
            u++;
        if(temp[i] == 'D')
            d--;
        if(temp[i] == 'R')
            r++;
        if(temp[i] == 'L')
            l--;
    }
    if(finx >= 0)
    {
        if(r >= finx)
            rightn++;
    }else
    {
        if(l <= finx)
            rightn++;
    }
    if(finy >= 0)
    {
        if(u >= finy)
            rightn++;
    }else
    {
        if(d <= finy)
            rightn++;
    }
    if(rightn == 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
        work();
    return 0;
}