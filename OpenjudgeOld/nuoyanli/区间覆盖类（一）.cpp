#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int used;
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
    for(int i = 1; i <= n; i++)
    {
        int a,b;
        cin >> a >> b;
        s[i].str = min(a,b);
        s[i].fin = max(a,b);
        //cin >> s[i].str >> s[i].fin;
    }
    sort(s+1,s+1+n,cmp);
    int nowtime = -1;
    int ans = 0;
    for(int i= 1; i <= n; i++)
    {
        int nowfin = s[i].fin;
        int nowstr = s[i].str;
        if(nowtime > nowstr)
            continue;
        nowtime = nowfin;
        ans++;
    }
    used++;
    cout << "Case " << used << ":" << endl;;
    cout << ans << "." << endl;
}

int main()
{
    while(cin >> n)
        work();
    return 0;
}