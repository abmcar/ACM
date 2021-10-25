#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define Maxn (int)1e6+10

using namespace std;

int n,k;
int vised[Maxn*4];
struct Pos
{
    int pos,time;
};
int ans = 1e8;
int main()
{
    cin >> n >> k;

        queue<Pos> q;
        Pos str;
        ans = 1e8;
        str.pos = n;
        str.time = 0;
        q.push(str);
        for(int i = 0; i <= Maxn*3; i++)
            vised[i] = 1e8;
        while(!q.empty())
        {
            Pos nowpos = q.front();
            q.pop();
            // cout << nowpos.pos  << " " << nowpos.time << endl;
            if(nowpos.pos > k)
            {
                ans = min(nowpos.time+nowpos.pos-k,ans);
                continue;
            }
            if(nowpos.pos == k)
            {
                ans = min(ans,nowpos.time);
                continue;
            }
            if(nowpos.time >= ans)
                continue;
            if(nowpos.time > vised[nowpos.pos])
                continue;
            vised[nowpos.pos] = nowpos.time;
            Pos next1,next2,next3;
            next1.pos = nowpos.pos * 2;
            next2.pos = nowpos.pos + 1;
            next3.pos = nowpos.pos - 1;
            next1.time = next2.time = next3.time = nowpos.time+1;
            q.push(next1);
            q.push(next2);
            q.push(next3);
        }
        cout << ans << endl;
    
}