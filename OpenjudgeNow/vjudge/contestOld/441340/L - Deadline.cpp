#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t;
ll d, n;

int main()
{
    // Buff;
    cin >> t;
    while (t--)
    {
        cin >> n >> d;
        // double x1 = max(0.0,(-1.0 + sqrt(1+4*d))/2);
        // double x2 = max(0.0,(-1.0 - sqrt(1+4*d))/2);
        // // cout << x1 << " " << x2;
        // int xx1 = x1;
        // int xx2 = x2;
        // ll minn = xx1 + (d+xx1/2+1)/(xx1+1);
        // minn = min(minn, xx2 + (d+xx2/2+1)/(xx2+1));
        // xx1++, xx2++;
        // minn = min(minn, xx2 + (d+xx2/2+1)/(xx2+1));
        // minn = min(minn, xx1 + (d+xx1/2+1)/(xx1+1));
        // if (minn <= n)
        //     cout << "YES" << endl;
        // else
        //     cout << "NO" << endl;
        ll minn = 1e9;
        for (int i = 0; i <= sqrt(d) + 10; i++)
            minn = min(minn,i + (d + i) / (i + 1));
        if (minn <= n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}