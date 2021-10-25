#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <map>

#define Buff std::ios::sync_with_stdio(false)
#define endl "\n"

using namespace std;

int n;
string lw = "";
int maxn;
map<string,int> M;
string tt[(int)1e5+10];

int main()
{
    Buff;
    cin >> n;
    // if(n == 0)
    // {
    //     cout << "name" << endl;
    //     return 0;
    // }
    for(int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        tt[i] = temp;
        M[temp]++;
        if(M[temp] > maxn)
        {
            maxn = M[temp];
            lw = temp;
        }
    }
    for(int i = 1; i <= n; i++)
        if(M[tt[i]] == maxn)
        {
            cout << tt[i];
            return 0;
        }
}