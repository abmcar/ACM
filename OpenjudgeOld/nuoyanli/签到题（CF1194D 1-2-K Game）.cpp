#include<iostream>

using namespace std;

int t,n,k;

void work()
{
    cin >> n >> k;
    if(k % 3 != 0)
    {
        if(n % 3 == 0)
            cout << "xue zhang tql!" << endl;
        else
            cout << "xue zhang jiu zhe a?" << endl;
    }else
    {
        n = n % (k+1);
        if(n == k || n % 3 != 0)
            cout << "xue zhang jiu zhe a?" << endl;
        else
            cout << "xue zhang tql!" << endl;;
    }
    return;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}