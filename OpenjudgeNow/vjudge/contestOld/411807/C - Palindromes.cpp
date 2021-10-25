#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

map<char,char> rever;
string s;

void prework()
{
    rever['A'] = 'A';
    rever['B'] = '`';
    rever['C'] = '`';
    rever['D'] = '`';
    rever['E'] = '3';
    rever['F'] = '`';
    rever['G'] = '`';
    rever['H'] = 'H';
    rever['I'] = 'I';
    rever['J'] = 'L';
    rever['K'] = '`';
    rever['L'] = 'J';
    rever['M'] = 'M';
    rever['N'] = '`';
    rever['O'] = 'O';
    rever['P'] = '`';
    rever['Q'] = '`';
    rever['R'] = '`';
    rever['S'] = '2';
    rever['T'] = 'T';
    rever['U'] = 'U';
    rever['V'] = 'V';
    rever['W'] = 'W';
    rever['X'] = 'X';
    rever['Y'] = 'Y';
    rever['Z'] = '5';
    rever['1'] = '1';
    rever['2'] = 'S';
    rever['3'] = 'E';
    rever['4'] = '`';
    rever['5'] = 'Z';
    rever['6'] = '`';
    rever['7'] = '`';
    rever['8'] = '8';
    rever['9'] = '`';
}

void work()
{
    bool ispalindrome = 0;
    bool ismillor = 0;
    string revers = s;
    string mirs = s;
    reverse(revers.begin(),revers.end());
    // cout << revers << endl;
    if(s == revers)
        ispalindrome = 1;
    for(int i = 0; i < s.size(); i++)
        mirs[i] = rever[s[i]];
    if(mirs == revers)
        ismillor = 1;
    if(ispalindrome == 1 && ismillor == 1)
        cout << s << " -- is a mirrored palindrome." << endl;
    if(ispalindrome == 0 && ismillor == 0)
        cout << s << " -- is not a palindrome." << endl;
    if(ispalindrome == 1 && ismillor == 0)
        cout << s << " -- is a regular palindrome." << endl;
    if(ispalindrome == 0 && ismillor == 1)
        cout << s << " -- is a mirrored string." << endl;
    cout << endl;
}

int main()
{
    prework();
    while(cin >> s)
        work();
}