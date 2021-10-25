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
#define endl "\n"

using namespace std;

const int Maxn = 2333;
const ll Mod = 1e9+7;

ll finans = 0;
ll nowans = 0;
int nowtypes = 0;
int n;
int type[Maxn];
int value[Maxn];
map<int,ll> M;
vector<ll> V;

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> type[i];
    for(int i = 1; i <= n; i++)
        cin >> value[i];
    for(int i = 1; i <= n; i++)
        M[type[i]] = value[i];
    for(map<int,ll>::iterator i = M.begin(); i != M.end(); i++)
        V.push_back(i->second);
    sort(V.begin(),V.end());
    for(int i = V.size()-1; i >= 0; i--)
    {
        nowans += V[i];
        nowtypes++;
        ll nextans =  nowtypes * nowans;
        if(nextans < finans)
            break;
        finans = nextans;
    }
    cout << finans << endl;
    return 0;
}