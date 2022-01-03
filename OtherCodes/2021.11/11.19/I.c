#include <stdio.h>

int n, m;
int a[100005], b[100005], s[100005], t[100005];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &a[i], &s[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d %d", &b[i], &t[i]);
    s[n + 1] = t[m + 1] = -1e9;
    int nowPos1, nowPos2;
    nowPos1 = nowPos2 = 1;
    while (nowPos1 <= n || nowPos2 <= m)
    {
        if (s[nowPos1] < t[nowPos2])
        {
            printf("%d %d ", b[nowPos2], t[nowPos2]);
            nowPos2++;
            continue;
        }
        if (s[nowPos1] > t[nowPos2])
        {
            printf("%d %d ", a[nowPos1], s[nowPos1]);
            nowPos1++;
            continue;
        }
        if (a[nowPos1] + b[nowPos2] != 0)
            printf("%d %d ", a[nowPos1] + b[nowPos2], t[nowPos2]);
        nowPos1++;
        nowPos2++;
    }
    return 0;
}
/* 
3 2
6 3 3 2 9 1
-6 3 -5 1

 */