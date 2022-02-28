#include <bits/stdc++.h>

using namespace std;

int n, ans;
string oriString;

signed main()
{
    string temp;
    cin >> n >> temp;
    for (char it : temp)
    {
        if (it == 'z' || it == 'f' || it == 'c')
            oriString = oriString + it;
    }
    while (oriString.find("zfc") != string::npos)
    {
        int pos = oriString.find("zfc");
        int pp = oriString.find("c");
        oriString = oriString.erase(pos, 3);
        if (pos > pp)
            oriString = oriString.erase(0, pp);
        ans++;
    }
    cout << ans << endl;
    return 0;
}