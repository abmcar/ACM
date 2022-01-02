#include <stdio.h>
#include <stdlib.h>

long long n, m;
long long bd[2010][2010];
long long ans, maxVal;

int main()
{
    scanf("%lld %lld", &n, &m);
    for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= m; j++)
        {
            scanf("%lld", &bd[i][j]);
            maxVal = maxVal > bd[i][j] ? maxVal : bd[i][j];
        }
    for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= m; j++)
        {
            if (bd[i][j] == maxVal)
                ans += i + j;
        }
    printf("%lld", ans);
    return 0;
}