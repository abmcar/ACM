#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n;
struct cow
{
    int v,x;
}cows[22222];

bool cmp(cow a,cow b)
{
    return a.v < b.v;
}

long long prex[22222];
long long ans;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> cows[i].v >> cows[i].x;
    sort(cows+1,cows+1+n,cmp);
    for(int i = 1; i <= n; i++)
        prex[i] = prex[i-1]+cows[i].x;
    for(int i = n; i >= 1; i--)
    for(int j = 1; j < i; j++)
        ans += cows[i].v * std::abs(cows[j].x-cows[i].x);
    cout << ans;
    return 0;
}