#include<iostream>
#include<algorithm>

using namespace std;

long long n,m,a;
long long l,r;

int main()
{
    cin >> n >> m >> a;
    l = n/a;
    r = m/a;
    if(n%a != 0)
        l++;
    if(m%a != 0)
        r++;
    cout << l*r;
    return 0;
}