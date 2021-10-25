#include<iostream>
#include<string>

using namespace std;

int t;
int l0[233];
int r0[233];
int l1[233];
int r1[233];
int q,n;
string s;

void work()
{
    cin >> n >> q;
    cin >> s;
    for(int i = 1; i <= q; i++)
    {
        bool ok = 0;
        int l,r;
        cin >> l >> r;
        if(r-l < 1)
        {
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < l-1; i++)
            if(s[i] == s[l-1])
            {
                ok = 1;
                break;
            }
        if(ok == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        for(int i = r; i < s.size(); i++)
            if(s[i] == s[r-1])
            {
                ok = 1;
                break;
            }
        if(ok == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}