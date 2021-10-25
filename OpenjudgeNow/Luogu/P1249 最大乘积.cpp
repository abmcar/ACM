#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int n;
int nowans;
vector<int> vnum;
long long num[2333333];

void cul(long long t)
{
    for(int j = 1; j <= 500; j++)
        num[j] *= t;
    for(int j = 1; j <= 500; j++)
        if(num[j] >= 10)
        {
            int temp = num[j];
            num[j] = num[j] % 10;
            num[j+1] += temp/10;
        }
}

int main()
{
    cin >> n;
    num[1] = 1;
    int p = n;
    int b = 2; 
    while (p != 0)
    {
        if(b == 65536)
        {
            cul(b);
            p--;
            continue;
        }
        if(p % 2 == 1)
            cul(b);
        b = b*b;
        p = p / 2;
    }
    num[1]--;
    int temp = 0;
    cout << (int)(n*log10(2)+1) << endl;
    for(int i = 500; i >= 1; i--)
    {
        cout << num[i];
        temp++;
        if(temp % 50 == 0)
            cout << endl;
    }
    return 0;
}