#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#define Maxn (int)1e7+10

using namespace std;

int n,m;
int num[Maxn];
int q[Maxn];
int pos[Maxn];
int head = 1;
int endpos;

int main()
{
    // std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        scanf("%d",&num[i]);
    cout << "0" << endl;
    for(int i = 1; i < n; i++)
    {
        while(head <= endpos && pos[head]+m <= i)
            head++;
        while(head <= endpos && q[endpos] > num[i])
            endpos--;
        endpos++;
        q[endpos] = num[i];
        pos[endpos] = i;
        printf("%d\n",q[head]);
    }
    return 0;
}