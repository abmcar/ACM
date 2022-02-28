#include <bits/stdc++.h>

using namespace std;

string oriString;
map<int, string> M;
vector<int> nums;

signed main()
{
    cin >> oriString;
    nums.resize(oriString.size() + 1, -1);
    int nowIndex = 0;
    while (oriString.size())
    {
        bool ok = false;
        for (int j = nowIndex; j >= 1; j--)
        {
            pair<int, string> it = {j, M[j]};
            if (it.second.size() >= oriString.size())
            {
                if (it.second == oriString)
                {
                    ok = true;
                    M[++nowIndex] = "";
                    nums[nowIndex] = j;
                    oriString = "";
                    break;
                }
                continue;
            }
            string nowString = oriString.substr(0, it.second.size());
            if (nowString == it.second)
            {
                nowString = nowString + oriString[it.second.size()];
                M[++nowIndex] = nowString;
                ok = true;
                oriString = oriString.substr(nowString.size(), oriString.size());
                nums[nowIndex] = j;
                break;
            }
        }
        if (ok)
            continue;
        M[++nowIndex] = oriString[0];
        nums[nowIndex] = 0;
        oriString = oriString.substr(1, oriString.size());
    }

    for (int i = 1; i <= nowIndex; i++)
    {
        if (M[i].size())
            cout << nums[i] << M[i][M[i].size() - 1];
        else
            cout << nums[i];
    }
    return 0;
}