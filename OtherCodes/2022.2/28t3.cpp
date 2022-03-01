#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int n;
string oriString[10];
vector<string> targetString;
unordered_map<string, bool> M;

void dfs(int nowPos, vector<bool> used, string nowString)
{
    M[nowString] = true;
    for (int i = 1; i <= 4; i++)
    {
        if (used[i])
            continue;
        vector<bool> nextU = used;
        nextU[i] = true;
        for (char nextChar : oriString[i])
            dfs(i, nextU, nowString + nextChar);
    }
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= 4; i++)
        cin >> oriString[i];
    targetString.resize(n + 1);
    vector<bool> oriUse(5, false);
    dfs(0, oriUse, "");
    for (int i = 1; i <= n; i++)
    {
        cin >> targetString[i];
        if (M[targetString[i]])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}