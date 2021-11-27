#include <stdio.h>

int runnian(int m)
{
    if ((m % 4 == 0 && m % 100 != 0) || m % 400 == 0)
    {
        return 1;
    }
    return 0;
}

int sum(int a, int b, int c)
{
    int sum = 0, i;
    int r[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int p[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int k = 1970; k <= a; k++)
    {
        if (runnian(k))
        {
            for (i = 0; i < b - 1; i++)
            {
                sum += r[i];
            }
        }
        else
        {
            for (i = 0; i < b - 1; i++)
            {
                sum += p[i];
            }
        }
    }
    sum += c;
    return sum;
}

int sum1, sum2;

int main()
{
    int y1, y2, m1, m2, d1, d2;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d-%d-%d", &y1, &m1, &d1);
        scanf("%d-%d-%d", &y2, &m2, &d2);
        printf("%d %d\n",y1,y2);
        // m1 = -m1, m2 = -m2, d1 = -d1, d2 = -d2;
        sum1 = sum(y1, m1, d1);
        sum2 = sum(y2, m2, d2);
        printf("%d %d\n", sum1, sum2);
        if (sum2 == sum1)
            printf("Today\n");
        else if (sum2 - sum1 == 1)
            printf("Yesterday\n");
        else if (y1 == y2)
        {
            if (m1 < 10)
                printf("0");
            printf("%d-", m1);
            if (d1 < 10)
                printf("0");
            printf("%d ", d1);
            printf("%d days ago\n", sum2 - sum1);
        }
        else
        {
            if (y1 < 10)
                printf("0");
            printf("%d-", y1);
            if (m1 < 10)
                printf("0");
            printf("%d-", m1);
            if (d1 < 10)
                printf("0");
            printf("%d ", d1);
            if ((y1 % 4 == 0 && y1 % 100 != 0) || y1 % 400 == 0)
                printf("%d days ago\n", sum2 - sum1 + 365);
            else
                printf("%d days ago\n", sum2 - sum1 + 364);
        }
    }
}
/* 
1
2019-02-27 2021-04-01
2370-03-21 2370-03-27
 */