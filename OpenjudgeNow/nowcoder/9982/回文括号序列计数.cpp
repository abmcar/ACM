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

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 998244353;
ll t,n;
ll ans[Maxn];

ll quickPow(ll x, ll p)
{
    ll now = 1;
    ll base = x;
    while(p != 0)
    {
        if(p % 2 == 1)
        {
            now = now * base % Mod;
            p--;
            continue;
        }
        base = base * base % Mod;
        p = p / 2;
    }
    // cout << x << endl;
    return now;
}

ll inverse(ll num)
{
    return quickPow(num,Mod-2);
}

ll getC(ll r,ll n)
{
    ll n1,n2,n3,ans;
    n1 = n2 = n3 = 1;
    for(int i = 1; i <= n; i++)
        n1 = n1 * i % Mod;
    for(int i = 1; i <= r; i++)
        n2 = n2 * i % Mod;
    for(int i = 1; i <= n-r; i++)
        n3 = n3 * i % Mod;
    ans = (n1 * inverse(n2) % Mod * inverse(n3) % Mod) % Mod;
    // cout << n << " " << r << endl;
    return ans;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n != 0)
        {
            cout << "0" << endl;
        }else
            cout << "1" << endl;
    }
    return 0;
}
/*
mgj
((((((( )))))))
()((((( )))))()
(()(((( ))))())
((()((( )))()))
(())((( )))(())
()()((( )))()()
(((()(( ))())))
()(()(( ))())()
(()()(( ))()())
((())(( ))(()))
((((()( )()))))
()((()( )()))()
(()(()( )())())
((()()( )()()))
(())()( )()(())
()()()( )()()()
(((())( )(())))
()(())( )(())()
(()())( )(()())
((()))( )((()))
(((((() ())))))
()(((() ())))()
(()((() ()))())
((()(() ())()))
(())(() ())(())
()()(() ())()()
(((()() ()())))
()(()() ()())()
(()()() ()()())
((())() ()(()))
((((()) (()))))
()((()) (()))()
(()(()) (())())
((()()) (()()))
    (())()) (()(())
    ()()()) (()()()
(((())) ((())))
    ()(())) ((())()
    (()())) ((()())
    ((()))) (((()))


(((((( ))))))
()(((( ))))()
(()((( )))())
((()(( ))()))
(())(( ))(())
()()(( ))()()
(((()( )())))
()(()( )())()
(()()( )()())
((())( )(()))
((((() ()))))
()((() ()))()
(()(() ())())
((()() ()()))
(())() ()(())
()()() ()()()
(((()) (())))
()(()) (())()
(()()) (()())
((())) ((()))


((((( )))))
()((( )))()
(()(( ))())
((()( )()))
(())( )(())
()()( )()()
(((() ())))
()(() ())()
(()() ()())
((()) (()))
    (())) ((())
    ()()) (()()

(((( ))))
()(( ))()
(()( )())
((() ()))
(()) (())
()() ()()

((( )))
()( )()
(() ())
    ()) (()

(( ))
() ()

( )
1 2 3 4 5  6  7
1 2 3 6 10 20 35
*/