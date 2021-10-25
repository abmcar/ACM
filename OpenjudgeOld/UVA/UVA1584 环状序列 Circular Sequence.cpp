#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string s;
string mins;
int n;

void work()
{
    cin >> s;
    mins = s;
    for(int i = 1; i < s.size(); i++)
    {
        string temps = "";
        temps = s.substr(i);
        temps = temps + s.substr(0,i);
        // cout << "nowtemps:" << temps << endl;
        mins = min(temps,mins);
    }
    cout << mins << endl;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        work();
    return 0;
}