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

const int Maxn = 1e5+10;

int n;
int num[Maxn];
vector<int> temp;
ll ans;

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        temp.push_back(i);
    }
    for(int i = 1; i < n; i++)
    {
        ll pos = upper_bound(temp.begin(),temp.end(),num[i]) - temp.begin();
        ll tempans = pos;
        if(*(temp.begin() + pos - 1) == num[i])
            tempans--;
        ans += tempans;
        temp.erase(pos+temp.begin()-1);
    }
    cout << ans;
    return 0;
}