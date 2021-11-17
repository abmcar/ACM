#include <bits/stdc++.h>

using namespace std;

mt19937 mt_rand(chrono::system_clock::now().time_since_epoch().count());

const int N = 1e5 + 1;

int main()
{
    // freopen("1.txt", "w", stdout);
    srand(time(0));
    int t = rand() % 1234;
    cout << t << endl;
    while (t--)
    {
        int a = rand() % (int)1e9;
        int b = rand() % (int)1e9;
        cout << a << " " << b << endl;
    }
    return 0;
}
