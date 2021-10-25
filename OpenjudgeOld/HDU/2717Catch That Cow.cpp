#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

int n,k;
int mint = 1e9;
bool used[200000];
int main()
{
    while(cin >> n)
    {
        
        memset(used,0,sizeof(used));
        mint = 1e5;
        cin >> k;
        queue<int> qp,qt;
        qp.push(n);
        qt.push(0);
        used[n] = 1;
        while(!qp.empty())
        {
            int nowpos = qp.front();
            int nowtime = qt.front();
            qp.pop();
            qt.pop();
            if(nowtime >= mint)
                continue;
            if(nowpos == k)
            {
                mint = nowtime;
                continue;
            }
            if(nowpos != 0)
            if(used[nowpos-1] == 0)
            {
                qp.push(nowpos-1);
                qt.push(nowtime+1);
                used[nowpos-1] = 1;
            }
            if(nowpos > k)
                continue;
            if(used[nowpos*2] == 0)
            if(nowpos != 0)
            {
                qp.push(nowpos*2);
                qt.push(nowtime+1);
                used[nowpos*2] = 1;
            }
            if(used[nowpos+1] == 0)
            {
                qp.push(nowpos+1);
                qt.push(nowtime+1);
                used[nowpos+1] = 1;
            }
        }
        cout << mint << endl;
    }
    return 0;
}