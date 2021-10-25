#include<iostream>
#include<map>

using namespace std;

map<int,int> student;
int n,m;
int nowpos;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        student[++nowpos] = temp;
    }
    for(int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        cout << student[temp] << endl;
    }
    return 0;
}