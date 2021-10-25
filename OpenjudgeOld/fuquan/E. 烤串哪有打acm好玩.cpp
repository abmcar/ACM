#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s;
int ans = 1;

int main()
{
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    for(int j = 0; j <= s.size(); j++)
    {
        string temps = s;
        temps = temps.substr(i,j);
        // cout << temps << endl;
        string revers = temps;
        reverse(revers.begin(),revers.end());
        if(temps == revers)
            ans = max(ans,(int)temps.size());
    }
    cout << ans;
    return 0;
}