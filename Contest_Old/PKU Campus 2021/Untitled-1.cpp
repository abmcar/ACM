#include <iostream>

using namespace std;

int lowbit(int k)
{
    return k&(-k);
}

int main()
{
    int n;
    while (cin >> n)
        cout << lowbit(n) << endl;
}