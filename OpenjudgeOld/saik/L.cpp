#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string S;
int ans, now = 1;
int pre1, pre2;

int main()
{
    cin >> n >> S;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            if (S[i] == S[i - 1])
                now++;
            else
            {
                ans = max(ans, now);
                ans = max(ans, pre1 + now);
                pre1 = pre2;
                pre2 = now;
                now = 1;
            }
    }
    ans = max(ans, now);
    ans = max(ans, pre1 + now);
    pre1 = pre2;
    pre2 = now;
    cout << ans << endl;
    return 0;
}