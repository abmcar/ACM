#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>

#define Maxn (int)1e7+10

using namespace std;

struct Student
{
    int woman,man;
    int dis;
    friend bool operator < (Student a,Student b)
    {
        if(a.dis == b.dis)
        {
            if(min(a.woman,a.man) == min(b.woman,b.man))
                return max(a.woman,a.man) > max(b.woman,b.man);
            return min(a.woman,a.man) > min(b.woman,b.man);
        }
        return a.dis > b.dis;
    }
};

int n;
char gender[Maxn];
bool used[Maxn];
int level[Maxn];
int k;
vector<int> minn,maxn;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> gender[i];
    for(int i = 1; i <= n; i++)
        cin >> level[i];
    priority_queue<Student,vector<Student> > q;
    for(int i = 1; i < n; i++)
    for(int j = i+1; j <= i+1; j++)
    if(gender[i] != gender[j])
    {
        Student student;
        if(gender[i] == 'B')
        {
            student.man = i;
            student.woman = j;
        }else
        {
            student.woman = i;
            student.man = j;
        }
        student.dis = max(level[i],level[j])-min(level[i],level[j]);
        q.push(student);
    }
    while(!q.empty())
    {
        Student nowstu = q.top();
        q.pop();
        if(used[nowstu.woman] || used[nowstu.man])
            continue;
        minn.push_back(min(nowstu.man,nowstu.woman));
        maxn.push_back(max(nowstu.man,nowstu.woman));
        used[nowstu.woman] = used[nowstu.man] = 1;
        k++;
        int tempmin = min(nowstu.man,nowstu.woman)-1;
        int tempmax = max(nowstu.man,nowstu.woman)+1;
        while(tempmin >= 0 && used[tempmin])
            tempmin--;
        while(tempmax <= n+1 && used[tempmax])
            tempmax++;
        if(tempmin == 0 || tempmax == n+1)
            continue;
        Student student;
        if(gender[tempmin] != gender[tempmax])
        {
            if(gender[tempmin] == 'B')
            {
                student.man = tempmin;
                student.woman = tempmax;
            }else
            {
                student.woman = tempmin;
                student.man = tempmax;
            }
            student.dis = max(level[tempmin],level[tempmax])-min(level[tempmin],level[tempmax]);
            q.push(student);
        }
    }
    cout << k << endl;
    for(int i = 0; i < k; i++)
        cout << minn[i] << " " << maxn[i] << endl;
    return 0;
}