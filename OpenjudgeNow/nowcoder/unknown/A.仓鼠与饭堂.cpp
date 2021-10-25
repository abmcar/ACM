#include<iostream>
#include<algorithm>

using namespace std;

int t,n;
double m;
int w[233];

void work()
{
    cin >> n >> m;
    double nowans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
        nowans += w[i];
    }
    if(nowans*0.7 >= m)
    {
        cout << "no" << endl;
        return;
    }
    sort(w+1,w+1+n);
    for(int i = 1; i <= n; i++)
    {
        if(m < w[i])
        {
            cout << "no" << endl;
            return;
        }
        m = m - w[i]*0.7;
    }
    cout << "yes" << endl;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}