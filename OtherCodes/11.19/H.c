#include <stdio.h>
#include <stdlib.h>

int n;
int borad[11000][11000];

void work(int strx, int stry, int num)
{
    if (num == 1)
    {
        borad[strx][stry] = 0;
        borad[strx + 1][stry] = 1;
        borad[strx + 1][stry + 1] = 1;
        borad[strx][stry + 1] = 1;
        return;
    }
    int l = 1;
    for (int i = 1; i <= num - 1; i++)
        l = l * 2;
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= l; j++)
            borad[strx + i][stry + j] = 0;
    work(strx + l, stry + l, num - 1);
    work(strx, stry + l, num - 1);
    work(strx + l, stry, num - 1);
}

void put()
{
    int finl = 1;
    for (int i = 1; i <= n; i++)
        finl = finl * 2;
    for (int i = 1; i <= finl; i++)
    {
        for (int j = 1; j <= finl; j++)
            printf("%d ",borad[i][j]);
        printf("\n");
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        work(1, 1, n);
        put();
        printf("\n");
        for (int i = 1; i <= 2048; i++)
        for (int j = 1; j <= 2048; j++)
            borad[i][j] = 0;
    }
    return 0;
}