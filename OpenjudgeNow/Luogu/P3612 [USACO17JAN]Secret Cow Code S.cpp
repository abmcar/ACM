#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string s;
long long n;
long long totsize;
/*
COW
COW W CO
COWWCO OCOWWC
*/
char work(long long nowpos)
{
    if(nowpos <= s.size())
        return s[nowpos-1];
    long long halfsize = totsize / 2;
    if(nowpos == halfsize+1)
        nowpos = halfsize;
    if(nowpos > halfsize)
        nowpos = nowpos-halfsize-1;
    totsize = halfsize;
    return work(nowpos);
}

int main()
{
    cin >> s >> n;
    totsize = s.size();
    while(totsize < n)
        totsize *= 2;
    cout << work(n);
}