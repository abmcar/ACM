#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double n;
int p1, p2;
int ans1[1234], ans2[1234];
long long cnt1, cnt2;
int ok = 1;

// 输入字符串,判断是否合法,值记录在ok里
void get()
{
    printf("Please input a num\n");
    char s[1234];
    scanf("%s", s);
    int pos = -1;
    ok = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        // 如果输入的字符串里存在非数字或者.则不合法
        if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
        {
            if (s[i] == '.')
            {
                if (pos == -1)
                    pos = i;
                else
                    ok = -1;
            }
        }
        else
            ok = -1;
    }
    // 如果不合法或者不是小数,则直接返回不合法

    if (ok == -1 || pos == -1)
    {
        ok = -1;
        printf("Error input\n");
        return;
    }
    p1 = p2 = 0;
    for (int i = 0; i < pos; i++)
        p1 = p1 * 10 + s[i] - '0';
    for (int i = pos + 1; i < strlen(s); i++)
        p2 = p2 * 10 + s[i] - '0';
    // printf("%d %d\n",p1,p2);
    if (p1 >= 1000 && p2 != 0)
    {
        ok = -1;
        printf("Error input range\n");
        return;
    }
}

// 输出16进制
void print(int x)
{
    if (x <= 9)
        printf("%d", x);
    else
        printf("%c", 'A' + x - 10);
}

int main()
{
    // 一直输入直到有合法输入
    get();
    while (ok != 1)
        get();
    // scanf("%lf", &n);
    // 整数部分转16进制
    if (p1 == 0)
        ans1[cnt1++] = 0;
    if (p2 == 0)
        ans2[cnt2++] = 0;
    while (p1 != 0)
    {
        ans1[cnt1++] = p1 % 16;
        p1 = p1 / 16;
    }
    // 小数部分转16进制
    while (p2 != 0)
    {
        ans2[cnt2++] = p2 % 16;
        p2 = p2 / 16;
    }
    // 整数部分输出
    for (int i = cnt1 - 1; i >= 0; i--)
        print(ans1[i]);
    printf(".");
    // 小数部分输出
    for (int i = cnt2 - 1; i >= (cnt2 - 7 > 0 ? cnt2 - 6 : 0); i--)
        print(ans2[i]);
    return 0;
}