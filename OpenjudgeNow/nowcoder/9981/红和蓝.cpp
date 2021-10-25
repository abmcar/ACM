#include <iostream>
#include <algorithm>
#include <vector>
#define Maxn 100000+10

using namespace std;

vector<int> sons[Maxn];
int fathers[Maxn];
int n;
char color[Maxn];

bool dfs(int str)
{
    char strcolor;
    if(color[fathers[str]] == 'R' || color[fathers[str]] == 'B')
    {
        color[str] = color[fathers[str]];
        return true;
    }
    if(sons[str].size() == 0)
    {
        color
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int tf,ts;
        cin >> tf >> ts;
        sons[tf].push_back(ts);
        fathers[ts] = tf;
    }
    for(int i = 1; i < n; i++)
        if(sons[i].size() == 0)
        {
            if(dfs(i) == false)
            {
                cout << "-1";
                return 0;
            }
        }
    for(int i = 1; i <= n; i++)
        cout << color[i];
    return 0;
}