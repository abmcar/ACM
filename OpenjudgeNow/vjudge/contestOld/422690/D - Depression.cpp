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

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int strHour = 0;
int strMinute = 0;
int endHour;
int endMinute;
double angleHour,angleMinute;

int main()
{
    Buff;
    scanf("%d:%d",&endHour,&endMinute);
    if(endHour < 12)
        strHour = 0;
    else
        strHour = 12;
    angleHour = (endHour-strHour)*((double)360/12);
    angleMinute = (endMinute-strMinute)*((double)360/60);
    angleHour += (double)endMinute/60/12*360;
    cout << angleHour << " " << angleMinute << endl;
    return 0;
}