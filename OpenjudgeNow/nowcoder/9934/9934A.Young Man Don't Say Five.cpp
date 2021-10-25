#include<iostream>
#include<string>

using namespace std;

string s;

int main()
{
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '5')
            s[i] = '*';
    cout << s;
    return 0;
}