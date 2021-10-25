#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m;
int usedmachinepos[666];
int usedtime[666];
int arraged[23];
int nowtime[23];
bool used[23][(int)1e5+10];
vector<int> worklist;
int ans;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n*m; i++)
    {
        int temp;
        cin >> temp;
        worklist.push_back(temp);
    }
    for(int i = 1; i <= n*m; i++)
    {
        int ta,tb;
        cin >> ta >> tb;
        usedmachinepos[i] = ta;
        usedtime[i] = tb;
    }
    for(int i = 0; i < worklist.size(); i++)
    {
        int nowpos = worklist[i];
        arraged[nowpos]++;
        int arragetime = nowtime[nowpos];
        int nexttime = usedtime[i+1];
        int nextpos = usedmachinepos[i+1];
        int tempfreetime = 0;
        for(int j = arragetime+1; j <= 1e5; j++)
            if(!used[nextpos][j])
            {
                tempfreetime++;
                //cout << tempfreetime << endl;
                if(tempfreetime >= nexttime)
                {
                    // cout << tempfreetime << endl;
                    for(int k = j; k >= j-nexttime; k--)
                        used[nextpos][j] = 1;
                    nowtime[nowpos] = j;
                    ans = max(ans,nowtime[nowpos]);
                    cout << nowpos << " " << nextpos << " " << j << endl;
                    break;
                }
            }else
                tempfreetime = 0;
    }
    cout << ans;
    return 0;
}