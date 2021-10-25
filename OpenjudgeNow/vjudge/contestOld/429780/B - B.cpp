#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
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
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int t, n, k;
string temp;

void work()
{
    cin >> n >> k;
    int ans = 0;
    cin >> temp;
    int tSize = temp.size();
    int leftPos,rightPos;
    rightPos = 0;
    for(int i = 0; i < tSize; i++)
        if(temp[i] == '*')
        {
            temp[i] = 'X';
            ans++;
            leftPos = i;
            break;
        }
    for(int i = tSize-1; i >= 0; i--)
        if(temp[i] == '*')
        {
            temp[i] = 'X';
            ans++;
            rightPos = i;
            break;
        }
    int firDis = k;
    while(rightPos - leftPos - 1 >= k)
    {
        if(temp[leftPos+firDis] == '*')
        {
            leftPos = leftPos+firDis;
            ans++;
            firDis = k;
            continue;
        }
        if(temp[rightPos-firDis] == '*')
        {
            rightPos = rightPos-firDis;
            ans++;
            firDis = k;
            continue;
        }
        firDis--;
        // for(int i = leftPos+k; i > leftPos; i++)
        // if(temp[i] == '*')
        // {
        //     leftPos = i;
        //     ans++;
        //     break;
        // }
        // if(rightPos - leftPos - 1 >= k)
        // {
        //     for(int i = rightPos-k; i < rightPos; i++)
        //     if(temp[i] == '*')
        //     {
        //         rightPos = i;
        //         ans++;
        //         break;
        //     }
        // }
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}