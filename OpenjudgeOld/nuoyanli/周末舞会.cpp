#include <iostream>
#include <queue>

using namespace std;

queue<int> a;
queue<int> b;
int n;

int main()
{
    int ta, tb;
    cin >> ta >> tb >> n;
    for (int i = 1; i <= ta; i++)
        a.push(i);
    for (int i = 1; i <= tb; i++)
        b.push(i);
    for (int i = 1; i <= n; i++)
    {
        int nowa = a.front();
        int nowb = b.front();
        a.pop();
        b.pop();
        a.push(nowa);
        b.push(nowb);
        cout << nowa << " " << nowb << endl;
    }
    return 0;
}