#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
int usedposition[10];
int totposition[10] = {0, 999, 25, 7, 4, 2, 2, 1};
struct player
{
    string name, position;
    int oldposlevel;
    int oldpos;
    long long banggong, level;
    int poslevel;
    void getpoelevel()
    {
        if (position == "BangZhong")
            poslevel = 1;
        if (position == "JingYing")
            poslevel = 2;
        if (position == "TangZhu")
            poslevel = 3;
        if (position == "ZhangLao")
            poslevel = 4;
        if (position == "HuFa")
            poslevel = 5;
        if (position == "FuBangZhu")
            poslevel = 6;
        if (position == "BangZhu")
            poslevel = 7;
        usedposition[poslevel]++;
    }
    void getposition()
    {
        if (poslevel == 7)
            position = "BangZhu";
        if (poslevel == 6)
            position = "FuBangZhu";
        if (poslevel == 5)
            position = "HuFa";
        if (poslevel == 4)
            position = "ZhangLao";
        if (poslevel == 3)
            position = "TangZhu";
        if (poslevel == 2)
            position = "JingYing";
        if (poslevel == 1)
            position = "BangZhong";
    }
};
player by[233];

bool cmpbg(player a, player b)
{
    if (a.poslevel >= 6 || b.poslevel >= 6)
    {
        if(a.poslevel == b.poslevel)
            return a.oldpos < b.oldpos;
        return a.poslevel > b.poslevel;
    }
    if(a.banggong == b.banggong)
        return a.oldpos < b.oldpos;
    return a.banggong > b.banggong;
}

bool cmplevel(player a, player b)
{
    if (a.poslevel != b.poslevel)
    return a.poslevel > b.poslevel; 
    if (a.level != b.level)
        return a.level > b.level;
    return a.oldpos < b.oldpos;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> by[i].name >> by[i].position >> by[i].banggong >> by[i].level;
        by[i].oldpos = i;
        by[i].getpoelevel();
    }
    sort(by + 1, by + 1 + n, cmpbg);
    int nowpos = 5;
    int nownum = 0;
    for (int i = 4; i <= n; i++)
    {
        if (nownum == 0)
        {
            int usedold = 0;
            for (int j = i; (j < i + totposition[nowpos]) && (j <= n); j++)
            {
                if (by[j].poslevel == nowpos)
                {
                    if (i + usedold != j)
                        swap(by[i + usedold], by[j]);
                    usedold++;
                }
            }
        }
        by[i].oldposlevel = by[i].poslevel;
        by[i].poslevel = nowpos;
        nownum++;
        if (nownum == totposition[nowpos])
        {
            nowpos--;
            nownum = 0;
        }
    }
    sort(by + 1, by + 1 + n, cmplevel);
    for (int i = 1; i <= n; i++)
        by[i].getposition();
    for (int i = 1; i <= n; i++)
        cout << by[i].name << " " << by[i].position << " " << by[i].level << endl;
    return 0;
}