#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k,t;

void work()
{
    cin >> n >> k;
    if(n >= k)
    {
        if(n % k != 0)
            cout << 2 << endl;
        else
            cout << 1 << endl;
        return;
    }
    if(k % n != 0)
        cout << (k/n)+1 << endl;
    else
        cout << (k/n) << endl;
    return;
}

int main()
{
    cin >> t;
    while(t--)
        work();
    return 0;
}