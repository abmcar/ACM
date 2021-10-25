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
int t,n,k;

void work()
{
    cin >> n >> k;
    int nowa,nowb;
    int num1[Maxn],num2[Maxn],preans[Maxn];
    memset(preans,0,sizeof(preans));
    nowa = n;
    nowb = 1;
    preans[0] = 0;
    if(n % 2 == 1)
    {
        int multiple = n/2;
        int tempnum = (k-1)/multiple;
        k = k + tempnum;
    }
    if(k % n == 0)
        cout << n << endl;
    else
        cout << k%n << endl;
    for(int i = 1; i <= k; i++)
    {
        if(nowa == nowb)
            nowb++,preans[i] = 1;
        preans[i] += preans[i-1];
        if(nowb == n+1)
            nowb = 1;
        num1[i] = nowa--;
        num2[i] = nowb++;
        if(nowb == n+1)
            nowb = 1;
        if(nowa == 0)
            nowa = n;
    }
    for(int i = 1; i <= k; i++)
        cout << num1[i] << " ";
    cout << endl;
    for(int i = 1; i <= k; i++)
        cout << num2[i] << " ";
    cout << endl;
    for(int i = 1; i <= k; i++)
        cout << preans[i] << " ";
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
5 4 3 2 1 5 4 3 2 1 5 4 3 2 1 5 4 3 2 1
1 2 4 5 2 3 5 1 3 4 2 3 4 5 2 3
0 0 1 1 2 2 3 3 4 4 5 5 5 5 6
*/