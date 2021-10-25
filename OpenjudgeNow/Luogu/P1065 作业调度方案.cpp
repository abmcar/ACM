#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m;
int usedmachinepos[233][233];
int usedtime[233][233];
int arraged[233];
int nowtime[233];
bool used[233][(int)1e5+10];
vector<int> worklist;
int ans;

void get()
{
    cin >> m >> n;
    for(int i = 1; i <= n*m; i++)
    {
        int temp;
        cin >> temp;
        worklist.push_back(temp);
    }
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        cin >> usedmachinepos[i][j];
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        cin >> usedtime[i][j];
    return;
}

int main()
{
    get();
    for(int i = 0; i < worklist.size(); i++)
    {
        int nowpos = worklist[i];
        arraged[nowpos]++;
        int arragetime = nowtime[nowpos];
        int nexttime = usedtime[nowpos][arraged[nowpos]];
        int nextpos = usedmachinepos[nowpos][arraged[nowpos]];
        int tempfreetime = 0;
        for(int j = arragetime+1; j <= 1e5; j++)
            if(!used[nextpos][j]) 
            {
                tempfreetime++;
                if(tempfreetime >= nexttime)
                {
                    for(int k = j; k >= j-nexttime+1; k--)
                        used[nextpos][k] = 1;
                    nowtime[nowpos] = j;
                    ans = max(ans,nowtime[nowpos]);
                    break;
                }
            }else
                tempfreetime = 0;
    }
    cout << ans;
    return 0;
}