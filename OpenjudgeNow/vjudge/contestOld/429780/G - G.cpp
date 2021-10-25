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
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int t;
string temp;

void work()
{
    cin >> temp;
    map<char,vector<int>> M;
    map<int,bool> Mselect;
    int firpos = 0;
    int nextpos;
    for(int i = 0; i < temp.size(); i++)
        M[temp[i]].push_back(i);
    for(char i = 'z'; i >= 'a'; i--)
    {
        if(M[i].size() == 0)
            continue;
        if(firpos == 0)
        {
            // cout << i << " " << M[i][0] << endl;
            Mselect[M[i][0]] = true;
            firpos = M[i][0];
            continue;
        }
        // cout << *(M[i].end()-1) << ' ' << firpos << endl;
        if(*(M[i].end()-1) < firpos)
        {
            Mselect[M[i][0]] = true;
            firpos = M[i][0];
            // cout << i << endl;
            continue;
        }
        if(*(M[i].end()-1) < nextpos)
        {
            Mselect[*(M[i].end()-1)] = true;
            // nextpos = *(M[i].end()-1);
            // cout << i << endl;
            continue;
        }
        // cout << i << endl;
        nextpos = *upper_bound(M[i].begin(),M[i].end(),nextpos);
        Mselect[nextpos] = true;
    }
    // cout << "pass1" << endl;
    for(map<int,bool>::iterator it = Mselect.begin(); it != Mselect.end(); it++)
        cout << temp[it->first];
    cout << endl;

}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}