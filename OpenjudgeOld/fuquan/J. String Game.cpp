#include<iostream>
#include<string>
#define Maxn (int)1e6
using namespace std;

string s;
char premin[Maxn];

int main()
{
    cin >> s;
    premin[0] = s[0];
    for(int i = 1; i < s.size(); i++)
        premin[i] = min(premin[i-1],s[i]);
    for(int i = 0; i < s.size(); i++)
        if(s[i] > premin[i])
            cout << "Ann" << endl;
        else
            cout << "Mike" << endl;
    return 0;
}