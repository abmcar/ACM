#include<iostream>
#include<string>

using namespace std;

int t,n,a;
int num[1000010];
int ans;

void work()
{
    cin >> n >> a;
    for(int i = 1; i <= 1000000; i++)
        num[i] = 0;
    int numlen = 1;
    num[1] = 1;
    ans = 0;
    for(int i = 2; i <= n ;i++)
    {
        for(int j = 1; j <= numlen; j++)
            num[j] *= i;
        for(int j = 1; j <= numlen; j++)
            if(num[j] >= 10)
            {
                int temp = num[j];
                num[j] = num[j] % 10;
                num[j+1] += temp/10;
            }
        while(num[numlen+1] != 0)
        {
            int temp = num[numlen+1];
            num[numlen+1] = temp % 10;
            numlen++;
            num[numlen+1] = temp/10;
        }
    }
    //numlen--;
    for(int i = numlen; i >= 1; i--)
        if(num[i] == a)
            ans++;
    cout << ans << endl;
    return;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}