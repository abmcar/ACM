#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 2e5+10;
const ll Mod = 1e9+7;
int n1[Maxn],n2[Maxn],n3[Maxn],n4[Maxn];
int N1,N2,N3,N4;
int M1,M2,M3;

map<int,bool> m1[Maxn],m2[Maxn],m3[Maxn];
int f[Maxn];
bool ok[Maxn];

int main()
{
    Buff;
    fill(f+1,f+Maxn,2e9);
    cin >> N1 >> N2 >> N3 >> N4;
    for(int i = 1; i <= N1; i++)
        cin >> n1[i];
    for(int i = 1; i <= N2; i++)
        cin >> n2[i];
    for(int i = 1; i <= N3; i++)
        cin >> n3[i];
    for(int i = 1; i <= N4; i++)
        cin >> n4[i];
    cin >> M1;
    for(int i = 1; i <= M1; i++)
    {
        int ta,tb;
        cin >> ta >> tb;
        m1[ta][tb] = true;
    }
    cin >> M2;
    for(int i = 1; i <= M2; i++)
    {
        int ta,tb;
        cin >> ta >> tb;
        m2[ta][tb] = true;
    }
    cin >> M3;
    for(int i = 1; i <= M3; i++)
    {
        int ta,tb;
        cin >> ta >> tb;
        m3[ta][tb] = true;
    }
    for(int i = 1; i <= N3; i++)
    {
        int tempnum[Maxn];
        fill(tempnum,tempnum+Maxn,2e9);
        for(int j = 1; j <= N4; j++)
            if(!m3[i][j])
                tempnum[i] = min(tempnum[i],n3[i]+n4[j]);
        for(int i = 1; i <= N3; i++)
            f[i] = tempnum[i];
    }
    for(int i = 1; i <= N2; i++)
    {
        int tempnum[Maxn];
        fill(tempnum,tempnum+Maxn,2e9);
        for(int j = 1; j <= N3; j++)
            if(!m3[i][j])
                tempnum[i] = min(tempnum[i],f[j]+n2[i]);
        for(int i = 1; i <= N2; i++)
            f[i] = tempnum[i];
    }
    for(int i = 1; i <= N1; i++)
    {
        int tempnum[Maxn];
        fill(tempnum,tempnum+Maxn,2e9);
        for(int j = 1; j <= N2; j++)
            if(!m3[i][j])
                tempnum[i] = min(tempnum[i],f[j]+n1[i]);
        for(int i = 1; i <= N1; i++)
            f[i] = tempnum[i];
    }
    int minn = 2e9;
    for(int i = 1; i <= N1; i++)
        minn = min(minn,f[i]);
    if(minn == 2e9)
        minn = -1;
    cout << minn;
    return 0;
}