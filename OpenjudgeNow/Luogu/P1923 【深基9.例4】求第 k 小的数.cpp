#include <iostream>
#include <algorithm>
#include <vector>
#define ll int
using namespace std;
#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF : *pa++

static char buf[100000], *pa = buf, *pd = buf;
inline ll re()
{
    register int x(0);
    register char c(gc);
    while (c < '0' || c > '9')
        c = gc;
    while (c >= '0' && c <= '9')
        x = (x << 1) + (x << 3) + (c ^ 48), c = gc;
    return x;
}

static ll arr[5000100];
ll n, k;

void quickSort(ll l, ll r)
{
    if (l >= r)
        return;
    ll nowl = l - 1;
    ll nowr = r + 1;
    ll baseNum = arr[(l + r) / 2];
    while (nowl < nowr)
    {
        do
            nowl++;
        while (arr[nowl] < baseNum);
        do
            nowr--;
        while (arr[nowr] > baseNum);
        if (nowl < nowr)
            swap(arr[nowl], arr[nowr]);
    }
    quickSort(l, nowr), quickSort(nowr + 1, r);
}

int main()
{
    // std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // cin >> n >> k;
    n = re();
    k = re();
    for (ll i = 1; i <= n; i++)
        arr[i] = re();
    // cin >> num[i];
    // nth_element(num+1,num+k+1,num+n+1);
    quickSort(1, n);
    cout << arr[k + 1];

    return 0;
}