#include<iostream>
#include<queue>
#include<algorithm>
// #define unsigned long long __int128
using namespace std;

vector<int> g[(int)1e6+10];
vector<int> endlist;
queue<int> worklist;
int r[(int)1e5+10];
int n,m;
__int128 fm[(int)1e6+10];
__int128 fz[(int)1e6+10];

inline void print(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

void get()
{
    cin >> n >> m;
    int totnum;
    int temp;
    for(int i = 1; i <= n; i++)
    {
        cin >> totnum;
        if(totnum == 0)
        {
            endlist.push_back(i);
            continue;
        }
        for(int j = 1; j <= totnum; j++)
        {
            cin >> temp;
            g[i].push_back(temp);
            r[temp]++;
        }
    }
    return;
}

__int128 gcd(__int128 a,__int128 b)
{
    if(a == 0 || b == 0)
        return 1;
    if(a%b == 0)
        return b;
    return gcd(b,a%b);
}

void work()
{
    for(int i = 1; i <= n; i++)
        fm[i] = 1;
    for(int i = 1; i <= n; i++)
    if(r[i] == 0)
        worklist.push(i),fz[i] = fm[i] = 1;
    while(!worklist.empty())
    {
        int nownode = worklist.front();
        worklist.pop();
        // cout << "size:" << g[nownode].size() << endl;
        if(g[nownode].empty())
            continue;
        __int128 nextfm = fm[nownode] * g[nownode].size();
        // fz[nownode] = fz[nownode]/gcd(nownode,nextfm);
        // nextfm = nextfm/gcd(fz[nownode],nextfm);
        for(int i = 0; i < g[nownode].size(); i++)
        {
            int nextnode = g[nownode][i];
            // cout << nownode << " " << nextnode << endl;
            __int128 newlcm = fm[nextnode]*(nextfm/gcd(fm[nextnode],nextfm));
            __int128 newfz = fz[nextnode] * (newlcm/fm[nextnode]) + fz[nownode] * (newlcm/nextfm);
            // cout << "fzfm " << newlcm << " " << newfz << endl;
            fz[nextnode] = newfz;
            __int128 tempnum = gcd(newlcm,fz[nextnode]);
            fm[nextnode] = newlcm/tempnum;
            fz[nextnode] = newfz/tempnum;
            r[nextnode]--;
            if(r[nextnode] == 0)
                worklist.push(nextnode);
        }
    }
    // cout << "test" << endlist.size() << endl;
    for(int i = 0; i < endlist.size(); i++)
    {
        print(fz[endlist[i]]);
        cout << " ";
        print(fm[endlist[i]]);
        cout << endl;
    }
        // cout << fz[endlist[i]] << " " << fm[endlist[i]] << endl;
    return;
}

int main()
{
    // freopen("water.in","r",stdin);
    // freopen("water.out","w",stdout);
    get();
    work();
    return 0;
}