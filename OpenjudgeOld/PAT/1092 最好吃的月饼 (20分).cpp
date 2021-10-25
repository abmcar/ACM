#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m;

struct yb
{
    long long ans;
    int pos;
};
yb num[2333];
vector<int> p;

bool cmp(yb a,yb b)
{
    if(a.ans != b.ans)
        return a.ans < b.ans;
    return a.pos < b.pos;
}

int main()
{
    cin >> n >> m;
    for(int j = 1; j <= n; j++)
        num[j].pos = j;
    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
    {
        long long tempnum;
        cin >> tempnum;
        num[j].ans += tempnum;
    }
    sort(num+1,num+1+n,cmp);
    cout << num[n].ans << endl;
    for(int j = 1; j <= n; j++)  
    if(num[j].ans == num[n].ans)
        p.push_back(num[j].pos);
    for(int i = 0; i < p.size()-1; i++)
        cout << p[i] << " ";
    cout << p[p.size()-1];
    return 0;
}