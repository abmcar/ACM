#include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

inline void read(__int128 &X)
{
	X = 0;
	int w=0; char ch=0;
	while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
	while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	if (w) X = -X;
}

void print(__int128 x)
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
    if(x > 9) print(x/10);
    putchar(x%10 + '0');
}

struct Node
{
    __int128 a,b;
    bool const operator< (Node c) const
    {
        return a*c.b+b < c.a*b+c.b;
    }
    void get()
    {
        read(a);
        read(b);
    }
}node[33];
__int128 n;
__int128 x;

int main()
{
    Buff;
    read(n);
    read(x);
    for(int i = 1; i <= n; i++)
        node[i].get();
    sort(node+1,node+1+n);
    for(int i = 1; i <= n; i++)
        x = node[i].a*x + node[i].b;
    print(x);
    return 0;
}
/*

a1(a0x+b0) + b1
a1*a0*x + a1*b0 + b1

a0(a1x+b1) + b0
a1*a0*x + a0*b1 + b0




*/