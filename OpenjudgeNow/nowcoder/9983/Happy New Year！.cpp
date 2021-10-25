#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int a;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> a;
    if(a % 10 != 0)
        a += 9;
    else
        a = 2102;
    cout << a;
    return 0;
}