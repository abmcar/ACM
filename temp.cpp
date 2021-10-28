#include <stdio.h>
int main()
{
    int n;
    char a[105];
    gets(a);
    n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == ' ' && a[i + 1] != ' ')
        {
            a[i + 1] -= 32;
            printf("%c", a[i]);
        }
        else
            printf("%c", a[i]);
    }

    return 0;
}