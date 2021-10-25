#include<iostream>
#include<string>

using namespace std;

int n,m;
string bd[233333];
int num[233][233];
int nx[9] = {0,0,1,1,1,0,-1,-1,-1};
int ny[9] = {0,1,1,0,-1,-1,-1,0,1};

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> bd[i];
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        if(bd[i][j-1] == '*')
            for(int k = 1; k <= 8; k++)
                num[i+nx[k]][j+ny[k]]++;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            if(bd[i][j-1] == '*')
                cout << "*";
            else
                cout << num[i][j];
        cout << endl;
    }
    return 0;
}