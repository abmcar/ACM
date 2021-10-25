#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

const int Maxn = 5e3+10;

struct Key
{
    string key;
    ll used;
    ll lasttime;
    bool ok;
    bool const operator < (Key b) const
    {
        if(used != b.used)
            return used < b.used;
        return lasttime < b.lasttime;
    }
};

map<string,Key> M1;
map<string,string> M2;
int n, k;
int nowSize;

int main()
{
    Buff;
    cin >> k;
    string opt;
    ll i = 0;
    while(cin >> opt)
    {
        i++;
        if(opt == "get")
        {
            string tempKey;
            cin >> tempKey;
            Key temp = M1[tempKey];
            if(!temp.ok)
            {
                cout << "Not Found" << endl;
                continue;
            }
            cout << M2[tempKey] << endl;
            M1[tempKey].used++;
            M1[tempKey].lasttime = i;
        }else
        {
            string tempKey,tempValue;
            cin >> tempKey >> tempValue;
            if(k == 0)
                continue;
            if(nowSize == k)
            {
                Key minKey = {"minn",(int)1e6,(int)1e6,true};
                for(map<string,Key>::iterator it = M1.begin(); it != M1.end(); it++)
                {
                    Key nowKey = it->second;
                    if(!nowKey.ok)
                        continue;
                    minKey = min(minKey,nowKey);
                }
                M1[minKey.key].ok = false;
                M1[minKey.key].used = 0;
                M1[minKey.key].lasttime = 0;
                nowSize--;
            }
            M1[tempKey].ok = true;
            M1[tempKey].key = tempKey;
            M1[tempKey].lasttime = i;
            M1[tempKey].used++;
            M2[tempKey] = tempValue;
            nowSize++;
        }
    }
    return 0;
}