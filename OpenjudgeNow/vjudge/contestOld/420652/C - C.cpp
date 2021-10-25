/*
1 1*4+4 3*4+4 5*4+4 7*4+4
1 8     16    24    56
*/
#include <iostream>
#include <algorithm>

using namespace std;

int t,n;

void work()
{
    cin >> n;
    long long ans = 0;
    for(long long i = 1; (1+(i-1)*2) < n; i++)
        ans += ((1+(i-1)*2)*4+4)*i;
    cout << ans << endl;
}

int main()
{
    cin >> t;
    while(t--)
        work();
    return 0;
}