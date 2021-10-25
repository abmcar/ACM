#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 1e5+10;
const ll Mod = 1e9+7;
int n;
int num[Maxn];
int blackNum,whiteNum;
int lastBlack,lastWhite;
bool used[Maxn];

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    cin >> num[i];
    for(int i = 1; i <= n; i++)
    {
        if(num[i] != num[i+1] && num[i] != num[i-1])
        {
            if(lastWhite != num[i] && lastBlack != num[i])
            {
                if(num[i+1] == lastWhite)
                {
                    lastWhite = num[i];
                    whiteNum++;
                    continue;
                }
                if(num[i+1] == lastBlack)
                {
                    lastBlack = num[i];
                    blackNum++;
                    continue;
                }
            }
        }
        if(lastBlack != num[i])
        {
            lastBlack = num[i];
            blackNum++;
            continue;
        }
        if(lastWhite != num[i])
        {
            lastWhite = num[i];
            whiteNum++;
            continue;
        }
    }
    cout << blackNum+whiteNum << endl;
    return 0;
}