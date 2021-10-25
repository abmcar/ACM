#include<iostream>

using namespace std;

int t;
int n;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        int j = 2;
        bool ok = 1;
        for(int i = 2; i <= 1e9; i+=j)
        {
            if(i == n)
            {
                ok = 0;
                cout << "YES" << endl;
                break;
            }
            j++;
        }
        if(ok)
            cout << "NO" << endl;
    }
    return 0;
}