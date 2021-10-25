#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int n;
int level[100100];
vector<int> num[100100];
map<int, vector<int> > m;
int nowvector;
int ans = 9999999;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> level[i];
    sort(level + 1, level + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (m[level[i] - 1].size() == 0)
        {
            nowvector++;
            num[nowvector].push_back(level[i]);
            m[level[i]].push_back(nowvector);
        }
        else
        {
            int temppos = 999999;
            int minn = 9999999;
            int deletepos;
            for (int j = 0; j < m[level[i] - 1].size(); j++)
                if (num[m[level[i] - 1][j]].size() < minn)
                {
                    temppos = m[level[i] - 1][j];
                    minn = num[m[level[i] - 1][j]].size();
                    deletepos = j;
                }
            num[temppos].push_back(level[i]);
            m[level[i]].push_back(temppos);
            m[level[i] - 1].erase(m[level[i] - 1].begin() + deletepos);
        }
    }
    for (int i = 1; i <= nowvector; i++)
        ans = min(ans, (int)num[i].size());
    cout << ans;
    return 0;
}