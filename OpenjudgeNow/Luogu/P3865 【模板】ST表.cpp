#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define Maxn (int)1e6+10

using namespace std;

inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int Max[Maxn][23];

int Query(int l,int r)
{
    int k = log2(r-l+1);
    return max(Max[l][k],Max[r-(1<<k)+1][k]);
}

int main()
{
    int n = read();
    int m = read();
    for(int i = 1; i <= n; i++)
        Max[i][0] = read();
    for(int j = 1; j <= 21; j++)
    for(int i = 1; i+(1<<j)-1 <= n; i++)
    {
        Max[i][j] = max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
        // cout << "debug1:" << i+(1<<(j-1)) << " " << i + max(1,(j-1)*2) << " " << i << " " << j << endl;
    }
    for(int i = 1; i <= m; i++)
    {
        int l = read();
        int r = read();
        printf("%d\n",Query(l,r));
    }
    return 0;
}