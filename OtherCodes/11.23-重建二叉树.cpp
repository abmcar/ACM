#include <bits/stdc++.h>

using namespace std;

string ansString;
int ans;
bool ok;

bool check(string leftString, string rightString)
{
    char temp = rightString[rightString.size() - 1];
    int k = leftString.find(temp);
    if (k < 0 || k >= rightString.size() || k >= leftString.size())
        return false;
    return true;
}

void solve(string leftString, string rightString, int deep)
{
    if (ok == false)
        return;
    if (leftString.size() <= 0)
        return;
    // int lenL, lenR;
    ans = ans > deep ? ans : deep;
    char temp = rightString[rightString.size() - 1];
    ansString = ansString + temp;
    int k = leftString.find(temp);
    ok = check(leftString, rightString);
    solve(leftString.substr(k + 1), rightString.substr(k, rightString.size() - k - 1), deep + 1);
    solve(leftString.substr(0, k), rightString.substr(0, k), deep + 1);
}

inline void clear()
{
    ans = 0;
    ok = true;
    ansString = "";
}

int main()
{
    string tempS1, tempS2;
    while (cin >> tempS1 >> tempS2)
    {
        solve(tempS2, tempS1, 0);
        if (ok)
        {
            cout << ans << endl;
            cout << ansString << endl;
        }
        else
            cout << "INVALID" << endl;
        clear();
    }
    return 0;
}