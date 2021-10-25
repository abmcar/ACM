#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#define Maxn (int)1e6+10

using namespace std;

struct edge
{
    int from,end;
    string data;
    char str,end;
}edges[Maxn];
string node[Maxn];
map<char,vector<int> > cstr,cend;
int father[Maxn];
int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> node[i];
        
    }
}
