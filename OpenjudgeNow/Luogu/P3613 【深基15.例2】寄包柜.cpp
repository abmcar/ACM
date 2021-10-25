#include<iostream>
#include<map>

using namespace std;

int n,q;
map<int,int> g[(int)1e5+10];

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= q; i++)
    {
        int a,b,c,d;
        cin >> a;
        if(a == 1)
        {
            cin >> b >> c >> d;
            g[b][c] = d;
            continue;
        }else
        {
            cin >> b >> c;
            cout << g[b][c] << endl;
        }
    }
    return 0;
}