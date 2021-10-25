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

char temp;
bool s = false;

int main()
{
    Buff;
    string fir;
    cin >> fir;
    cout << fir << endl;
    string tt;
    cin >> tt;
    cout << tt;
    string codes;
    getline(cin,codes);
    // cout << codes;
    for(int i = 0; i < codes.size(); i++)
    {
        if(codes[i] == ' ')
        {
            cout << codes[i];
            continue;
        }
        if(codes[i] == '{')
        {
            if(codes[i-1] == ')')
            {
                cout << " {" << endl;
                cout << "    ";
                s = true;
            }else
            {
                cout << "{" << endl;
                cout << "    ";
                s = true;
            }
            continue;
        }
        if(codes[i] == ';')
        {
            cout << codes[i] << endl;
            if(codes[i+1] != '}')
                cout << "    ";
            continue;
        }
        if(codes[i] == '+' || codes[i] == '-' || codes[i] == '*' || codes[i] == '/' || codes[i] == '%' || codes[i] == '=')
        {
            if(codes[i-1] != ' ')
                cout << " ";
            cout << codes[i];
            if(codes[i+1] != ' ')
                cout << " ";
            continue;
        }
        cout << codes[i];
    }
}