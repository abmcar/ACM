#include <stdio.h>

void work()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int nowNum = 1;
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += (1 << (nowNum-1));
        temp++;
        if (temp == nowNum)
        {
            temp = 0;
            nowNum++;
        }
    }
    printf("%d\n",cnt);
}

int main()
{

    for (int i = 1; i <= 30; i++)
        work();
    return 0;
}
