#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

#define Buff std::ios::sync_with_stdio(false)
#define endl "\n"

using namespace std;

char t1;
int num;

void work()
{
    for(int i = 1; i <= num; i++)
    {
        for(int j = num; j > i; j--)
            cout << " ";
        for(int j = 1; j <= i; j++)
            cout << t1;
        cout << " ";
        for(int j = 1; j <= i; j++)
            cout << t1;
        cout << endl;
    }
}

int main()
{
    Buff;
    while (cin >> t1 >> num)
        work();
    return 0;
}