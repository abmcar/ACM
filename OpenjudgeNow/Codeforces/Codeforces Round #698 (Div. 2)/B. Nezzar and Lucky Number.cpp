#include <iostream>
#include <algorithm>
#include <cmath>
#define Maxn (int)1e4

using namespace std;

int t, q, d;

bool check(int num)
{
    if(num < 0)
        return false;
    if(num >= d*10)
        return true;
    for(int i = 1; i <= 9; i++)
    {
        int tempnum = num-d*i;
        if(tempnum < 0)
            return false;
        if(tempnum % 10 == 0)
            return true;
    }
    return false;
}

void work()
{
    cin >> q >> d;
    for(int i = 1; i <= q; i++)
    {
        int temp;
        cin >> temp;
        if(check(temp))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}