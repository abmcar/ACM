#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>

#define Buff std::ios::sync_with_stdio(false)
#define endl "\n"
#define ll long long
using namespace std;

const int Maxn = 5e3+10;

struct Student
{
    int pos;
    ll val;
    bool const operator < (Student b) const
    {
        if(val == b.val)
            return pos < b.pos;
        return val > b.val;
    }
}student[Maxn];
int ans[Maxn];
int n;

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> student[i].pos >> student[i].val;
    sort(student+1,student+1+n);
    for(int i = 1; i <= n; i++)
        if(student[i].val == student[i-1].val)
            ans[student[i].pos] = ans[student[i-1].pos];
        else
            ans[student[i].pos] = i;
    for(int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}