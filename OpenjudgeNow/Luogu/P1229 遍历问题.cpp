#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s1,s2;
int ans = 1;

int main()
{
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size()-1; i++)
    {
        string s3 = s1.substr(i,2);
        reverse(s3.begin(),s3.end());
        if(s2.find(s3) != -1)
            ans *= 2;
    }
    cout << ans;
}