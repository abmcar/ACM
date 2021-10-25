#include<iostream>
#include<algorithm>
#define Maxn (int)1e6

using namespace std;

int n;
int num[Maxn];
int qwq[7] = {0,1,1,4,5,1,4};
int nowpos = 1;

bool check(int pos)
{
    for(int i = pos; i <= pos+5; i++)
        if(qwq[i-pos+1] != num[i])
            return false;
    return true;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    num[0] = 1;
    for(int i = 1; i <= n-5; i++)
    {
        int prenum = num[i-1];
        if(check(i))
        {
            num[i+4] = 5;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << num[i] << " ";
    return 0;
}