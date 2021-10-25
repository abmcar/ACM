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

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
ll posX[Maxn],posY[Maxn];
int t;
int n;

void work()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> posX[i] >> posY[i];
    sort(posX+1,posX+1+n);
    sort(posY+1,posY+1+n);
    ll leftX,leftY,rightX,rightY,numX,numY;
    
    leftX = posX[((n+1)/2)];
    leftY = posY[((n+1)/2)];
    if(n%2 == 0)
    {
        rightX = posX[(n+2)/2];
        rightY = posY[(n+2)/2];
    }else
    {
        rightY = leftY;
        rightX = leftX;
    }
    numX = rightX - leftX + 1;
    numY = rightY - leftY + 1;
    // cout << "test:" << leftX << " " << rightX << " " << leftY << " " << rightY << " " << numX << " " << numY << "\n";
    cout << numX*numY << "\n";
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}