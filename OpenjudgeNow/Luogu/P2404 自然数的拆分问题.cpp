#include<iostream>
#include<vector>

using namespace std;

int num;
void dfs(int nownum,vector<int> nowlist)
{
    // if(nownum == 0)
    // {
    //     for(int i = 0; i < nowlist.size()-1; i++)
    //         cout << nowlist[i] << "+";
    //     cout << nowlist[nowlist.size()-1] << endl;
    // }

    int lastnum = 1;
    if(nowlist.size() != 0)
    lastnum = nowlist[nowlist.size()-1];
    for(int i = lastnum; i <= nownum/2; i++)
    {
        vector<int> nextlist = nowlist;
        nextlist.push_back(i);
        dfs(nownum-i,nextlist);
    }
    for(int i = 0; i < nowlist.size(); i++)
        cout << nowlist[i] << "+";
    if(nowlist.size() != 0)
    cout << nownum << endl;
}

int main()
{
    cin >> num;
    vector<int> temp;
    dfs(num,temp);
    return 0;
}