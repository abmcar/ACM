#include <bits/stdc++.h>

using namespace std;

int n;
long long tot;
int nex[2333333];
long long ans[2333333];
char String[2333333];

int main()
{
    scanf("%d", &n);
    scanf("%s", String + 1);
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && String[i] != String[j + 1])
        {
            j = nex[j];
        }
        if (String[i] == String[j + 1])
        {
            j++;
        }
        nex[i] = j;
        if (ans[j] != 0)
            ans[i] = ans[j];
        else
            ans[i] = j;
    }
    for (long long i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
            ans[i] = i;
        tot += i - ans[i];
    }
    printf("%d", tot);
    return 0;
}