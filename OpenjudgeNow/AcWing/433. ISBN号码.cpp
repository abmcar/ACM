#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 11;
int nowMultiple = 1;
int ans;
string fins;

int main()
{
    std::ios::sync_with_stdio(false);
    char tempchar;
    int tempnum;
    cin >> tempchar;
    fins = fins + tempchar;
    tempnum = tempchar - '0';
    ans += tempnum * nowMultiple++;
    cin >> tempchar;
    fins = fins + tempchar;
    for(int i = 1; i <= 3; i++)
    {
        cin >> tempchar;
        fins = fins + tempchar;
        tempnum = tempchar - '0';
        ans += tempnum * nowMultiple++;
    }
    cin >> tempchar;
    fins = fins + tempchar;
    for(int i = 1; i <= 5; i++)
    {
        cin >> tempchar;
        fins = fins + tempchar;
        tempnum = tempchar - '0';
        ans += tempnum * nowMultiple++;
    }
    ans = ans % Mod;
    cin >> tempchar;
    fins = fins + tempchar;
    cin >> tempchar;
    if(tempchar != 'X')
        tempnum = tempchar - '0';
    else
        tempnum = 10;
    // cout << tempchar << " " << ans << endl;
    if(tempnum == ans)
    {
        cout << "Right";
        return 0;
    }
    if(ans != 10)
        fins = fins + (char)(ans+'0');
    else
        fins = fins + 'X';
    cout << fins;
    return 0;
}