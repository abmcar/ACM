#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>

#define ll long long

using namespace std;

const int Maxn = 1234;
const ll Mod = 1e9+7;
int n;
int bd[Maxn][Maxn];

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            if((i+j)%2 == 1)
                cout << "1";
            else
                cout << "0";
        cout << endl;
    }
    return 0;
}