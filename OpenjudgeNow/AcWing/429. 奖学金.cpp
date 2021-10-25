#include<iostream>
#include<algorithm>
#define Maxn (int)333
using namespace std;

struct Student
{
    int chinese,math,english;
    int tot;
    int pos;
    void get()
    {
        cin >> chinese >> math >> english;
        tot = chinese + math + english;
    }
}student[Maxn];
int n;

bool cmp(Student a,Student b)
{
    if(a.tot != b.tot)
        return a.tot > b.tot;
    if(a.chinese != b.chinese)
        return a.chinese > b.chinese;
    return a.pos < b.pos;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        student[i].get();
        student[i].pos = i;
    }
    sort(student+1,student+1+n,cmp);
    for(int i = 1; i <= 5; i++)
        cout << student[i].pos << " " << student[i].tot << endl;
    return 0;
}