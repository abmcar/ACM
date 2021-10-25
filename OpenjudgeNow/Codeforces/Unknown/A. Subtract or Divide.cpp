#include <iostream>
#include<algorithm>
using namespace std;

int t;
int n;

void work()
{
    cin >> n;
    if(n == 1)
    {
        cout << "0" << endl;
        return;
    }
    int tempn = n;
    int finans = 0;
    int ans = 0;
    bool flag = 1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            n = i;
            ans++;
            break;
        }
    while (n != 1)
    {
        if (flag == 1)
        {
            n--;
            ans++;
            flag = !flag;
        }
        else
        {
            flag = 1;
            for (int i = 2; i * i <= n; i++)
                if (n % i == 0)
                {
                    n = i;
                    ans++;
                    break;
                }
        }
    }
    finans = ans;
    ans = 1;
    n = tempn-1;
    flag = 1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            n = i;
            ans++;
            flag = 1;
            break;
        }
    while (n != 1)
    {
        if (flag == 1)
        {
            n--;
            ans++;
            flag = !flag;
        }
        else
        {
            flag = 1;
            for (int i = 2; i * i <= n; i++)
                if (n % i == 0)
                {
                    n = i;
                    ans++;
                    break;
                }
        }
    }
    finans = min(finans,ans);
    cout << finans << endl;
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
        work();
    return 0;
}