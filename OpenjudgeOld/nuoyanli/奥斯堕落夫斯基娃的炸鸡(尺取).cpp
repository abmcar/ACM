#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

bool primes[(int)2e5+10];
int nums[(int)2e5+10];
int f[(int)2e5+10];
int nowprime;
int ans[(int)2e5+10];
int t;
int maxn;

bool isprime(int num)
{
    for(int i = 2; i*i <= num; i++)
        if(num % i == 0)
            return 0;
    return 1;
}

void prework()
{
    for(int i = 1; i <= 2e5+10; i++)
        primes[i] = isprime(i);
    for(int i = 1; i <= 2e5+10; i++)
        if(primes[i] == 1)
            nums[++nowprime] = i;
    return;
}

void work()
{
    int tempnum;
    cin >> tempnum;
    int left,right,nowsum;
    left = right = 2;
    nowsum = 0;
    int ans = 0;
    while(1)
    {
        //cout << left << " " << right << " " << nowsum << endl;          
        while(right < tempnum && nowsum < tempnum)
        {
            right++;
            if(primes[right])
                continue;
            nowsum += right;
        }
        if(left == right)
            break;
        if(nowsum == tempnum)
            ans++;
        left++;
        while(primes[left] && left < tempnum)
            left++;
        nowsum = nowsum - left;
    }
    cout << ans << endl;
    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    prework();
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}