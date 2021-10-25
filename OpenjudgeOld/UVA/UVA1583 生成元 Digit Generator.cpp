#include<iostream>
#include<algorithm>
#define Maxn 100010
using namespace std;

int num[2*Maxn];

int getsum(int nownum)
{
    int ans = 0;
    while(nownum != 0)
    {
        ans += nownum%10;
        nownum = nownum/10;
    }
    return ans;
}

int main()
{
    int n;
    for(int i = 1; i <= Maxn; i++)
    if(num[i+getsum(i)] == 0)
        num[i+getsum(i)] = i;
    int temp;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        cout << num[temp] << endl;
    }
    return 0;
}