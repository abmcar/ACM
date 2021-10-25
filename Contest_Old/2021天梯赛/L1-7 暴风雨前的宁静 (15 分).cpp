#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

#define Buff std::ios::sync_with_stdio(false)
#define endl "\n"

using namespace std;

int n;

int main()
{
    Buff;
    cin >> n;
    if(n == 2)
    {
        cout << "1" << endl << "1";
        return 0;
    }
    if(n == 3)
    {
        cout << "2" << endl << "1 3";
        return 0;
    }
    if(n == 4)
    {
        cout << "3" << endl << "3 1 4";
        return 0;
    }
    cout << n << endl;
    for(int i = 1; i <= n; i+=2)
        cout << i << " ";
    for(int i = 2; i <= n; i+=2)
        cout << i << " ";
    return 0;
}