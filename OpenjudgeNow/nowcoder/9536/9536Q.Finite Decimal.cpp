#include<iostream>
#include<cmath>

using namespace std;

int t;
long long n;

void work()
{
    cin >> n;
    long long temp = 1e18;
    n = temp/n;
    if(temp % n == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}