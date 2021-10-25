#include <iostream>
#include <algorithm>

using namespace std;

long long t,n,m;

void work()
{
    cin >> n >> m;
    if(n == 1)
    {
        cout << "0" << endl;
        return;
    }
    if(n == 2)
    {
        cout << m << endl;
        return;
    }
    cout << 2*m << endl;
}

int main()
{
    cin >> t;
    while(t--)
        work();
    return 0;
}