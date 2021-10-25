#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define Maxn (int)1e6+10
#define ll long long

using namespace std;

int n;
char t1[Maxn],t2[Maxn];
int maxn;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    maxn = n;
    for(int i = 1; i <= n; i++)
        cin >> t1[i];
    for(int i = 1; i <= n; i++)
        cin >> t2[i];
    for(int i = 1; i <= n; i++)
        if(t1[i] == t2[i])
            maxn++;
    cout << maxn << " 0";
    return 0;
}