#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int n;
string pres,afts;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    pres = "-1";
    afts = "-1";
    string temp;
    for(int i = 1; i <= n; i++)
    {
        int una = 0;
        cin >> temp;
        if(pres != "-1" && temp[0] != '#')
        {
            string nows = "";
            for(int j = 0; temp[j] != '#' && j < temp.size(); j++)
                nows = nows + temp[j];
            for(int j = 0; j < min(nows.size(),pres.size()); j++)
                if(nows[j] != pres[j])
                {
                    // cout << nows[j] << " " << afts[j] << endl;
                    cout << "0";
                    return 0;
                }
            if(nows.size() > pres.size())
                pres = nows;
        }
        if(afts != "-1" && temp[temp.size()-1] != '#')
        {
            string nows = "";
            int ttemp = 0;
            for(int j = temp.size()-1; temp[j] != '#' && j >= 0; j--)
                nows = nows + temp[j];
            for(int j = 0; j < min(nows.size(),afts.size()); j++)
                if(nows[j] != afts[j])
                {
                    // cout << nows[j] << " " << afts[j] << endl;
                    cout << "0";
                    return 0;
                }
            if(afts.size() < nows.size())
                afts = nows;
        }
        // cout << pres << " " << afts << endl;
        if(pres == "-1" && temp[0] != '#')
        {
            pres = "";
            for(int j = 0; temp[j] != '#' && j < temp.size(); j++)
                pres = pres + temp[j];
        }
        if(afts == "-1" && temp[temp.size()-1] != '#')
        {
            afts = "";
            for(int j = temp.size()-1; temp[j] != '#' && j >= 0; j--)
                afts = afts + temp[j];
        }
    }
    cout << "-1";
    return 0;
}
/*
-1
a#b
#ab
ab#ba
pres==
afts==

0
*/