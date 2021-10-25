#include <iostream>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

const int Maxn = 3e6 + 10;

int n, m, k;
int templ, tempr;
int num[Maxn], num1[Maxn];
unordered_map<int, int> ans;
vector<int> tempa;

struct Node
{
    int l, r, k, pos;
    bool const operator<(Node b) const
    {
        ll t1 = l / k;
        ll t2 = b.l / k;
        if (t1 != t2)
            return t1 < t2;
        return r < b.r;
    }
} node[Maxn];

int main()
{
    cin >> n >> m;
    k = sqrt(m);
    tempa.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int tempNum;
        cin >> tempNum;
        tempa.push_back(tempNum);
    }
    for (int i = 1; i <= m; i++)
        cin >> node[i].l >> node[i].r >> node[i].k, node[i].pos = i;
    sort(node + 1, node + m + 1);
    templ = node[1].l, tempr = node[1].r;
    for (int i = templ; i <= tempr; i++)
    {
        num1[num[tempa[i]]]--;
        num[tempa[i]]++;
        num1[num[tempa[i]]]++;
    }
    ans[node[1].pos] = num1[node[1].k];
    for (int i = 2; i <= m; i++)
    {
        int nowPos = node[i].pos;
        while (templ > node[i].l)
        {
            templ--;
            num1[num[tempa[templ]]]--;
            num[tempa[templ]]++;
            num1[num[tempa[templ]]]++;
        }
        while (tempr < node[i].r)
        {
            tempr++;
            num1[num[tempa[tempr]]]--;
            num[tempa[tempr]]++;
            num1[num[tempa[tempr]]]++;
        }
        while (templ < node[i].l)
        {
            num1[num[tempa[templ]]]--;
            num[tempa[templ]]--;
            num1[num[tempa[templ]]]++;
            templ++;
        }
        while (tempr > node[i].r)
        {
            num1[num[tempa[tempr]]]--;
            num[tempa[tempr]]--;
            num1[num[tempa[tempr]]]++;
            tempr--;
        }
        ans[nowPos] = num1[node[i].k];
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}