#include<iostream>
#include<algorithm>
#include<cmath>
#define Maxn (int)2e5+100

using namespace std;

int n;
long long numa[Maxn];
long long numb[Maxn];
long long nowans;
long long finans = 1e10;
long long premax[Maxn];

struct score
{
    long long a,b;
};
score score1[Maxn];

bool cmp1(score ta,score tb)
{
    return ta.a < tb.a;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> numa[i];
    for(int i = 1; i <= n; i++)
        cin >> numb[i];
    for(int i = 1; i <= n; i++)
    {
        score1[i].a = numa[i];
        score1[i].b = numb[i];
    }
    sort(score1+1,score1+1+n,cmp1);
    for(int i = n; i >= 0; i--)
        premax[i] = max(premax[i+1],score1[i].b);
    for(int i = 0; i <= n; i++)
        finans = min(finans,score1[i].a+premax[i+1]);   
    cout << finans;
    return 0;
}