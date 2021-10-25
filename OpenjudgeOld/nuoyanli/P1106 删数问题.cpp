#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string s;
int n;

string work(string nows)
{

    string ansstring = nows;
    ansstring.erase(ansstring.begin());
    for(int i = 1; i < nows.size(); i++)
    {
        string tempstring = nows;
        tempstring.erase(tempstring.begin()+i);
        ansstring = min(ansstring,tempstring);
    }
    return ansstring;
}


int main()
{
    cin >> s >> n;
    for(int i = 1; i <= n; i++)
        s = work(s);
    cout << s;
    return 0;
}