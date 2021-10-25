#include<iostream>
#include<vector>
#define Maxn (int)1e4+10

using namespace std;

long long num[Maxn];
bool used[Maxn];
int totnum;
long long totsum;

int main()
{
    while(cin >> num[++totnum])
        totsum += num[totnum];
    totnum--;
    for(int i = 1; i < totnum; i++)
        totsum *= 2;
    // cout << totnum << endl;
    cout << totsum;
    return 0;
}