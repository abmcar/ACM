#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int m,n;
int num[1234][233];
int len[1234];

void cul(int pos)
{
    int temp[233] = {0};
    for(int i = 1; i <= len[pos-1]; i++)
        temp[i] = num[pos-1][i] + num[pos-2][i];
    for(int i = 1; i <= len[pos-1]+1; i++)
    {
        len[pos]++;
        if(i == len[pos-1]+1 && temp[i] == 0)
            len[pos]--;
        if(temp[i] >= 10)
        {
            temp[i+1] += temp[i]/10;
            temp[i] = temp[i]%10;
        }
        num[pos][i] = temp[i];
    }
    // for(int i = len[pos]; i >= 1; i--)
    //     cout << num[pos][i];
    // cout << endl;
    return;
}

int main()
{
    num[1][1] = num[2][1] = len[1] = len[2] = 1;
    cin >> m >> n;
    for(int i = 3; i <= n-m+1; i++)
        cul(i);
    for(int i = len[n-m+1]; i >= 1; i--)
        cout << num[n-m+1][i];
    return 0;
}