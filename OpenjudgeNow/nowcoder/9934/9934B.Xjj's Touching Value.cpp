#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

double t,a,b,n;
double pow2[32];

int gcd(int a,int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

void work()
{
    double nowmax = -1e8;
    int maxu,maxd;
    cin >> a >> b >> n;
    for(int i = 0; i <= n; i++)
    {
        if((a*i+b)/pow2[i] > nowmax)
        {
            nowmax = (a*i+b)/(double)pow2[i];
            maxu = a*i+b;
            maxd = pow2[i];
        }
    }
    int temp = gcd(maxu,maxd);
    maxu = maxu / temp;
    maxd = maxd / temp;
    if(maxd < 0)
        maxd *= -1, maxu *= -1;
    if(maxu % maxd == 0)
    {
        cout << maxu / maxd << endl;
        return;
    }
    if(maxu == 0)
    {
        cout << '0' << endl;
        return;
    }
    cout << maxu << "/" << maxd << endl;
}

int main()
{
    pow2[0] = 1;
    for(int i = 1; i <= 30; i++)
        pow2[i] = pow2[i-1]*2;
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}