#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

const int Maxn = 5e3+10;

int n;

struct Time
{
    int h,m,s;
    bool const operator < (Time b) const
    {
        if(h != b.h)
            return h < b.h;
        if(m != b.m)
            return m < b.m;
        if(s != b.s)
            return s < b.s;
    }
    void output()
    {
        cout << h << ":" << m << ":" << s;
    }
};

struct Ipv6
{
    string originString[10];
    string finString[10];
    string ip;
    void turnString()
    {
        for(int i = 1; i <= 8; i++)
        {
            reverse(originString[i].begin(),originString[i].end());
            int temp = 0;
            int cnt = 0;
            for(int j = originString[i].size()-1; j >= 0; j--)
                temp += pow(2,cnt++)*(originString[i][j] - '0');
            string tempString = "";
            do
            {
                char tempChar = '0';
                int tempNum = temp % 16;
                temp = temp / 16;
                if(tempNum >= 10)
                    tempChar = tempNum + 'a' - 10;
                else
                    tempChar = tempNum + '0';
                tempString = tempChar + tempString;
            }while(temp != 0);
            finString[i] = tempString;
        }
        bool fir = false;
        for(int i = 1; i <= 8; i++)
        {
            if(!fir)
            if(i != 1)
            if(finString[i] == "0")
            {
                int tt = 0;
                for(int j = i+1; j <= 8; j++)
                    if(finString[j] == "0")
                        tt++;
                    else
                        break;
                if(tt != 0)
                {
                    i += tt;
                    ip = ip + ":";
                    if(i == 8)
                        ip = ip + ":";
                    fir = true;
                    continue;
                }
            }
            ip = ip + finString[i] + ":";
        }
        ip.erase(ip.end()-1);
        cout << ip << endl;
    }
};

Time firTime = {99,99,99};
Ipv6 ips[Maxn];
Time times[Maxn];
string Ip;

int main()
{
    // Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        Ipv6 tempIp;
        string tempSting;
        Time tempTime;
        scanf("%d:%d:%d--->",&tempTime.h,&tempTime.m,&tempTime.s);
        cin >> tempSting;
        for(int i = 1; i <= 8; i++)
        for(int j = (i-1)*16; j < i*16; j++)
            tempIp.originString[i] = tempSting[j] + tempIp.originString[i];
        tempIp.turnString();
        ips[i] = tempIp;
        times[i] = tempTime;
    }
    cin >> Ip;
    for(int i = 1; i <= n; i++)
        if(ips[i].ip == Ip)
            firTime = min(firTime,times[i]);
    firTime.output();
    return 0;
}