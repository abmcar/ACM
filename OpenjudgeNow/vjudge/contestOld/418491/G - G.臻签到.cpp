#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

int t,n;
map<string,bool> m;
int cnt;
string add(string num)
{
    cnt++;
    string tempnum = num;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j+num[i] <= '9'; j++)
        {
            num[i] += j;
            if(m[num] == false)
                return num;
            num[i] -= j;
        }
        for(int j = 1; j-num[i] >= '0'; j--)
        {
            num[i]-= j;
            if(m[num] == false)
                return num;
            num[i]+= j;
        }
    }
}

void work()
{
    m.clear();
    map<string,int> mm;
    vector<string> ans;
    cnt = 0;
    cin >> n;
    string ss[23];
    for(int i = 1; i <= n; i++)
    {
        cin >> ss[i];
        m[ss[i]] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        string temp = ss[i];
        if(mm[temp] == 0)
        {
            ans.push_back(temp);
            m[temp] = true;
            mm[temp]++;
            continue;
        }
        temp = add(temp);
        m[temp] = true;
        ans.push_back(temp);
        mm[temp]++;
    }
    cout << cnt << endl;
    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}