#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl '\n'

using namespace std;

const int Maxn = 2e5+10;
const ll Mod = 1e9+7;

int t;
struct Int
{
    int a;
    bool const operator < (Int b) const
    {
        return a > b.a;
    }
};

int ori1[Maxn];
int ori2[Maxn];
int tot1[Maxn];
int tot2[Maxn];
int preA[Maxn];
int aftA[Maxn];
int max1,max2;
int n,m;

void work()
{
    vector<int> preN;
    vector<Int> aftN;
    vector<int> preM;
    vector<Int> aftM;
    cin >> n >> m;
    for(int i = 0; i <= m+5; i++)
    {
        ori1[i] = 0;
        ori2[i] = 0;
        tot1[i] = 0;
        tot2[i] = 0;
        preA[i] = 0;
        aftA[i] = 0;
    }
    max1 = max2 = 0;
    stack<Int> S;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        Int Temp;
        cin >> temp;
        Temp.a = temp;
        if(temp > 0)
            preN.push_back(temp);
        else
            S.push(Temp);
    }
    while(!S.empty())
        aftN.push_back(S.top()), S.pop();
    for(int i = 1; i <= m; i++)
    {
        int temp;
        Int Temp;
        cin >> temp;
        Temp.a = temp;
        if(temp > 0)
            preM.push_back(temp);
        else
            S.push(Temp);
        // if(temp > 0)
        // {
        //     if(temp > *preAns.end())
        //         continue;
        //     int pos = lower_bound(preAns.begin(),preAns.end(),temp) - preAns.begin();
        //     int nextdis = *lower_bound(preAns.begin(),preAns.end(),temp);
        //     if(nextdis - temp <= pos)
        //         tot1[pos]++;
        // }else
        // {
        //     if(temp < aftAns.end()->a)
        //         continue;
        //     int pos = lower_bound(aftAns.begin(),aftAns.end(),Temp) - aftAns.begin();
        //     int nextdis = (*lower_bound(aftAns.begin(),aftAns.end(),Temp)).a;
        //     if(nextdis - temp <= pos)
        //         tot2[pos]++;
        // }
    }
    while(!S.empty())
        aftM.push_back(S.top()), S.pop();
    int pos;
    if(preN.size() != 0 && preM.size() != 0)
    {
        int t1 = 2e9;
        preN.push_back(t1);
        pos = lower_bound(preN.begin(),preN.end(),preM[0]) - preN.begin();
        if(pos == preN.size())
            pos--;
        int tt = preM.size();
        int t = preN.size();
        for(int i = 0; i < tt; i++)
        {
            while (preN[pos] < preM[i] && pos < t-1)
                pos++;
            if(preN[pos] == preM[i])
            {
                ori1[i]++;
                if(pos < t-1)
                    pos++;
            }
            for(int j = i; j >= 0; j--)
            {
                if(preM[i] - preM[j] < pos)
                    tot1[i]++;
                else
                    break;
                // cout << j  << " " << M[j] << endl;
            }
        }
    }
    if(aftN.size() != 0 && aftM.size() != 0)
    {
        Int t2;
        t2.a = -2e9;
        aftN.push_back(t2);
        pos = lower_bound(aftN.begin(),aftN.end(),aftM[0]) - aftN.begin();
        if(pos == aftN.size())
            pos--;
        int t = aftN.size();
        int tt = aftM.size();
        for(int i = 0; i < tt; i++)
        {
            while (aftN[pos] < aftM[i] && pos < t-1)
                pos++;
            if(aftM[i].a == aftN[pos].a)
            {
                ori2[i]++;
                if(pos < t-1)
                    pos++;
            }
            for(int j = i; j >= 0; j--)
            {
                if(aftM[j].a - aftM[i].a < pos)
                    tot2[i]++;
                else
                    break;
                // cout << pos << " " << M[j] << endl;
            } 
        }
    }
    for(int i = preM.size() - 1; i >= 0; i--)
        preA[i] = preA[i+1] + ori1[i];
    for(int i = 0; i < preM.size(); i++)
    {
        int temp = preA[i+1];
        // cout << preM[i] << " " << tot1[i] << " " << temp << " " << max1 << endl;
        if(tot1[i]+temp > max1)
            max1 = tot1[i] + temp;
        // max1 = max(max1,tot1[i]+temp);
    }
    for(int i = aftM.size() - 1; i >= 0; i--)
        aftA[i] = aftA[i+1] + ori2[i];
    for(int i = 0; i < aftM.size(); i++)
    {
        int temp = aftA[i+1];
        // cout << aftM[i].a << " " << tot2[i] << " " << temp << " " << max2 << endl;
        // max2 = max(max2,tot2[i]+temp);
        if(tot2[i] + temp > max2)
            max2 = tot2[i] + temp;
    }
    cout << max1+max2 << endl;
}

int main()
{
    Buff;
    // vector<int> temp;
    // temp.push_back(2);
    // temp.push_back(4);
    // temp.push_back(6);
    // temp.push_back(8);
    // temp.push_back(10);
    // cout << (lower_bound(temp.begin(),temp.end(),18) - temp.begin());
    cin >> t;
    while(t--)
        work();
    return 0;
}