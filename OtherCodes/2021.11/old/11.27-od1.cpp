#include <bits/stdc++.h>

using namespace std;

string oriString;
vector<int> nums;
int ans = 0;

int main()
{
    cin >> oriString;
    for (int i = 0; i < oriString.size(); i += 2)
        nums.push_back(oriString[i] - '0');
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            int nowMax = 0;
            for (int j = i + 1; j <= nums.size(); j++)
                if (nums[j] == 1)
                {
                    nowMax = j - i;
                    break;
                }
            for (int j = i - 1; j >= 0; j--)
                if (nums[j] == 1)
                {
                    nowMax = min(nowMax, i - j);
                    break;
                }
            ans = max(ans, nowMax);
        }
    }
    cout << ans << endl;
    return 0;
}

/* 
1,0,0,0,0,1,0,0,1,0,1
 */