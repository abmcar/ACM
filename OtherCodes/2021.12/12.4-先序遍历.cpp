#include <bits/stdc++.h>

using namespace std;

int node[1234];
int nums[4321];
int tot[1234];
bool ok[1234];
int n, m;
int ans;

inline int lc(int x)
{
    return x * 2;
}

inline int rc(int x)
{
    return x * 2 + 1;
}

void build(int pos, int nowDeep)
{
    if (!nums[++m])
        return;
    node[pos] = nums[m];
    n = max(n, pos);
    build(lc(pos), nowDeep + 1);
    build(rc(pos), nowDeep + 1);
    if (node[lc(pos)] == 0 && node[rc(pos)] == 0)
        tot[nowDeep] += node[pos], ok[nowDeep] = true;
}

int main()
{
    int temp;
    int cnt = 1;
    while (cin >> temp)
        nums[cnt++] = temp;
    build(1, 0);
    int nowAns = -1e9;
    for (int i = 1; i <= 1234; i++)
        if (tot[i] >= nowAns && ok[i])
        {
            // cout << i << " " << tot[i] << endl;
            nowAns = tot[i];
            ans = i;
        }
    cout << ans << endl;
    return 0;
}
