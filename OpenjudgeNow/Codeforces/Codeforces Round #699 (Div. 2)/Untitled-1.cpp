/*
 * @Author: hesorchen
 * @Date: 2020-11-26 09:12:46
 * @LastEditTime: 2021-02-06 00:04:26
 * @Description: 栽种绝处的花
 */
#include <bits/stdc++.h>
using namespace std;

int a[100010];
int b[100010];
int c[100010];
unordered_map<int, int> mp1;
unordered_map<int, int> mp2;
int pos[100010];
int ans[100010], ct;
vector<int> vec[100010];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            pos[i] = 0;
            vec[i].clear();
        }
        mp1.clear();
        mp2.clear();
        ct = 0;

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if(vec[a[i]].size() != 0)
                vec[a[i]].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
            if(vec[b[i]].size() != 0)
                vec[b[i]].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &c[i]);
            if(vec[c[i]].size() != 0)
                vec[c[i]].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            mp2[b[i]] = 1;
            if (a[i] != b[i])
                mp1[b[i]]++;
        }
        for (int i = 1; i <= m; i++)
        {
            if (mp1.count(c[i]))
            {
                mp1[c[i]]--;
                if (mp1[c[i]] == 0)
                    mp1.erase(c[i]);
            }
        }
        if (mp1.size() || !mp2.count(c[m]))
        {
            puts("NO");
            continue;
        }

        int other;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != b[i])
                vec[b[i]].push_back(i);
            if (b[i] == c[m])
                other = i;
        }
        for (int i = 1; i <= m; i++)
        {
            if (pos[c[i]] < vec[c[i]].size())
                ans[++ct] = vec[c[i]][pos[c[i]]++];
            else
                ans[++ct] = other;
        }
        puts("YES");
        for (int i = 1; i <= ct; i++)
            printf("%d%c", ans[i], (i == ct ? '\n' : ' '));
    }
    return 0;
}