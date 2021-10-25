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

const int Maxn = 1e4 + 10;
const ll Mod = 1e9 + 7;

int n;
int num[Maxn];
int pos[Maxn];

int msort(int l, int r)
{
    int ans = 0;
    int mid = (l + r) / 2;
    if (l == r)
        return;
    msort(l, mid);
    msort(mid + 1, r);
    int leftstr = l;
    int rightstr = mid + 1;
    int endstr = l;
    int tempnum[522222];
    for (int i = l; i <= r; i++)
        tempnum[i] = num[i];
    while (leftstr <= mid && rightstr <= r)
    {
        if (num[leftstr] > num[rightstr])
        {
            ans += mid - leftstr + 1;
            tempnum[endstr++] = num[rightstr];
            rightstr++;
        }
        else
        {
            tempnum[endstr++] = num[leftstr];
            leftstr++;
        }
    }
    while (leftstr <= mid)
    {
        tempnum[endstr++] = num[leftstr];
        leftstr++;
    }
    while (rightstr <= r)
    {
        tempnum[endstr++] = num[rightstr];
        rightstr++;
    }
    for (int i = l; i <= r; i++)
        num[i] = tempnum[i];
    return ans;
}

void work()
{
    int Ans = 1e9;
    queue<int> Q, oriQ;
    vector<int> numV, onumV;
    for (int i = 1; i <= n; i++)
        cin >> num[i], Q.push(num[i]);
    Ans = min(Ans, msort(1, n));
    oriQ = Q;
    Q.push(Q.front());
    Q.pop();
    while (Q != oriQ)
    {
        for (int i = 1; i <= n; i++)
            
    }
    

}

int main()
{
    Buff;
    while (cin >> n)
        work();
    return 0;
}