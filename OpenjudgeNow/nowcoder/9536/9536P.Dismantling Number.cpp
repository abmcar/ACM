#include<iostream>
#include<vector>

using namespace std;

vector<int> num;
int n;
int ans;
bool ok;
void dfs(int nowtimes,int nownum)
{
    if(ok)
        return;
    for(int i = num.size()-1; i >= 0; i--)
    {
        if(nownum >= num[i])
        {
            if(nowtimes == 2)
                if(nownum != num[i])
                    return;
                else
                {
                    ok = 1;
                    return;
                }
            dfs(nowtimes+1,nownum-num[i]);
        }
    }
}

int main()
{
    int temp = 1;
    for(int i = 1; temp <= 1e9; i++)
    {
        temp = temp*2;
        num.push_back(temp);
    }
    cin >> n;
    dfs(0,n);
    if(ok)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}