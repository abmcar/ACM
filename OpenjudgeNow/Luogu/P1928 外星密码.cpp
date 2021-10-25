#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s;

string jy(int pos)
{
    // cout << pos << endl;
    string nexts = "";
    int num = 0;
    if(s[pos] == '[')
        pos++;
    while(s[pos]>='0'&&s[pos]<='9')
    {
        int tempnum = s[pos]-'0';
        num = num * 10;
        num = num + tempnum;
        s[pos] = '!';
        pos++;
    }
    if(num == 0)
        num = 1;
    // cout << "numpos" << pos << " " << num << endl;
    for(;s[pos]!=']' && pos < s.size();pos++)
    {
        if(s[pos] == '!')
            continue;
        if(s[pos] == '[')
        {
            nexts = nexts + jy(pos);
            continue;
        }
        nexts += s[pos];
        s[pos] = '!';
    }
    s[pos] = '!';
    string fins = "";
    for(int i = 1; i <= num; i++)
        fins += nexts;
    return fins;
}

int main()
{
    cin >> s;
    cout << jy(0);
    for(int i = 1; i <= s.size(); i++)
        if(s[i] != '!')
            cout << jy(i);
    return 0;
}