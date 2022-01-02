#include <stdio.h>
#include <string.h>

int ne[1234];

// KMP
char *findc(char const *source, char const *obj)
{
    // 初始化两串,使其下标从1开始,方便kmp处理
    char p[1234] = "-";
    char s[1234] = "-";
    strcat(p, obj);
    strcat(s, source);
    int n = strlen(obj);
    int m = strlen(source);
    // 初始化ne数组
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    // 找匹配位置
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
            return source + (i - n);
    }
    printf("Can not find\n");
    return NULL;
}

int main()
{
    char temp1[1234];
    char temp2[1234];
    scanf("%s %s", temp1, temp2);
    printf("%s\n", findc(temp1, temp2));
    return 0;
}