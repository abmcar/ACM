#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> s;

int main()
{
    string temp;
    while(cin >> temp)
        if(temp == "0")
            break;
        else
            s.push_back(temp);
    for(int i = s.size()-1; i >= 0; i--)
    {
        cout << s[i];
        cout << " ";
    }
    return 0;
}