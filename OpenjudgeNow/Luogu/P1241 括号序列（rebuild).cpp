#include<iostream>
#include<stack>
#include<string>

using namespace std;

string temp;
bool ok[233333];

int main()
{
    cin >> temp;
    for(int i = 0; i <= temp.size(); i++)
    {
        char nowchar = temp[i];
        if(nowchar == ')')
        {
            for(int j = i-1; j >= 0; j--)
            {
                char nextchar = temp[j];
                if(nextchar == '(' && ok[j] != 1)
                {
                    ok[i] = 1;
                    ok[j] = 1;
                    break;
                }
                if(nextchar == '[' && ok[j] != 1)
                    break;
            }
        }
        if(nowchar == ']')
        {
            for(int j = i-1; j >= 0; j--)
            {
                char nextchar = temp[j];
                if(nextchar == '[' && ok[j] != 1)
                {
                    ok[i] = 1;
                    ok[j] = 1;
                    break;
                }
                if(nextchar == '(' && ok[j] != 1)
                    break;
            }
        }
    }
    for(int i = 0; i <= temp.size(); i++)
    {
        char nowchar = temp[i];
        if(ok[i])
        {
            cout << nowchar;
            continue;
        }
        if(nowchar == '(')
            cout << "()";
        if(nowchar == '[')
            cout << "[]";
        if(nowchar == ')')
            cout << "()";
        if(nowchar == ']')
            cout << "[]";
    }
    return 0;
}