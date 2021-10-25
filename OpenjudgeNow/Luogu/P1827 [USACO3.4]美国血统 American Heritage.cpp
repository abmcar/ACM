#include<iostream>
#include<string>

using namespace std;

string pres,inors;

void work(string pre,string inor)
{
    if(pre.empty())
        return;
    char nowroot = pre[0];
    int k = inor.find(nowroot);
    pre.erase(pre.begin());
    string prel = pre.substr(0,k);
    string prer = pre.substr(k);
    string inorl = inor.substr(0,k);
    string inorr = inor.substr(k+1);
    work(prel,inorl);
    work(prer,inorr);
    cout << nowroot;
}

int main()
{
    cin >> inors >> pres;
    work(pres,inors);
    return 0;
}