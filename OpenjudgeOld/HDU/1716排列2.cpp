#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int num[5];
map<int,bool> m;
int ans;
bool used[5];
bool firc;
void dfs(int deep,int nowans)
{
    if(deep == 4)
    if(m[nowans] == 1)
        return;
    else
    {
        if(firc == 0)
            firc = 1;
        else
            cout << ' ';
        cout << nowans;
        m[nowans] = 1;
        return;
    }
    for(int i = 1; i <= 4; i++)
    {
        if(deep == 0 && num[i] == 0)
            continue;
        if(used[i])
            continue;
        if(deep == 0)
            firc = 0;
        used[i] = 1;
        int temp = nowans;
        temp *= 10;
        temp += num[i];
        dfs(deep+1,temp);
        used[i] = 0;
        if(deep == 0 && num[i] != num[i-1])
            cout << endl;
    }
}


void work()
{
    
    m.clear();
    sort(num+1,num+5);
    dfs(0,0);
}

int main()
{
    bool fir = 0;
    while(cin >> num[1])
    {
        for(int i = 2; i <= 4; i++)
            cin >> num[i],used[i] = 0;
        if(num[1]+num[2]+num[3]+num[4] == 0)
            return 0;
        if(fir == 1)
            cout << endl;
        else
            fir = 1;
        work();
    }
}
