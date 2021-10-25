#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <set>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int n;
set<int> s;

struct Node
{
    int num;
    bool const operator< (const Node b) const
    {
        return num < b.num;
    }
    bool const operator== (const Node b) const
    {
        return true;
    }
};

set<Node> ss;

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        Node tempn;
        tempn.num = temp;
        ss.insert(tempn);
        s.insert(temp);
    }
    // sort(s.begin(),s.end());
    cout << s.size() << endl;
    for(set<Node>::iterator it = ss.begin(); it != ss.end(); it++)
        cout << it->num << " ";
    return 0;
}