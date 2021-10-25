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
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int t;
string a,b;

void work()
{
    cin >> a >> b;
    int strSize = min(a.size(),b.size());
    for(int i = strSize; i >= 1; i--)
    {
        string tempa, tempb;
        for(int j = 0; j < a.size() - i + 1; j++)
        {
            tempa = a.substr(j,i);
            for(int k = 0; k < b.size() - i + 1; k++)
            if(b[k] == a[j])
            {
                tempb = b.substr(k,i);
                if(tempa == tempb)
                {
                    cout << a.size()+b.size()-2*i << endl;
                    return;
                }
            }
        }
    }
    cout << a.size()+b.size() << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}