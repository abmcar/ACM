#include<iostream>
#include<algorithm>
#include<vector>

#define MAXN 100000+10

using namespace std;


int n,m,nowpos;
int prepos[MAXN];
long long totvisit[MAXN];
long long pa[MAXN],pb[MAXN],pc[MAXN];
unsigned long long minncost[MAXN];
unsigned long long ans;
vector<int> worklist;

int main()
{
    cin >> n >> m; 
    for(int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        worklist.push_back(temp);
    }
    for(int i = 1; i <= n-1; i++)
        cin >> pa[i] >> pb[i] >> pc[i];
    nowpos = worklist[0];
    for(int i = 1; i < worklist.size(); i++)
    {
        int nextpos = worklist[i];
        int minn = min(nowpos,nextpos);
        int maxn = max(nowpos,nextpos);
        prepos[minn]++;
        prepos[maxn]--;
        nowpos = nextpos;
        // for(int i = 1; i <= 9; i++)
        //     cout << prepos[i] << " ";
        // cout << endl;
    }
    int now = 0;
    for(int i = 0; i <= MAXN; i++)
    {
        now += prepos[i];
        totvisit[i] += now;
    }
    for(int i = 1; i <= MAXN; i++)
        ans += min(totvisit[i]*pa[i],pc[i]+totvisit[i]*pb[i]);
    // for(int i = 1; i <= 9; i++)
    //     cout << totvisit[i] << " ";
    // cout << endl;
    cout << ans;
    return 0;
}