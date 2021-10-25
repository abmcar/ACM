#include<iostream>
#include<string>

using namespace std;

int n;
string m;
int ans;

void work(int nowsum,int nowpos)
{
    //cout << nowsum << " " << nowpos << endl;
    int nextnum = m[nowpos]-'0';
    int nextsum1 = nowsum + nextnum;
    int nextsum2 = nowsum - nextnum;
    nowpos++;
    if(m.size() == nowpos)
    {
        if(nextsum1 == n) ans++; 
        if(nextsum2 == n) ans++; 
        return;
    }
    work(nextsum1,nowpos);
    work(nextsum2,nowpos);
}

int main()
{
    while(cin >> m)
    {
        ans = 0;
        cin >> n;
        work(m[0]-'0',1);
        cout << ans << endl;
    }
    return 0;
}