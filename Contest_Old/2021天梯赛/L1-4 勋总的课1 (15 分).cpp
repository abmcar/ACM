#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <climits>
#define Buff std::ios::sync_with_stdio(false)
#define endl "\n"

using namespace std;

int lowbit(int n)
{
    return n & -n;
}

int n;

void work()
{
    int tt = n;
    string ans = "";
    // if(n == 0)
    // {
    //     cout << "10000000 00000000 00000000 00000000 <->0" << endl;
    //     return;
    // }
    int temp = 0;
    while(n != 0)
    {
        for(; temp < log2(lowbit(n)); temp++)
            ans = "0" + ans;
        ans = "1" + ans;
        temp++;
        n = n - lowbit(n);
    }
    while(ans.size() != 32)
        ans = "0" + ans;
    for(int i = 0; i < 8; i++)
        cout << ans[i];
    cout << " ";
    for(int i = 8; i < 16; i++)
        cout << ans[i];
    cout << " ";
    for(int i = 16; i < 24; i++)
        cout << ans[i];
    cout << " ";
    for(int i = 24; i < 32; i++)
        cout << ans[i];
    cout << " <->" << tt << endl;
}

int main()
{
    Buff;
    while(cin >> n)
        work();
    return 0;
}