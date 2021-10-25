#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int a,b,c,d;
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int years[2333];
int finday;
int normalyear;

int getyear(int ye)
{
    if(years[ye] != 0)
        return years[ye];
    if(ye % 100 == 0)
    {
        if(ye % 400 == 0)
        {
            years[ye] = normalyear+1;
            return years[ye];
        }
        years[ye] = normalyear;
        return years[ye];
    }
    if(ye % 4 == 0)
    {
        years[ye] = normalyear+1;
        return years[ye];
    }
    years[ye] = normalyear;
    //cout << ye << " " << years[ye] << endl;
    return years[ye];
}

long long getday(int ta,int tb,int tc)
{
    long long nowday = 0;
    for(int i = 1900; i < ta; i++)
        nowday += getyear(i);
    for(int i = 1; i < tb; i++)
        nowday += month[i];
    if(tb > 2)
    {
        if(getyear(ta) == normalyear+1)
            nowday++;
    }
    nowday += tc;
    
    return nowday;
}

void work()
{
    char temp;
    cin >> temp;
    cin >> b >> temp >> c >> d;
    if(d == 0)
        return;
    long long tday = getday(a,b,c);
    long long lessday = finday - tday+1;
    //cout << lessday <<endl;
    long long add = 0;
    if(lessday % 7 <= 2)
    {
        lessday = lessday - lessday % 7;
        add = 0;
    }else
    {
        add = lessday % 7 - 2;
        lessday = lessday - lessday % 7;
    }
    lessday = lessday - (lessday/7)*2 + add;
    if(lessday >= d)
        cout << "huahua yyds" << endl;
    else
        cout << "~~~>_<~~~" <<endl;
    //cout << lessday <<endl;
}
int main()
{
    for(int i = 1; i <= 12; i++)
        normalyear += month[i];
    finday = getday(2020,12,13);
    //cout << normalyear <<endl;
    while(cin >> a)
        work();
    return 0;
}