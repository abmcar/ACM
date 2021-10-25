#include<iostream>
#include<algorithm>

using namespace std;

long long n,k;
long long nowmax;
long long ans;

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        long long temp;
        cin >> temp;
        nowmax = max(temp,nowmax);
    }
    ans = n + nowmax - 1;
    if(ans > k)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}