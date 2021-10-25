#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#define Maxn (int)1e6+10
using namespace std;

int t,n;
long long num[Maxn];

void work()
{
    bool isok = false;
    map<long long,int> temp;
    priority_queue<long long> q;
    cin >> n;
    for(int i = 1; i <= n*2; i++)
        cin >> num[i];
    for(int i = 1; i <= n*2; i++)
    {
        temp[num[i]]++;
        if(temp[num[i]] == 1)
        {
            q.push(num[i]);
            isok = false;
            continue;
        }
        if(temp[num[i]] == 2)
        {
            isok = true;
            continue;
        }
        cout << "NO" << endl;
        return;
    }
    if(isok == false)
    {
        cout << "NO" << endl;
        return;
    }
    long long lastans = 0;
    int pos = 0;
    while(!q.empty())
    {
        pos++;
        long long nownum = q.top()-lastans;
        q.pop();
        // cout << pos << " " << nownum << " "  << (2*(n-pos+1)) << " " << nownum/(2*(n-pos+1)) << "  " << endl;
        if(nownum % (2*(n-pos+1)) != 0 || nownum/(2*(n-pos+1)) <= 0)
        {
            cout << "NO" << endl;
            return;
        }
        lastans += 2*(nownum/(2*(n-pos+1)));
    }
    cout << "YES" << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}