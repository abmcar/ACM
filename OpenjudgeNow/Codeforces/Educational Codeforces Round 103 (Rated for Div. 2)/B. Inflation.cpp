#include <iostream>
#include <algorithm>

using namespace std;

int t,n;
long long k;

void work()
{
    long long ans = 0;
    long long base;
    cin >> n >> k;
    cin >> base;
    for(int i = 2; i <= n; i++)
    {
        long long temp;
        cin >> temp;
        // cout << temp/k << " needbase" << endl;
        if(base*k < temp*100)
        {
            long long newbase = temp*100/k;
            while(newbase*k < temp*100)
                newbase++;
            // cout << newbase << " " << base << " " << temp << endl;
            ans += newbase - base;
            base = newbase;
            base += temp;
        }
        else
            base += temp;
        // cout << base << " afterbase" << endl;
    }
    cout << ans << endl;
}

int main()
{
    cin >> t;
    while(t--)
        work();
    return 0;
}