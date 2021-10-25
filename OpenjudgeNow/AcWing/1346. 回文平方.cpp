#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#define Maxn 300

using namespace std;

int b;

/*
1 1
2 10
3 11
4 100
5 101
6 110
7 111
8 1000
9 1001
*/


void check(int num)
{
    int originnum = (int)sqrt(num);
    string strnum = "";
    while(originnum != 0)
    {
        int tempnum = originnum % b;
        char tempchar = tempnum + '0';
        if(tempchar > '9')
            tempchar = 'A' + tempchar - '9' - 1;
        originnum = originnum / b;
        strnum = tempchar + strnum;
    }
    string finnum = "";
    while(num != 0)
    {
        int tempnum = num % b;
        char tempchar = tempnum + '0';
        if(tempchar > '9')
            tempchar = 'A' + tempchar - '9' - 1;
        num = num / b;
        finnum = tempchar + finnum;
    }
    string temps = finnum;
    reverse(finnum.begin(),finnum.end());
    // cout << temps << " " << finnum << endl;
    if(temps == finnum)
        cout << strnum << " " << temps << endl;
}

int main()
{
    cin >> b;
    for(int i = 1; i <= Maxn; i++)
    {
        int tempb = i*i;
        check(tempb);
    }
}
