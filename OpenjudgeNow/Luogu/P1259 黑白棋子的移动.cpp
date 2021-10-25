#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

string s;
int n;

void work(int num)
{
    if(num == 4)
    {
        // cout << "oooo****--";
        // for(int i = 1; i <= n-4; i++)
        //     cout << "o*";
        // cout << endl;
        cout << "ooo--***o*";
        for(int i = 1; i <= n-4; i++)
            cout << "o*";
        cout << endl;
        cout << "ooo*o**--*";
        for(int i = 1; i <= n-4; i++)
            cout << "o*";
        cout << endl;
        cout << "o--*o**oo*";
        for(int i = 1; i <= n-4; i++)
              cout << "o*";
        cout << endl;
        cout << "o*o*o*--o*";
        for(int i = 1; i <= n-4; i++)
            cout << "o*";
        cout << endl;
        cout << "--o*o*o*o*";
        for(int i = 1; i <= n-4; i++)
            cout << "o*";
        cout << endl;
        return;
    }
    swap(s[num],s[2*num+1]);
    swap(s[num-1],s[2*num]);
    cout << s << endl;
    swap(s[num],s[2*num-1]);
    swap(s[num-1],s[2*num-2]);
    cout << s << endl;
    work(num-1);
    return;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        s = s + "o";
    for(int i = 1; i <= n; i++)
        s = s + "*";
    s = s + "--";
    cout << s << endl;
    work(n);
    return 0;
}