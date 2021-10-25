#include<iostream>
#include<algorithm>

using namespace std;

int n;
int num[23333];
int totnum1[23];
int totnum2[23];
int tempnum = 1;
void work()
{
    if(n == 0)
        return;
    cout << "Game " << tempnum++ << ":"  << endl;
    for(int i = 0; i <= 10; i++)
        totnum1[i] = 0;
    int temptot[23];
    for(int i = 1; i <= n; i++)
        cin >> num[i],totnum1[num[i]]++;
    for(int i = 0; i <= 10; i++)
        temptot[i] = totnum1[i];
    while(1)
    {
        int corr = 0;
        int sum0 = 0;
        int wrongpos = 0;
        int temp;
    for(int i = 0; i <= 10; i++)
        totnum1[i] = temptot[i];
        for(int i = 0; i <= 10; i++)
            totnum2[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> temp;
            if(temp == 0)
                sum0++;
            totnum2[temp]++;
            if(temp == num[i])
                totnum1[temp]--,totnum2[temp]--,corr++;
        }
        for(int i = 0; i <= 10; i++)
            wrongpos += min(totnum1[i],totnum2[i]);
        if(sum0 == n)
            break;
        cout << "    ";
        cout << "(" << corr << "," << wrongpos << ")" << endl;
    }
}

int main()
{
    while(cin >> n)
        work();
    return 0;
}