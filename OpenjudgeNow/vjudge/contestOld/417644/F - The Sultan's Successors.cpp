#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

int maxn = 15;
int scnum;
int x[33],d1[30],d2[45],now[33];
int scores[10][10];

void putout()
{
    int tempans = 0;
    for(int i = 1; i <= 8; i++)
        tempans += scores[i][now[i]];
    scnum = max(scnum,tempans);
}

void queen(int y)
{
    int n = 8;
    for(int i = 1; i <= n; i++)
    if(x[i] == 0 && d1[y+i] == 0 && d2[n+i-y] == 0)
    {
        x[i] = 1;
        d1[y+i] = 1;
        d2[n+i-y] = 1;
        now[y] = i;
        if(y == n) putout();
        else queen(y+1);
        x[i] = 0;
        d1[y+i] = 0;
        d2[n+i-y] = 0;
    }
}

int main()
{
    // freopen("a.out","w",stdout);
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++)
    {
        scnum = 0;
        for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            cin >> scores[i][j];
	    queen(1);
	    cout << setw(5) << scnum << endl;
    }
    return 0;
}