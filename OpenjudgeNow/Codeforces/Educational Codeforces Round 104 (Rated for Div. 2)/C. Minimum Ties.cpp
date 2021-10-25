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

const int Maxn = 1e3+10;
const ll Mod = 1e9+7;

struct Node
{
    int wins,loses,ties;
    void clear()
    {
        wins = loses = ties = 0;
    }
}node[Maxn];

int t,n;

void work()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        node[i].clear();
    for(int i = 1; i < n; i++)
    {
        int other = i + 1;
        if((n-1-node[i].ties) % 2 == 1)
        {
            cout << "0 ";
            node[i].ties++;
            node[other++].ties++;
        }
        if(i % 2 == 1)
        {
            for(;node[i].loses < ((n-1-node[i].ties)/2); node[i].loses++)
            {
                cout << "-1 ";
                node[other++].wins++;
            }
            for(;node[i].wins < ((n-1-node[i].ties)/2); node[i].wins++)
            {
                cout << "1 ";
                node[other++].loses++;
            }
        }else
        {
            for(;node[i].wins < ((n-1-node[i].ties)/2); node[i].wins++)
            {
                cout << "1 ";
                node[other++].loses++;
            }
            for(;node[i].loses < ((n-1-node[i].ties)/2); node[i].loses++)
            {
                cout << "-1 ";
                node[other++].wins++;
            }
        }
        
        
    }
    cout << endl;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}
/*
2-2-1
2-2-1

*/
