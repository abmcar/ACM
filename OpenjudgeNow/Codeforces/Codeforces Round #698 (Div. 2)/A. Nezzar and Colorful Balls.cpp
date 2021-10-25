#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define Maxn (int) 1e6+10

using namespace std;

int t,n;
int num[Maxn];

void work()
{
    int maxn = 0;
    memset(num,0,sizeof(num));
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        num[temp]++;
        maxn = max(maxn,num[temp]);
    }
    cout << maxn << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}