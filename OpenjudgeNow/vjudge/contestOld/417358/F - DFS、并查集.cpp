#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

#define Maxn 1234
using namespace std;

int n,m;
string bd[Maxn];
bool dish[Maxn],disr[Maxn];
int ans;

void disable(int strh,int strr)
{
    // if(dish[strh] || disr[strr])
    // {
    //     ans--;
    //     return;
    // }
    // cout << strh << " " << strr << "   2323" << endl;
    queue<int> qh,qr;
    qh.push(strh);
    qr.push(strr);
    bd[strh][strr] = '.';
    while (!qh.empty() || !qr.empty())
    {
        while(!qh.empty())
        {
            int nowh = qh.front();
            qh.pop();
            if(dish[nowh])
                continue;
            // cout << "h" << nowh << endl;
            // cout << bd[4][0] << endl;
            for(int j = 0; j < m; j++)
                if(bd[nowh][j] == '1')
                {
                    bd[nowh][j] = '.';
                    qr.push(j);
                    // cout << nowh << ' ' << j << endl;
                }
            dish[nowh] = 1;
        }
        while(!qr.empty())
        {
            int nowr = qr.front();
            qr.pop();
            if(disr[nowr])
                continue;
            // cout << "r" << nowr << endl;
            for(int i = 1; i <= n; i++)
                if(bd[i][nowr] == '1')
                {
                    bd[i][nowr] = '.';
                    qh.push(i);
                    // cout << i << " " << nowr << endl;
                }
            disr[nowr] = 1;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> bd[i];
    for(int i = 1; i <= n; i++)
    for(int j = 0; j < m; j++)
        if(bd[i][j] == '1')
            disable(i,j),ans++;
    cout << ans;
    
    return 0;
}