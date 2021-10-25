#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

long long n,minn,maxn;

int main()
{
    cin >> n >> minn >> maxn;
    if(n <= 1)
    {
        if(minn == maxn)
            cout << "1";
        else
            cout << "0";
        return 0;
    }
    cout << maxn*(n-2)-minn*(n-2)+1;
    return 0;
}