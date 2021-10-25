#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

int n;
int tot,maxn,minn;
double avg;

int main()
{
    minn = 1e9;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        maxn = max(maxn,temp);
        minn = min(minn,temp);
        tot+=temp;
    }
    avg = (double)tot/n;
    cout << fixed << setprecision(2) << avg/1.00 << setprecision(0) << " " << maxn << " " << minn;
    return 0;
}