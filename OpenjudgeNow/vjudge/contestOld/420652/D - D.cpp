#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define Maxn (int)1e6

using namespace std;

int t,n;
int num[Maxn];

struct Node
{
    int l,r,mid;
    int size;
    bool operator<(const Node b) const
    {
        if(size == b.size)
        {
            return l > b.l;
        }
        return size < b.size;
    }
};

void work()
{
    cin >> n;
    priority_queue<Node> q;
    Node fir;
    if(n % 2 == 1)
        fir.mid = (1+n)/2;
    else
        fir.mid = (n/2);
    fir.l = 1;
    fir.r = n;
    fir.size = n-1;
    q.push(fir);
    int cnt = 0;
    while(!q.empty())
    {
        Node now = q.top();
        int nowmid = now.mid;
        int nowl = now.l;
        int nowr = now.r;
        q.pop();
        // cout << nowmid << " " << nowl << " " << nowr << " " << cnt+1 << " " << now.size << endl;
        num[nowmid] = ++cnt;
        if(nowmid-nowl >= nowr-nowmid)
        {
            if((nowmid-1-nowl+1) % 2 == 1 && nowmid != nowl)
            {
                Node next;
                next.l = nowl;
                next.r = nowmid-1;
                next.mid = (nowmid-1+nowl)/2;
                next.size = next.r - next.l;
                q.push(next);
            }
            if((nowmid-1-nowl+1) % 2 == 0 && nowmid != nowl)
            {
                Node next;
                next.l = (nowl);
                next.r = (nowmid-1);
                next.mid = (nowmid-2+nowl)/2;
                next.size = next.r - next.l;
                q.push(next);
            }
            if((nowr-(nowmid+1)+1) % 2 == 1 && nowmid != nowr)
            {
                Node next;
                next.l = (nowmid+1);
                next.r = (nowr);
                next.mid = (nowr+nowmid+1)/2;
                next.size = next.r - next.l;
                q.push(next);
            }
            if((nowr-(nowmid+1)+1) % 2 == 0 && nowmid != nowr)
            {
                Node next;
                next.l = (nowmid+1);
                next.r = (nowr);
                next.mid = (nowr+nowmid)/2;
                next.size = next.r - next.l;
                q.push(next);
            }
        }else
        {
            if((nowr-(nowmid+1)+1) % 2 == 1 && nowmid != nowr)
            {
                Node next;
                next.l = (nowmid+1);
                next.r = (nowr);
                next.mid = (nowr+nowmid+1)/2;
                next.size = next.r - next.l;
                q.push(next);
            }
            if((nowr-(nowmid+1)+1) % 2 == 0 && nowmid != nowr)
            {
                Node next;
                next.l = (nowmid+1);
                next.r = (nowr);
                next.mid = (nowr+nowmid)/2;
                next.size = next.r - next.l;
                q.push(next);
            }
            if((nowmid-1-nowl+1) % 2 == 1 && nowmid != nowl)
            {
                Node next;
                next.l = nowl;
                next.r = nowmid-1;
                next.mid = (nowmid-1+nowl)/2;
                next.size = next.r - next.l;
                q.push(next);
            }
            if((nowmid-1-nowl+1) % 2 == 0 && nowmid != nowl)
            {
                Node next;
                next.l = (nowl);
                next.r = (nowmid-1);
                next.mid = (nowmid-2+nowl)/2;
                next.size = next.r - next.l;
                q.push(next);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << num[i] << " ";
    cout << endl; 
}

int main()
{
    cin >> t;
    while(t--)
        work();
    return 0;
}