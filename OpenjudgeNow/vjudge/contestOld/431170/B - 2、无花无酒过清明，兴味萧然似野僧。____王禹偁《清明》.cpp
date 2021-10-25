#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
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

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int n;
ll temp;
unordered_map<ll,bool> M,M1;
ll jc[25];

// bool dfs(ll num)
// {
//     if (num == 1)
//         return true;
//     if (M[num])
//         return true;
//     if (M1[num])
//         return false;
//     int str = upper_bound(jc+1,jc+21,num) - jc;
//     for (int i = 2; i <= str; i++)
//         if (num % jc[i] == 0)
//         if (!M1[num/jc[i]])
//             if(dfs(num/jc[i]))
//             {
//                 M[num] = true;
//                 return true;
//             }
//     // M1[num] = true;
//     return false;
// }

vector<ll> V;

int main()
{
    Buff;
    // freopen("b2.out","w",stdout);
    cin >> n;
    jc[0] = 1;
    for (int i = 1; i <= 20; i++)
        jc[i] = jc[i-1] * i, V.push_back(jc[i]);
    for (int i = 2; i <= 20; i++)
    {
        for (int j = 0; j < V.size(); j++)
        {
            ll k =  jc[i];
            M[V[j]] = true;
            while (log10(k)+log10(V[j]) <= 18)
            {
                if(M[k*V[j]])
                    break;
                M[k*V[j]] = true;
                V.push_back(k*V[j]);
                // cout << k * V[j] << " " << k << endl;
                k *= jc[i];
                if(log10(k)+log10(V[j]) > 18)
                    break;
            }
        }
        // unique(V.begin(),V.end());
    }
    // sort(V.begin(),V.end());
    // for (int i = 0; i < V.size(); i++)
    // {
    //     // cout << "M[" << V[i] << "] = true;" << endl;
    // }
    for (int i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        if (M[temp])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } 
    // for (ll i = n; i >= 1; i--)
    // {
    //     temp = i;
    //     if (dfs(temp))
    //     {
    //         cout << "M[" << i << "] = true;" << endl;
    //     }
    //     // else
    //     //     cout << "NO" << endl;
    // }
    return 0;
}