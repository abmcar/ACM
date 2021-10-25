#include <iostream>
#include <string>

using namespace std;

string a, b;

int main()
{
    cin >> a >> b;
    if (a == b)
    {
        cout << "100";
        return 0;
    }
    if (a[0] == b[1] && a[1] == b[0])
    {
        cout << "20";
        return 0;
    }
    if (a[0] == b[0] || a[0] == b[1] || a[1] == b[0] || a[1] == b[1])
    {
        cout << "2";
        return 0;
    }
    cout << "0";
    return 0;
}