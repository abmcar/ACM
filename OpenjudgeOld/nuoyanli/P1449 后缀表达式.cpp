#include <iostream>
#include <stack>
#include <string>

using namespace std;

string temp;
stack<int> nums;
int lastnum;

int main()
{
    cin >> temp;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '@')
        {
            cout << nums.top();
            break;
        }
        if (temp[i] >= '0' && temp[i] <= '9')
        {
            int tempnum = temp[i] - '0';
            lastnum = lastnum * 10 + tempnum;
            continue;
        }
        if (temp[i] == '.')
        {
            nums.push(lastnum);
            lastnum = 0;
            continue;
        }
        if (temp[i] == '+')
        {
            int numa = nums.top();
            nums.pop();
            int numb = nums.top();
            nums.pop();
            nums.push(numa + numb);
            continue;
        }
        if (temp[i] == '-')
        {
            int numa = nums.top();
            nums.pop();
            int numb = nums.top();
            nums.pop();
            nums.push(numb - numa);
            continue;
        }
        if (temp[i] == '*')
        {
            int numa = nums.top();
            nums.pop();
            int numb = nums.top();
            nums.pop();
            nums.push(numa * numb);
            //cout << numa << " " << numb << endl;
            continue;
        }
        if (temp[i] == '/')
        {
            int numa = nums.top();
            nums.pop();
            int numb = nums.top();
            nums.pop();
            nums.push(numb / numa);
            continue;
        }
    }
    return 0;
}