#include<iostream>
#include<algorithm>

using namespace std;

long long a,c,b;
long long d,e,f;

int main()
{
    cin >> a >> b >> c;
    d = min(a,b);
    a = max(a-d,(long long)0);
    e = min(a,c);
    c = max(c-e,(long long)0);
    f = c/2;
    cout << d+e+f;
    return 0;
}