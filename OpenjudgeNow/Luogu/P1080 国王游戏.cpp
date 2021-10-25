#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n;
int nowa[23333];
int nowlen;
int ans[23333];
string finans = "0";

struct gold
{
    int a,b;
    int c;
    void get()
    {
        cin >> a >> b;
        c = a*b;
    }
}g[23333];

bool cmp(gold ta, gold tb)
{
    return ta.c < tb.c;
}

string maxs(string ta,string tb)
{
    if(ta.size() > tb.size())
        return ta;
    else
        return tb;
    return max(ta,tb);
}

void cul1(int num)
{
    int temp[23333];
    for(int i = 1; i <= nowlen; i++)
        temp[i] = 0;
    for(int i = 1; i <= nowlen; i++)
        temp[i] = nowa[i]*num;
    for(int i = 1; i <= nowlen; i++)
    if(temp[i]>=10)
    {
        temp[i+1] += temp[i] / 10;
        temp[i] = temp[i] % 10;
    }
    while(temp[nowlen+1] > 0)
    {
        nowlen++;
        if(temp[nowlen] >= 10)
        {
            temp[nowlen+1] = temp[nowlen] / 10;
            temp[nowlen] = temp[nowlen] % 10;
        }
    }
    for(int i = 1; i <= nowlen; i++)
        nowa[i] = temp[i];
    // cout << num << ' ';
    // for(int i = nowlen; i >= 1; i--)
    //     cout << nowa[i];
    // cout << " " << nowlen;
    // cout << endl;
}

string cul2(int num)
{
    int temp = 0;
    for(int i = 1; i <= nowlen; i++)
        ans[i] = 0;
    for(int i = nowlen; i >= 1; i--)
    {
        temp *= 10;
        temp += nowa[i];
        if(temp >= num)
        {
            ans[i] = temp/num;
            temp = temp % num;
        }
    }
    long long tempans = 0;
    for(int i = nowlen; i >= 1; i--)
    {
        tempans *= 10;
        tempans += ans[i];
    }
    string tempstring = "";
    int newlen = nowlen;
    while(ans[newlen] == 0)
        newlen--;
    for(int i = newlen; i >= 1; i--)
    {
        char tempchar = ans[i] + '0';
        tempstring = tempstring + tempchar;
    }
    // for(int i = nowlen; i >= 1; i--)
    //     cout << nowa[i];
    // cout << " " << num << " ";
    // for(int i = nowlen; i >= 1; i--)
    //     cout << ans[i];
    // cout << " " << tempstring << endl;
    return tempstring;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n+1; i++)
        g[i].get();
    sort(g+2,g+2+n,cmp);
    nowa[1] = nowlen = 1;
    cul1(g[1].a);
    for(int i = 2; i <= n+1; i++)
    {
        finans = maxs(finans,cul2(g[i].b));
        cul1(g[i].a);
    }
    cout << finans;
    return 0;
}