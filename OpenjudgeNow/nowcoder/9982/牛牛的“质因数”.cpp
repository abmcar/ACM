#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <queue>

#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
ll ans[Maxn];
bool used[Maxn];
bool isprime[Maxn];
int n;
queue<ll> qnum,qpos;
vector<ll> primes;

int getLength(int num)
{
    int length = 0;
    while(num != 0)
    {
        length++;
        num = num / 10;
    }
    return length;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    int temppos = 0;
    for(int i = 2; i <= n; i++)
    {
        if(used[i] == 0)
        {
            isprime[i] = true;
            for(int j = 1; j * i <= n; j++)
                used[i*j] = true;
            ans[i] = i;
            qnum.push(i);
            qpos.push(++temppos);
            primes.push_back(i);
        }
    }
    while(!qnum.empty())
    {
        int nownum = qnum.front();
        int nowpos = qpos.front();
        qnum.pop();
        qpos.pop();
        // cout << nownum << " " << ans[nownum] << endl;
        for(int i = nowpos-1; i < primes.size() && nownum*primes[i] <= n; i++)
        {
            if(ans[nownum*primes[i]] != 0)
                continue;
            ll nowans = ans[nownum];
            int level = 1;
            for(int j = 1; j <= getLength(primes[i]); j++)
                level = (level*10)%Mod;
            nowans = (nowans*level%Mod+primes[i])%Mod;
            ans[nownum*primes[i]] = nowans;
            qnum.push(nownum*primes[i]);
            qpos.push(i+1);
        }
    }
    ll finans = 0;
    for(int i = 2; i <= n; i++)
        finans = (finans%Mod + ans[i]%Mod)%Mod;
    cout << finans << endl;
    return 0;
}
/*
18
2 3 3
*/