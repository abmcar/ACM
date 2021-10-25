#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

map<string, int> M1;
map<string, string> M2;
vector<string> V, oriV;

bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a + b < b + a;
}

int main()
{
    Buff;
    string tempString;
    while (cin >> tempString)
    {
        V.push_back(tempString);
        for (int i = 0; i < tempString.size(); i++)
        {
            string ts = tempString;
            M1[ts.substr(0, i + 1)]++;
        }
    }
    oriV = V;
    sort(V.begin(), V.end(), cmp);
    for (int k = 0; k < V.size(); k++)
    {
        for (int i = 0; i < V[k].size(); i++)
        {
            string ts = V[k];
            ts = ts.substr(0, i + 1);
            // cout << V[k] << " " << ts << endl; 
            if (M1[ts] == 1 || i == V[k].size() - 1)
            {
                M2[V[k]] = ts;
                break;
            }
        }
    }
    for (int i = 0; i < oriV.size(); i++)
        cout << oriV[i] << " " << M2[oriV[i]] << endl;
    return 0;
}