#include<iostream>

using namespace std;

int week(int y,int m,int d)
{
    if(m == 1 || m == 2)
        m = m + 12,y--;
    return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
}

int n;
int weekday[8];

int main()
{
    cin >> n;
    for(int i = 1900; i < 1900 + n; i++)
    for(int j = 1; j <= 12; j++)
    {
        int w = week(i,j,13);
        weekday[w]++;
    }
    for(int i = 6; i < 6+7; i++)
        cout << weekday[i % 7] << " ";
    return 0;
}