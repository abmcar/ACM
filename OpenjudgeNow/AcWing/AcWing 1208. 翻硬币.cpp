#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string strs,endstr;
int cnt;

int main()
{
    cin >> strs >> endstr;
    while(strs != endstr)
    {
        for(int i = 0; i < strs.size(); i++)
            if(strs[i] != endstr[i])
            {
                strs[i] = endstr[i];
                if(strs[i+1] == '*')
                    strs[i+1] = 'o';
                else
                    strs[i+1] = '*';
                cnt++;
            }
    }
    cout << cnt << endl;
    return 0;
}