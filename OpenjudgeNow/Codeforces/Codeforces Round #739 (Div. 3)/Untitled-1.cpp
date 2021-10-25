#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Buff std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define lowbit(x) (x & (-x))
#define ls (rt * 2)
#define rs (rt * 2 + 1)
const int mod = 1000000007;
const int MAXN = 1e5 + 10;
const double eps = 1e-8;
//=====================================

#define ll int
using namespace std;
ll n, m, t;
vector<ll> v[2005];
int main()
{
    freopen("2.txt", "w", stdout);
    //Buff;
    clock_t c1 = clock();
    v[1].emplace_back(0);
    ll i, j;
    for (i = 2; i <= 700; i++)
    {
        v[i].emplace_back(0);
        for (j = i - 1; j >= 1; j--)
        {
            ll x = j * (i - j);
            v[i].emplace_back(x);
            for (auto w : v[j])
                v[i].emplace_back(x + w);
        }
        ll p = 0;
        ll x = i - 1;
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
        if(i%100==0)
        {
            cerr << "Time Used:" << clock() - c1 << "ms" << endl;
        }
        if (i==677||i==678||i==699||i == 700)
            for (auto w : v[i])
            {
                cout << w << " ";
                p=1;
            }
            if(p)cout<<endl;
    }
    // cin>>t;
    // while(t--)
    // {
    //     cin>>n;
    //     for(auto w:v[n])
    //         cout<<w<<" ";
    //     cout<<endl;
    // }
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
