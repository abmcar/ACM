#include <iostream>
#include <string>

using namespace std;

const int N = 1e6 + 10;

long long n, totAns;
long long ans[N], ne[N];
string s;

int main()
{
    cin >> n;
    cin >> s;
    s = "-" + s;
    int i = 2;
    int j = 0;
    for (; i <= n; i++)
    {
        while (j && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j + 1])
            j++;
        ne[i] = j;
        ans[i] = ans[j] == 0 ? j : ans[j];
    }
    for (int i = 1; i <= n; i++)
        if (ans[i] == 0)
            ans[i] = i;
    totAns = (1 + n) * n / 2;
    for (int i = 1; i <= n; i++)
        totAns = totAns - ans[i];
    cout << totAns << endl;
    return 0;
}