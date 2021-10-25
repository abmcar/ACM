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

const int Maxn = 1e5+10;
const ll Mod = 1e9+7;
int n;
int l = 1;
int r;
int ans;
int mid;

map<int,int> M[Maxn];
int query(int l,int r)
{
    int temp;
    if(l >= r)
        return -1;
    if(M[l][r] != 0)
        return M[l][r];
    cout << "? " << l << " " << r << endl;
    cin >> temp;
    M[l][r] = temp;
    return temp;
}

bool check(int l,int r,int mid)
{
    if(mid == query(l,r))
        return true;
    return false;
}

int main()
{
    Buff;
    cin >> n;
    r = n;
    int p = query(l,r);
    if(p > 1 && query(1,p) == p)
    {
        l = 1;
        r = p;
        while(l < r)
        {
            mid = (l+r+1)/2;
            if(query(mid,p) == p)
                l = mid;
            else
                r = mid-1;
        }
        cout << "! " << l;
    }else
    {
        l = p;
        r = n;
        while(l < r)
        {
            mid = (l+r)/2;
            if(query(p,mid) == p)
                r = mid;
            else
                l = mid+1;
        }
        cout << "! " << l;
    }
    return 0;
}