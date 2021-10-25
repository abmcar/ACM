#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

int n;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    int l = 1, r = n, ans;
    while(l < r)
    { 
        int mid = (l+r)/2;
        int num1,num2;
        cout << "? " << mid << endl;
        cin >> num1;
        cout << "? " << mid+1 << endl;
        cin >> num2;
        if(num1 > num2)
            l = mid+1;
        else
            r = mid;
    }
    cout << "! " << l << endl;
    return 0;
}
