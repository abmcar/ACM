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

const int Maxn = 1e5+10;
const ll Mod = 1e9+7;

struct Student
{
    int num;
    string name;
    bool const operator < (Student b) const
    {
        return num < b.num;
    }
}student[Maxn];
int n;

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> student[i].name >> student[i].num;
    sort(student+1,student+1+n);
    cout << student[n].name << endl;
    return 0;
}