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
string s;

void work()
{
    cin >> s;
    for(int i = 0; i <= s.size(); i++)
    {
        if(i % 2 == 0)
        {
            if(s[i] == 'a')
            {
                s[i] = 'b';
                continue;
            }
            s[i] = 'a';
        }else
        {
            if(s[i] == 'z')
            {
                s[i] = 'y';
                continue;
            }
            s[i] = 'z';
        }
    }
    cout << s << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
        work();
    return 0;
}