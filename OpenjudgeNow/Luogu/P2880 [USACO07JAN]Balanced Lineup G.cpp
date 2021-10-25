#include<iostream>
#include<algorithm>
#include<cmath>

#define Maxn (int)5e4+10

using namespace std;

int Max[Maxn][23];
int Min[Maxn][23];
int n,q;

int QueryMax(int l,int r)
{
    int k = log2(r-l+1);
    return max(Max[l][k],Max[r-(1<<k)+1][k]);
    //         l,l+2^k-1     r-2^k+1,r
}

int QueryMin(int l,int r)
{
    int k = log2(r-l+1);
    return min(Min[l][k],Min[r-(1<<k)+1][k]);
    //         l,l+2^k-1     r-2^k+1,r
}

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        Max[i][0] = Min[i][0] = temp;
    }
    for(int j = 1; j <= 21; j++)
    for(int i = 1; i+(1<<j)-1 <= n; i++)
    {
        Max[i][j] = max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
        Min[i][j] = min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
    }
    for(int i = 1; i <= q; i++)
    {
        int l,r;
        cin >> l >> r;
        // cout << QueryMax(l,r) << " " << QueryMin(l,r) << endl;
        cout << QueryMax(l,r)-QueryMin(l,r) << endl;
    }
    return 0;
}