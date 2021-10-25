#include<iostream>
#include<algorithm>

using namespace std;

int n;
long long num = 1;
const int Mod = 1e9;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        num *= i; 
        while(num % 10 == 0)
            num = num / 10;
        num = num % Mod;
    }
    cout << num % 10;
    return 0;
}