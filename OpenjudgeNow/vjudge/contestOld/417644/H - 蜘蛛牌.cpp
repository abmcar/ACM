#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int t;
int used[11];
int pos[11];
int ans;
stack<int> num[11];

void dfs(int nowans)
{
    int temp = 0;
    for(int i = 1; i <= 10; i++)
        if(used[i] == true)
            temp++;
    // cout << temp << " " << nowans << endl;
    if(temp == 9)
        ans = min(ans,nowans);
    for(int i = 1; i <= 9; i++)
    {
        int temppos[11];
        for(int j = 1; j <= 9; j++)
            temppos[j] = pos[j];
        if(used[i] == false)
        {
            used[i] = true;
            int nextans = nowans+abs(pos[i]-pos[i+1]);
            for(int j = 1; j <= 9; j++)
                if(pos[j] == pos[i])
                    pos[j] = pos[i+1];
            pos[i] = pos[i+1];
            dfs(nextans);
            for(int j = 1; j <= 9; j++)
                pos[j] = temppos[j];
            used[i] = false;
        }
    }

}

void work()
{
    for(int i = 1; i <= 10; i++)
    {
        int temp;
        cin >> temp;
        while(!num[temp].empty())
            num[temp].pop();
        num[temp].push(temp);
        pos[temp] = i;
        used[temp] = false;
    }
    ans = 1e9;
    dfs(0);
    cout << ans << endl;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}