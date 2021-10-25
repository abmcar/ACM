#include <iostream>

using namespace std;

int tot1, tot2;
int h1, m1, h2, m2;
int ans;

int main()
{
    cin >> h1 >> m1 >> h2 >> m2;
    tot1 = h1 * 60 + m1;
    tot2 = h2 * 60 + m2;
    ans = tot2 - tot1;
    cout << ans / 60 << " " << ans % 60;
    return 0;
}