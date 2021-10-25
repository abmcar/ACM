#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 5e3 + 55;
char s[N][N];
char a[N][N];
const int add = 20;
int n = 70 + add, m = 70 + add;
int in(int x, int y, int stx, int sty, int edx, int edy)
{
    if (stx <= x && x <= edx && sty <= y && y <= edy)
        return 1;
    return 0;
}
void print(int n, int m)
{
    for (int i = n; i >= add; i--)
    {
        for (int j = add; j <= m; j++)
        {
            printf("%c", a[i][j]);
        }
        puts("");
    }
    puts("");
}
char solve(ll y, ll x)
{
    if (x <= 31 && y <= 15)
        return a[y + add][x + add];
    for (ll i = 5; i <= 60; i++)
    {
        ll len = (1ll << i);
        if (x < (1ll << i) && y < (1ll << (i - 1)))
        {
            //if(x==32 && y==0) printf("IN1 %lld\n",len);
            ll stx = 0, sty = 0;
            ll edx = len / 2 - 1, edy = len / 4 - 1;
            if (in(x, y, stx, sty, edx, edy))
                return solve(y - sty, x - stx);
            //if(x==32 && y==0) printf("IN2\n");
            stx = len / 2, sty = 0;
            edx = len - 1, edy = len / 4 - 1;
            if (in(x, y, stx, sty, edx, edy))
                return solve(y - sty, x - stx);
            //if(x==32 && y==0) printf("IN3\n");
            stx = len / 4, sty = len / 4;
            edx = len / 4 + len / 2 - 1, edy = len / 2 - 1;
            if (in(x, y, stx, sty, edx, edy))
                return solve(y - sty, x - stx);
            //if(x==32 && y==0) printf("IN4\n");
            return '.';
        }
    }
}

int main()
{
    a[add][add] = 'A';
    for (int t = 2; t <= 32; t++)
    {
        int flag = 'A';
        if (!(t & 1))
        {
            flag = 'B';
        }
        for (int i = 0; i <= n + add; i++)
        {
            for (int j = 0; j <= m + add; j++)
            {
                if (i >= 1 && j >= 2)
                    if (!a[i - 1][j - 1] && a[i][j - 2] && a[i][j - 2] != flag)
                    {
                        a[i][j] = flag;
                    }
                if (i >= 1 && j >= 2)
                    if (!a[i][j - 2] && a[i - 1][j - 1] && a[i - 1][j - 1] != flag)
                    {
                        a[i][j] = flag;
                    }
            }
        }
    }
    for (int i = 0; i <= n + add; i++)
        for (int j = 0; j <= m + add; j++)
            if (!a[i][j])
                a[i][j] = '.';
    ios::sync_with_stdio(false), cin.tie(0);
    ll t, x0, y0, a, b;
    while (cin >> t >> x0 >> y0 >> a >> b)
    {
        memset(s, 0, sizeof s);
        for (ll y = 0; y < b; y++)
        {
            for (ll x = 0; x < a; x++)
            {
                s[y][x] = solve(y + y0, x + x0);
                if (s[y][x] != '.' && (y + y0 + x + x0) / 2 >= t)
                    s[y][x] = '.';
            }
        }
        for (int i = b - 1; i >= 0; i--)
            printf("%s\n", s[i]);
    }

    return 0;
}
/**
3 0 0 10 20
.....................................
...............B.....................
..............A.B....................
.............B...B...................
............A.B.A.B..................
...........B.......B.................
..........A.B.....A.B................
.........B...B...B...B...............
........A.B.A.B.A.B.A.B..............
.......B...............B.............
......A.B.............A.B............
.....B...B...........B...B...........
....A.B.A.B.........A.B.A.B..........
...B.......B.......B.......B.........
..A.B.....A.B.....A.B.....A.B........
.B...B...B...B...B...B...B...B.......
A.B.A.B.A.B.A.B.A.B.A.B.A.B.A.B......

1000000000000 1000000000000 1000000000000 0 50

2 0 0 10 10
*/
