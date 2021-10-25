#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

const int Maxn = 5e3+10;
string temp;

void work()
{
    int minn = 2;
    int opt;
    string s1,s2,s3;
    s1 = s2 = s3 = "";
    ll num1,num2,num3;
    int pos1,pos2,pos3;
    for(int i = 0; i < temp.size(); i++)
    if((temp[i] >= '0' && temp[i] <= '9') || (temp[i] >= 'A' && temp[i] <= 'F'))
    if(temp[i] >= '0' && temp[i] <= '9')
        minn = max(minn,temp[i]-'0'+1);
    else
        minn = max(minn,temp[i] - 'A' + 10+1);
    for(int i = 0; i < temp.size(); i++)
    {
        if(temp[i] == '+')
            opt = 1;
        if(temp[i] == '-')
            opt = 2;
        if(temp[i] == '*')
            opt = 3;
        if(temp[i] == '/')
            opt = 4;
    }
    for(int i = temp.size()-1; i >= 0; i--)
    {
        if(temp[i] == '=')
        {
            pos3 = i;
            break;
        }
        s3 = temp[i] + s3;
    }
    for(int i = pos3-1; i >= 0; i--)
    {
        if(temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/')
        {
            pos2 = i;
            break;
        }
        s2 = temp[i] + s2;
    }
    for(int i = pos2-1; i >= 0; i--)
        s1 = temp[i] + s1;
    for(int i = minn; i <= 16; i++)
    {
        num1 = num2 = num3 = 0;
        ll t1,t2,t3;
        t1 = t2 = t3 = 0;
        for(int j = s1.size()-1; j >= 0; j--)
        {
            ll tempnum;
            if(s1[j] >= '0' && s1[j] <= '9')
                tempnum = s1[j] - '0';
            else
                tempnum = s1[j] - 'A' + 10;
            num1 += tempnum * pow(i,t1++);
        }
        for(int j = s2.size()-1; j >= 0; j--)
        {
            ll tempnum;
            if(s2[j] >= '0' && s2[j] <= '9')
                tempnum = s2[j] - '0';
            else
                tempnum = s2[j] - 'A' + 10;
            num2 += tempnum * pow(i,t2++);
        }
        for(int j = s3.size()-1; j >= 0; j--)
        {
            ll tempnum;
            if(s3[j] >= '0' && s3[j] <= '9')
                tempnum = s3[j] - '0';
            else
                tempnum = s3[j] - 'A' + 10;
            num3 += tempnum * pow(i,t3++);
        }
        if(opt == 1)
        {
            if(num1 + num2 == num3)
            {
                cout << i << endl;
                return;
            }
            continue;
        }
        if(opt == 2)
        {
            if(num1 - num2 == num3)
            {
                cout << i << endl;
                return;
            }
            continue;
        }
        if(opt == 3)
        {
            if(num1 * num2 == num3)
            {
                cout << i << endl;
                return;
            }
            continue;
        }
        if(opt == 4)
        {
            if(num1 / num2 == num3 && num1 % num2 == 0)
            {
                cout << i << endl;
                return;
            }
            continue;
        }
    }
    cout << "-1" << endl;
}

int main()
{
    Buff;
    while(cin >> temp)
        work();
    return 0;
}