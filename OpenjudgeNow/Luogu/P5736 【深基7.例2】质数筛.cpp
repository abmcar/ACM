#include<iostream>
#include<vector>

using namespace std;

int n;
bool isprime[(int)1e7+10];
vector<int> primes;

int main()
{
    cin >> n;
    for(int i = 0; i <= 1e7; i++)
        isprime[i] = 1;
    isprime[0] = false;
    isprime[1] = false;
    for(int i = 2; i*i <= (int)1e7; i++)
    {
        if(isprime[i] == false)
            continue;
        primes.push_back(i);
        for(int j = i*i; j <= (int)1e7;j += i)
            isprime[j] = false;
    }
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if(isprime[temp])
            cout << temp << " ";
    }
    return 0;
}