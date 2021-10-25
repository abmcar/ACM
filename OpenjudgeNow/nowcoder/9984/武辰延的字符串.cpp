#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;


const int Maxn = 1e4+10;
const ll Mod = 1e9+7;
string s,t;
int posA,posB;
int ans;

string subS[Maxn],subT[Maxn];

string getS(int pos)
{
    string temp = subS[pos/50];
    if(pos % 50 == 0)
        return temp;
    for(int i = 1+pos-pos%50; i <= pos; i++)
        temp = temp + s[i-1];
    // cout << "s:" << pos << " " << temp.size() << "\n";
    return temp;
}
string getT(int pos)
{
    string temp = subT[pos/50];
    if(pos % 50 == 0)
        return temp;
    for(int i = 1+pos-pos%50; i <= pos; i++)
        temp = temp + t[i-1];
    // cout << "t:" << pos << " " << temp << "\n";
    return temp;
}

int main()
{
    Buff;
    cin >> s >> t;
    posA = posB = 1;
    int sizeS = s.size();
    int sizeT = t.size();
    string nows = "";
    nows = nows + s[0];
    for(int i = 2; i <= sizeS; i++)
    {
        nows = nows + s[i-1];
        if(i % 50 == 0)
            subS[i/50] = nows;
    }
    nows = "";
    nows = nows + t[0];
    for(int i = 2; i <= sizeT; i++)
    {
        nows = nows + t[i-1];
        if(i % 50 == 0)
            subT[i/50] = nows;
    }
    while (getS(posA) == getT(posA) && posA <= sizeS)
    {
        posB = 1;
        int l = 1;
        int r = sizeS;
        int tans = 0;
        while(l <= r)
        {
            posB = (l+r+1)/2;
            // cout << getS(posA)+getS(posB) << " " << getT(posA+posB) << '\n';
            if(getS(posA)+getS(posB) == getT(posA+posB) && (posA+posB) <= sizeT)
            {
                l = posB+1;
                tans = posB;
            }
            else
                r = posB-1;
        }
        posB = tans;
        // while (s.substr(0,posA)+s.substr(0,posB) == t.substr(0,posA+posB) && (posA+posB) <= t.size())
        //     posB++;
        // while (!(s.substr(0,posA)+s.substr(0,posB) == t.substr(0,posA+posB) && (posA+posB) <= t.size()))
        //     posB--;
        // cout << posA << " " << posB << '\n';
        ans += posB;
        posA++;
    }
    // cout << log(1e5)*1e5 << endl;
    cout << ans;
    return 0;
}