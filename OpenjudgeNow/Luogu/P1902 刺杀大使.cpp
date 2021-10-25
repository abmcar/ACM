#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define Maxn (int)1e3+10
using namespace std;

int bd[Maxn][Maxn];
int n,m;
int nextx[5] = {0,1,0,0,-1};
int nexty[5] = {0,0,1,-1,0};
bool used[Maxn][Maxn];

bool check(int num)
{
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        used[i][j] = 0;
    queue<int> nowx;
    queue<int> nowy;
    for(int i = 1; i <= m; i++)
    if(bd[2][i] <= num)
        nowx.push(1),nowy.push(i),used[1][i] = 1;
    while(!nowx.empty())
    {
        int roomx = nowx.front();
        int roomy = nowy.front();
        nowx.pop();
        nowy.pop();
        if(roomx == n)
            return true;
        for(int i = 1; i <= 4; i++)
        {
            int nextroomx = roomx + nextx[i];
            int nextroomy = roomy + nexty[i];
            if(nextroomy == 0 || nextroomy == m+1)
                continue;
            if(nextroomx == 0)
                continue;
            if(used[nextroomx][nextroomy] == 1)
                continue;
            if(bd[nextroomx][nextroomy] <= num)
                nowx.push(nextroomx),nowy.push(nextroomy);
            used[nextroomx][nextroomy] = 1;
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    // freopen("a.in","r",stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        cin >> bd[i][j];
    int l = 0;
    int r = 1e4;
    int ans;
    while(l <= r)
    {
        // cout << l << ' ' << r << endl;
        int mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            r = mid-1;
        }else
            l = mid+1;
    }
    cout << ans;
    return 0;
}