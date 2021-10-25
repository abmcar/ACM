#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int nownum = 1;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        if(i%2 == 1)
        {
            for(int j = 1; j <= m; j++)
                cout << nownum++ << " ";
            cout << endl;
        }
        else
        {
            nownum += m;
            for(int j = 1; j <= m; j++)
                cout << nownum-j << " ";
            cout << endl;
        }
    }
    return 0;
}