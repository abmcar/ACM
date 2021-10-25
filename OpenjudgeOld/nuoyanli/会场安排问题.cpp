#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int m,n;
struct sj
{
    int str,fin;
};
sj s[233333];

bool cmp(sj a,sj b)
{
    if(a.fin == b.fin)
        return a.str < b.str;
    return a.fin < b.fin;
}

void work()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i].str >> s[i].fin;
    sort(s+1,s+1+n,cmp);
    int nowtime = 0;
    int ans = 0;
    for(int i= 1; i <= n; i++)
    {
        int nowfin = s[i].fin;
        int nowstr = s[i].str;
        if(nowtime >= nowstr)
            continue;
        nowtime = nowfin;
        ans++;
    }
    cout << ans << endl;
}

int main()
{
    cin >> m;
    for(int i = 1; i <= m; i++)
        work();
    return 0;
}