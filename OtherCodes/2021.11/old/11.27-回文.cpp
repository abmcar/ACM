#include <bits/stdc++.h>
using namespace std;

int n;
char s1[5555];
int f[5555][5555];

int main()
{
    scanf("%d", &n);
    scanf("%s", s1);

    for (int k = 1; k < n; k++)
        for (int i = 0; i + k < n; i++)
        {
            int j = i + k;
            f[i][j] = min(f[i + 1][j] + 1, f[i][j - 1] + 1);
            if (s1[i] == s1[j])
                f[i][j] = min(f[i][j], f[i + 1][j - 1]);
        }
    printf("%d", f[0][n - 1]);
    return 0;
}

/* 

 */