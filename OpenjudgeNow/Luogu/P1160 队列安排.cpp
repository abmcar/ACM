#include<iostream>
#include<list>
#include<algorithm>
#include<cstdio>

using namespace std;

list<int> l;
int n, m;
list<int>::iterator it;
bool used[100010];

int main()
{
    //freopen("a.txt","r",stdin);
    std::ios::sync_with_stdio(false);
    cin >> n;
    l.push_back(1);
    for(int i = 2; i <= n; i++)
    {
        int k,p;
        cin >> k >> p;
        it = lower_bound(l.begin(),l.end(),k);
        if(p == 1)
            l.insert(++it,i);
        else
            l.insert(it,i);
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if(used[x] == 1)
            continue;
        l.remove(x);
        used[x] = 1;
    }
    for(it = l.begin(); it != l.end(); it++)
    if(*it != l.back())
        cout << *it << " ";
    cout << l.back() << endl;
    return 0;
}