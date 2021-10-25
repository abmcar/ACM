#include<iostream>

using namespace std;

int n;
int num[23333];
int preans[23333];
int t;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        preans[i] += preans[i-1]+num[i];
    }
    for(int i = n+1; i <= 12345; i++)
        preans[i] += preans[i-1]+num[i];
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int p,q;
        cin >> p >> q;
        cout << preans[q]-preans[p-1] << endl;
    }
    return 0;
}