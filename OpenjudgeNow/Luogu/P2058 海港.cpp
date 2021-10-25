#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> members[100010];
queue<int> times;
int n,numbers;
int nums[300010];
int nowans;
int nowused;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int tempnum,temptime;
        cin >> temptime >> tempnum;
        times.push(temptime);
        int lasttime = times.front();
        for(int j = 1; j <= tempnum; j++)
        {
            int temp;
            cin >> temp;
            members[i].push_back(temp);
        }
        while(temptime - lasttime >= 86400)
        {
            nowused++;
            for(int j = 0; j < members[nowused].size(); j++)
            {
                nums[members[nowused][j]]--;
                if(nums[members[nowused][j]] == 0)
                    nowans--;
            }
            times.pop();
            lasttime = times.front();
        }
        for(int j = 0; j < members[i].size(); j++)
        {
            if(nums[members[i][j]] == 0)
                nowans++;
            nums[members[i][j]]++;
        }
        cout << nowans << endl;
    }
    return 0;
}