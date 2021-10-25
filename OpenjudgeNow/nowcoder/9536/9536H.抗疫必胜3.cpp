#include<iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
            cout << " ";
        cout << "V";
        if(n == i)
            continue;
        for(int j = 1; j <= (n-i)*2-1; j++)
            cout << " ";
        cout << "V" << endl;
    }
    return 0;
}