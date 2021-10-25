#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> v;
int n,m;
int num[23333];


void work()
{
    int flag,x,y,k;
    cin >> flag;
    if(flag == 1)
    {
        cin >> x >> y;
        swap(num[x],num[y]);
        return;
    }
    cin >> k;
    v.clear();
    int nowans = 0;
    bool isend = 0;
    while(1)
    {
        nowans++;
        for(int i = 1; i <= n; i++)
        {
            if(v.size() != 0)
            if(v[v.size()-1]+k > n)
            {
                isend = 1;
                break;
            }
            if(num[i] == 1 && v.size() == 0)
            {
                v.push_back(num[i]);
                continue;
            }
            if(v.size() != 0)W
            if(num[i] == v[v.size()-1]+k)
            {
                v.push_back(num[i]);
                continue;
            }
        }
        if(isend == 1)
            break;
    }
    cout << nowans << endl;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        work();
    return 0;
}