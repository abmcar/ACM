#include<iostream>

using namespace std;

long long a,b;

int main()
{
    cin >> a >> b;
    if(a % b == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}