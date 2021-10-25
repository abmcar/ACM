#include <iostream>
#include <cmath>
#include <algorithm>
#define Maxn (int)123

using namespace std;

int n;
int bd[Maxn][Maxn];

int main()
{
    while(cin >> n)
    {
        if(n == 0)
            return 0;
        for(int i = 1; i <= n; i++)
        {
            int temp = 1;
            for(int j = i; j <= n; j++)
            {
                bd[j][temp] = i;
                bd[temp++][j] = i;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                cout << bd[i][j] << " ";
            cout << endl;
        }
    }
}