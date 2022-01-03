#include <bits/stdc++.h>

using namespace std;

int t, n1, n2;
string s;

bool check(string ns, int pos)
{
    if (ns[pos] >= 'A' && ns[pos] <= 'Z' && ns[pos - 1] != ' ')
        return false;
    return true;
}

int main()
{
    cin >> t;
    getchar();
    for (int i = 1; i <= t; i++)
    {
        string ans = "yes";
        n1 = n2 = 0;
        getline(cin, s);
        if (s[0] >= 'a' && s[0] <= 'z')
            ans = "no";
        for (int i = 1; i < s.size(); i++)
        {
            if (check(s, i) == false)
                ans = "no";
            if (s[i] == ' ')
                n1++;
            if (s[i] >= 'A' && s[i] <= 'Z')
                n2++;
            if (n2 > 1)
                ans = "no";
            if (n1 > 1)
                ans = "no";
        }
        cout << ans << endl;
    }
    return 0;
}
/* 
4
Zhuge Liang
no
Sikong Kongming
no
SiKong Kongming
no
 */