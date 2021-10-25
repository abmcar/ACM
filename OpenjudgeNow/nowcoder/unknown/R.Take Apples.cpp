#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> sum;
int n,t;

void work()
{
    cin >> n;
    for(int i = sum.size()-1; i >= 0; i--)
    {
        if(n >= sum[i])
        {
            if(n == sum[i])
            {
                cout << "YES" << endl;
                return;
            }
            if(n-sum[i] <= i)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
            return;
        }
    }
}

int main()
{
    int nowans = 2;
    int nowk = 2;
    sum.push_back(0);
    while(nowans <= 1e9)
    {
        sum.push_back(nowans);
        nowans+=nowk*2;
        nowk++;
    }
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}