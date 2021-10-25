#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int l,k;
string s;

bool check(long long n)
{
    if(n == 2)
        return true;
    for(long long i = 2; i*i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main()
{
    cin >> l >> k;
    cin >> s;
    for(int i = 0; i < l-k+1; i++)
    {
        long long num = 0;
        for(int j = 0; j < k; j++)
        {
            long long t = s[i+j]-'0';
            num = num * 10 + t;
        }
        if(check(num))
        {
            for(int j = 0; j < k; j++)
                cout << s[i+j];
            return 0;
        }
    }
    cout << "404";
    return 0;
}