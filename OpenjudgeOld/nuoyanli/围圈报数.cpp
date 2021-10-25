#include<iostream>
#include<list>

using namespace std;

list<int> l;
list<int>::iterator it;
int n,k;

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        l.push_back(i);
    it = l.begin();
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            ++it;
            if(it == l.end())
                it = l.begin();
        }
        cout << *it << " ";
        l.erase(it);
    }
    cout << l.front();
    return 0;
}