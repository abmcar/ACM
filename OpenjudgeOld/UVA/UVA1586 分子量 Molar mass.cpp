#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<iomanip>

using namespace std;

int n;
string nows;

map<char,double> m;

void work()
{
    double nowmass,ansmass;
    int nownum = 0;
    nowmass = ansmass = 0;
    cin >> nows;
    for(int i = 0; i < nows.size(); i++)
    {
        // if(nows[i] == 'H')
        // {
        //     if(nowmass == 14.01 || nowmass == 12.01)
        //     {
        //         ansmass += nowmass;
        //         nowmass = 0;
        //     }
        // }
        if(nows[i] >= '0' && nows[i] <= '9')
        {
            nownum *= 10;
            nownum += nows[i]-'0';
            if(i == nows.size()-1 || nows[i+1] < '0' || nows[i+1] > '9')
            {
                ansmass += nowmass * nownum;
                nowmass = 0;
                nownum = 0;
            }
            continue;
        }
        ansmass += nowmass;
        nowmass = m[nows[i]];
    }
    if(nowmass != 0)
        ansmass += nowmass;
    cout << fixed << setprecision(3);
    cout << ansmass << endl;
}

int main()
{
    //freopen("a.out","w",stdout);
    m['C'] = 12.01;
    m['H'] = 1.008;
    m['O'] = 16;
    m['N'] = 14.01;
    cin >> n;
    for(int i = 1; i <= n; i++)
        work();
    return 0;
}