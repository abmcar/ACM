#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

const int Maxn = 3e5+10;

int n,m;
int num[Maxn];

int main()
{
    Buff;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = 1; i <= m; i++)
    {
        int l,r,k;
        cin >> l >> r >> k;
        vector<int> V;
        for(int j = l; j <= r; j++)
            V.push_back(num[j]);
        sort(V.begin(),V.end());
        cout << V[V.size()-k] << endl;
    }
    return 0;
}