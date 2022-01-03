#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define LL long long
using namespace std;

const int N = 1000010;
char a[N];
int nxt[N];
int sum[N];

void get_nxt()
{
    int k = 0;
    int l = strlen(a);
    for (int i = 1; i < l; i++)
    {
        while (k && a[i] != a[k])
            k = nxt[k - 1];
        if (a[i] == a[k])
            k++;
        nxt[i] = k;
    }
}

int find(int nowNum)
{
    // cout << nowNum << " " << nxt[nowNum-1] << endl;
    if (nxt[nowNum-1] == 0)
        return nowNum;
    nxt[nowNum-1] = find(nxt[nowNum-1]);
    return nxt[nowNum-1];
}

int main()
{
    int l;
    cin >> l >> a;
    get_nxt();
    int k = 0;
    LL sum = 0;
    LL tot = 0;
    for (int i = 1; i <= l; i++)
    {
        // sum = i;
        // int m = i;
        // while (m)
        // {
        //     if (nxt[m - 1] == 0)
        //         break;
        //     sum = nxt[m - 1];
        //     m = nxt[m - 1];
        // }
        // cout << i-sum << endl;
        int temp = find(i);
        cout << i << " " << temp << endl;
        tot += i-temp;
    }
    cout << tot;

    return 0;
}
