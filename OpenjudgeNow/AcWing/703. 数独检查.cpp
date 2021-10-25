#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int Maxn = 60;
int t,n;
int bd[Maxn][Maxn];
int now;

bool check()
{
    map<int,int> m;
    for(int i = 1; i <= n*n; i++)
    {
        m.clear();
        for(int j = 1; j <= n*n; j++)
            if(bd[i][j] > n*n || m[bd[i][j]] == 1)
                return false;
            else
                m[bd[i][j]]++;
    }
    // cout << "pass1" << endl;
    for(int j = 1; j <= n*n; j++)
    {
        m.clear();
        for(int i = 1; i <= n*n; i++)
            if(bd[i][j] < 1 || bd[i][j] > n*n || m[bd[i][j]] == 1)
                return false;
            else
                m[bd[i][j]]++;
    }
    // cout << "pass2" << endl;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
        m.clear();
        for(int k = (i-1)*n+1; k <= i*n; k++)
        for(int l = (j-1)*n+1; l <= j*n; l++)
            if(bd[k][l] < 1 || bd[k][l] > n*n || m[bd[k][l]] == 1)
                return false;
            else
                m[bd[k][l]]++;
    }
    return true;
}

void work()
{
    cin >> n;
    for(int i = 1; i <= n*n; i++)
    for(int j = 1; j <= n*n; j++)
        cin >> bd[i][j];
    cout << "Case #" << ++now << ": ";
    if(check())
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
        work();
    return 0;
}