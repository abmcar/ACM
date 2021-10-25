#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

bool ok[11];
map<int,int> M;

class Time
{
public:
    int maxH, maxM;
    int nowH, nowM;
    Time(int t1, int t2, int t3, int t4);
    bool check();
    void add();
    void print();
    bool reverse();
};

Time::Time(int t1, int t2, int t3, int t4)
{
    maxH = t1;
    maxM = t2;
    nowH = t3;
    nowM = t4;
}

bool Time::check()
{
    int t1,t2,t3,t4;
    if (nowH == 0)
        t1 = t2 = 0;
    else
        t1 = nowH/10, t2 = nowH%10;
    if (nowM == 0)
        t3 = t4 = 0;
    else
        t3 = nowM/10, t4 = nowM%10;

    if (ok[t1] && ok[t2] && ok[t3] && ok[t4])
    {
        if (nowH < maxH && nowM < maxM)
            return true;
    }
    return false;
}

void Time::add()
{
    nowM++;
    if(nowM >= maxM)
    {
        nowM = 0;
        nowH++;
    }
    if(nowH >= maxH)
    {
        nowH = 0;
    }
    // print();
}

void Time::print()
{
    if (nowH < 10)
        cout << "0";
    cout << nowH << ":";
    if (nowM < 10)
        cout << "0";
    cout << nowM << endl;
}

bool Time::reverse()
{
    int newH,newM;
    newH = newM = 0;
    if (nowH < 10)
    {
        newH = M[nowH];
        newH *= 10;
    }else
    {
        if (nowH == 0)
            newH = 0;
        else
        {
            newH = M[nowH%10];
            newH *= 10;
            newH += M[nowH/10];
        }
    }
    if (nowM < 10)
    {
        newM = M[nowM];
        newM *= 10;
    }else
    {
        if (nowM == 0)
            newM = 0;
        else
        {
            newM = M[nowM%10];
            newM *= 10;
            newM += M[nowM/10];
        }
    }
    int t = newH;
    newH = newM;
    newM = t;
    // cout << nowH << " " << nowM << " " << newH << " " << newM << endl;
    nowH = newH;
    nowM = newM;
    if (check())
        return true;
    return false;
}

int t;

void work()
{
    int t1,t2,t3,t4;
    cin >> t1 >> t2;
    scanf("%d:%d",&t3,&t4);
    Time nowTime(t1,t2,t3,t4);
    while (1)
    {
        if (nowTime.check())
        {
            if (nowTime.reverse())
                break;
            else
                nowTime.reverse();
        }
        nowTime.add();
    }
    nowTime.reverse();
    nowTime.print();
}

int main()
{
    // Buff;
    ok[0] = true;
    ok[1] = true;
    ok[2] = true;
    ok[5] = true;
    ok[8] = true;
    M[0] = 0;
    M[1] = 1;
    M[2] = 5;
    M[5] = 2;
    M[8] = 8;
    cin >> t;
    while (t--)
        work();
    return 0;
}