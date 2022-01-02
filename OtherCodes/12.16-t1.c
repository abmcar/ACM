#include <stdio.h>

int n;
int ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp % 2 == 0 && temp % 3 == 0 && temp % 5 == 0)
            ans++;
    }
    printf("%d", ans);
    return 0;
}