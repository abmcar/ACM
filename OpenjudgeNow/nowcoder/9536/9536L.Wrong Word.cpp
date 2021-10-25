#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<vector>

using namespace std;

string s;
int totlen;
int ans;
bool used[23];
unordered_map<string,bool> m;

void dfs(string nows,vector<char> nowused)
{
    int nowlen = nows.size();
    if(nowlen == totlen)
    {
        if(m[nows] == 1)
            return;
        ans++;
        m[nows] = 1;
        return;
    }
    
    for(int i = 0; i < nowused.size(); i++)
    {
        char tempchar = nowused[i];
        nowused.erase(nowused.begin()+i);
        dfs(nows+tempchar,nowused);
        nowused.insert(nowused.begin()+i,tempchar);
    }
    return;
}

int main()
{
    cin >> s;
    totlen = s.size();
    m[s] = 1;
    vector<char> temp;
    for(int i = 0; i < totlen; i++)
        temp.push_back(s[i]);
    dfs("",temp);
    cout << ans << endl;
}