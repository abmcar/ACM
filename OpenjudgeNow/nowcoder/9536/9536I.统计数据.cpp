#include<iostream>

using namespace std;

int num[23333];
int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        num[temp]++;
    }
    for(int i = 10000; i >= 1; i--)
        if(num[i] == 0)
            continue;
        else
            cout << i << "-" << num[i] << endl;
    return 0;
}