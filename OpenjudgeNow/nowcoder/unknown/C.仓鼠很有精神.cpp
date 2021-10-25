#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;
string s;
char lastchar = '0';

bool check(char tempchar)
{
    if(tempchar == 'a' || tempchar == 'e' || tempchar == 'i' || tempchar == 'o' || tempchar == 'u')
        return true;
    return false;
}

void work()
{
    cin >> s;
    int finans = 0;
    int nowans = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(check(s[i]))
        {
            nowans++;
            continue;
        }
        finans = max(finans,nowans);
        nowans = 0;
    }
    finans = max(finans,nowans);
    cout << finans << endl;
}


int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        work();
    return 0;
}