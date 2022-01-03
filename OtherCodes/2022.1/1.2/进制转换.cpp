#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char s[N];
int num[N], ans[N];
int main()
{
    int t, a, b, len, k;
    while (cin >> s)
    {
        memset(num, 0, sizeof(num));
        k = 0;
        a = 10;
        b = 2;
        len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                num[len - 1 - i] = s[i] - '0';
            else if (s[i] >= 'A' && s[i] <= 'Z')
                num[len - 1 - i] = s[i] - 'A' + 10;
            else
                num[len - 1 - i] = s[i] - 'a' + 36;
        }

        while (len > 0)
        {
            for (int i = len - 1; i > 0; i--)
            {
                num[i - 1] += num[i] % b * a;
                num[i] /= b;
            }
            ans[k++] = num[0] % b;
            num[0] /= b;
            while (len > 0 && !num[len - 1])
                len--;
        }
        // printf("%d %s\n%d ", a, s, b);
        for (int i = k - 1; i >= 0; i--)
        {
            if (ans[i] >= 0 && ans[i] <= 9)
                printf("%d", ans[i]);
            else if (ans[i] >= 10 && ans[i] <= 35)
                printf("%c", ans[i] - 10 + 'A');
            else
                printf("%c", ans[i] - 36 + 'a');
        }
        printf("\n");
    }
    return 0;
}
