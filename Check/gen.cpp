#include <bits/stdc++.h>

using namespace std;

mt19937 mt_rand(chrono::system_clock::now().time_since_epoch().count());

const int N = 1e5 + 1;

int main()
{
    // freopen("1.txt", "w", stdout);
    srand(time(0));
    cout << 1 << endl;
    for (int i = 1; i <= 1; i++)
    {
        int n = rand() % 200000 + 1;
        cout << n << endl;
        for (int j = 1; j <= n; j++)
            cout << rand() % 1000000 << " ";
        cout << endl;
    }
    return 0;
}
