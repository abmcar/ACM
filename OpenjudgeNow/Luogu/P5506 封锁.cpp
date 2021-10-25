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

int n, t;


class UAV
{
public:
    int pos;
    int posX, posY;
    int h, f;
    int atk;
    int def;
    int mat;
    int mdf;
    int hp;
    int fix;
    bool alive;
    string opt;
    UAV(int t1, int t2, string t3);
    void getPosition(int t1, int t2, int t3, int t4);
    void getSkillValue(int t1, int t2, int t3, int t4, int t5);
    void moveU();
    void moveD();
    void moveL();
    void moveR();
    void moveForward();
    void skillFix();
    void skillShoot();
    void skillLase();
    bool checkShoot(int shooterPos);
    bool checkLase(int laserPos);
    void damageShoot(int shooterPos);
    void damageLase(int laserPos);
    void updata(int nowT);
};

UAV uav[123];

struct Dis
{
    int pos;
    double dis;
    Dis(int i, int j)
    {
        UAV t1 = uav[i];
        UAV t2 = uav[j];
        double x1 = t1.posX;
        double x2 = t2.posX;
        double y1 = t1.posY;
        double y2 = t2.posY;
        dis = (x1 - x2) * (x1 - x2) + (y1 - y2) + (y1 - y2);
        pos = j;
    }
    bool const operator< (Dis b) const
    {
        return dis > b.dis;
    }
};

UAV::UAV(int t1, int t2, string t3)
{
    pos = t1;
    if (t2 <= 0)
    {
        alive = false;
        hp = t2;
    }else
    {
        alive = true;
        hp = t2;
    }
    opt = t3;
}

void UAV::getPosition(int t1, int t2, int t3, int t4)
{
    posX = t1;
    posY = t2;
    h = t3;
    f = t4;
}

void UAV::getSkillValue(int t1, int t2, int t3, int t4, int t5)
{
    atk = t1;
    def = t2;
    mat = t3;
    mdf = t4;
    fix = t5;
}

void UAV::moveU()
{
    if (h == 4)
        return;
    h++;
}

void UAV::moveD()
{
    if (h == 0)
        return;
    h--;
}

void UAV::moveL()
{
    if (f == 7)
        f = 0;
    else
        f++;
}

void UAV::moveR()
{
    if (f == 0)
        f = 7;
    else
        f--;
}

void UAV::moveForward()
{
    if (f == 0)
    {
        posX++;
    }
    if (f == 1)
    {
        posX++;
        posY++;
    }
    if (f == 2)
    {
        posY++;
    }
    if (f == 3)
    {
        posX--;
        posY++;
    }
    if (f == 4)
    {
        posX--;
    }
    if (f == 5)
    {
        posX--;
        posY--;
    }
    if (f == 6)
    {
        posY--;
    }
    if (f == 7)
    {
        posX++;
        posY--;
    }
}

void UAV::skillFix()
{
    if (!alive)
        return;
    hp += fix;
}

void UAV::skillShoot()
{
    priority_queue<Dis> Q;
    for (int i = 1; i <= n; i++)
    {
        if (uav[i].checkShoot(pos))
        {
            Dis temp(pos,i);
            Q.push(temp);
        }
    }
    if (!Q.empty())
        uav[Q.top().pos].damageShoot(pos);
}

void UAV::skillLase()
{
    for (int i = 1; i <= n; i++)
    {
        if (uav[i].checkLase(pos))
            uav[i].damageLase(i);
    }
}

bool UAV::checkShoot(int shooterPos)
{
    UAV shooter = uav[shooterPos];
    if (!shooter.alive)
        return false;
    if (h != shooter.h)
        return false;
    int disX = shooter.posX - posX;
    int disY = shooter.posY - posY;
    if (disX == 0 && disY == 0)
        return false;
    if (disX == 0)
    {
        if (disY > 0)
        {
            if (f == 2)
                return true;
            return false;
        }
        if (disY < 0)
        {
            if (f == 6)
                return true;
            return false;
        }
    }
    if (disY == 0)
    {
        if (disX > 0)
        {
            if (f == 0)
                return true;
            return false;
        }
        if (disX < 0)
        {
            if (f == 4)
                return true;
            return false;
        }
    }
    if (disX > 0 && disY > 0 && disX == disY)
    if (f == 1)
        return true;
    if (disX < 0 && disY < 0 && disX == -1*disY)
    if (f == 3)
        return true;
    if (disX < 0 && disY < 0 && disX == disY)
    if (f == 5)
        return true;
    if (disX > 0 && disY < 0 && disX == -1*disY)
    if (f == 7)
        return true;
    return false;
}

bool UAV::checkLase(int laserPos)
{
    UAV laser = uav[laserPos];
    if (!laser.alive)
        return false;
    if (h != laser.h)
        return false;
    int disX = laser.posX - posX;
    int disY = laser.posY - posY;
    if (disX == 0 && disY == 0)
        return false;
    if (disX == 0)
    {
        if (disY > 0)
        {
            if (f == 2)
                return true;
            return false;
        }
        if (disY < 0)
        {
            if (f == 6)
                return true;
            return false;
        }
    }
    if (disY == 0)
    {
        if (disX > 0)
        {
            if (f == 0)
                return true;
            return false;
        }
        if (disX < 0)
        {
            if (f == 4)
                return true;
            return false;
        }
    }
    if (disX > 0 && disY > 0 && disX == disY)
    if (f == 1)
        return true;
    if (disX < 0 && disY < 0 && disX == -1*disY)
    if (f == 3)
        return true;
    if (disX < 0 && disY < 0 && disX == disY)
    if (f == 5)
        return true;
    if (disX > 0 && disY < 0 && disX == -1*disY)
    if (f == 7)
        return true;
    return false;
}

void UAV::damageShoot(int shooterPos)
{
    int nowDamage = uav[shooterPos].atk - def;
    if (nowDamage < 0)
        nowDamage = 0;
    hp = hp - nowDamage;
    if (hp < 0)
        alive = false;
}

void UAV::damageLase(int laserPos)
{
    int nowDamage = uav[laserPos].mat - mdf;
    if (nowDamage < 0)
        nowDamage = 0;
    hp = hp - nowDamage;
    if (hp < 0)
        alive = false;
}

void UAV::updata(int nowT)
{
    if (!alive)
        return;
    char nowOpt = opt[nowT-1];
    if (nowOpt == 'N')
        return;
    if (nowOpt == 'U')
        moveU();
    if (nowOpt == 'D')
        moveD();
    if (nowOpt == 'L')
        moveL();
    if (nowOpt == 'R')
        moveR();
    if (nowOpt == 'F')
        skillFix();
    if (nowOpt == 'A')
        skillShoot();
    if (nowOpt == 'M')
        skillLase();
}

void init()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        int temp[12];
        string stringOpt;
        for (int j = 1; j <= 11; j++)
            cin >> temp[i];
        cin >> stringOpt;
    }
}

int main()
{
    Buff;
    return 0;
}