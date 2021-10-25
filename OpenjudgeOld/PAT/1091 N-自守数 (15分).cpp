#include<iostream>

using namespace std;

int m,n;
int num;

void work()
{
    cin >> num;
    for(int i = 1; i < 10; i++)
    {
        int tempnum1 = num;
        int tempnum2 = num*num*i;
        bool ok = 1;
        //cout << num << "  " << tempnum2 << endl;
        while(tempnum1 != 0)
        {
            int lastnum1 = tempnum1 % 10;
            int lastnum2 = tempnum2 % 10;
            tempnum1 = tempnum1 / 10;
            tempnum2 = tempnum2 / 10;
            if(lastnum1 != lastnum2)
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            cout << i << " " << num*num*i << endl;
                return;
        }
    }
    cout << "No" << endl;
    return;
}

int main()
{
    cin >> m;
    for(int i = 1; i <= m; i++)
        work();
    return 0;
}