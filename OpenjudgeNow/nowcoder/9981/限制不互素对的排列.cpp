#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#define Maxn (int)3e8+10
#define Mod (int)(1e9+7)
#define ll long long

using namespace std;

int n,k;
bool vised[Maxn];
int nowans = 0;
vector<int> ans;

int main()
{
    cin >> n >> k;
    k++;
    for(int i = 2; i <= n; i+=2)
    {
        if(nowans == k)
            break;
        if(i == 6)
            continue;
            vised[i] = true;
        nowans++;
        ans.push_back(i);
    }
    if(nowans < k && n >= 6)
    {
        nowans++;
        ans.push_back(6);
        vised[6] = true;
        for(int i = 3; i <= n; i+=3)
        {
            if(nowans == k)
                break;
            vised[i] = true;
            ans.push_back(i);
            nowans++;
        }
    }
    if(nowans < k)
    {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    for(int i = 1; i <= n; i++)
        if(!vised[i])
            cout << i << " ";
    return 0;
}
