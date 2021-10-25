#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll Maxn = 1e5 + 10;

int tot;

int main()
{
    cin >> tot;
    srand(0);
    cout << rand()%tot+1;
}