#include<iostream>
#include<map>
#include<string>

using namespace std;

string s;
string ans;
bool f = 0;
map<char,bool> m;

int main()
{
    while(getline(cin,s))
    {
        for(int i = 0; i < s.size(); i++)
            if(m[s[i]] == 0)
            {
                if(s[i] == '\n')
                    continue;
                ans = ans + s[i];
                m[s[i]] = 1;
            }
    }
    cout << ans;
    return 0;
}