#include<iostream>
#include<algorithm>
#include<cmath>
#define Maxn (int)1e5+10
using namespace std;

int n,num[Maxn];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    sort(num+1,num+1+n);
    int minn = 0,maxn = 0;
    for(int i = 1; i <= n/2; i++)
        minn += num[i];
    for(int i = (n/2)+1; i <= n; i++)
        maxn += num[i];
    // cout << minn << " " << maxn << endl;
    cout << n%2 << " " << maxn-minn;
    return 0;
}