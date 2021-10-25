#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<vector>

using namespace std;

inline int trunint(string tempstring)
{
    int tempnum = 0;
    for(int i = 0; i < tempstring.size(); i++)
    {
        int tt = tempstring[i] - '0';
        tempnum = tempnum*10 + tt;
    }
    return tempnum;
}

struct student
{
    string zkz;
    string cla;
    string tpos;
    string troompos;
    int grade;
    string data;
    int pos,roompos;
    void gets()
    {
        cla = zkz[0];
        troompos = zkz[1];
        troompos = troompos + zkz[2] + zkz[3];
        roompos = trunint(troompos);
        data = zkz[4];
        data = data + zkz[5] + zkz[6] + zkz[7] + zkz[8] + zkz[9];
        tpos =  zkz[10];
        tpos = tpos + zkz[11] + zkz[12];
        pos = trunint(tpos);
        //cout << cla << " " << roompos << " " << data << " " << pos << endl;
    }
};
struct room
{
    int roompos;
    int tot;
};
room rm[2333];
unordered_map<string,vector<student>> m1,m3;
unordered_map<int,vector<student>> m2;

student s[(int)1e4+10];
int n,m;
int used;

inline bool cmp1(student a,student b)
{
    if(a.grade == b.grade)
        return a.zkz < b.zkz;
    return a.grade > b.grade;
}

inline bool cmp2(room a,room b)
{
    if(a.tot == b.tot)
        return a.roompos < b.roompos;
    return a.tot > b.tot;
}


inline void work()
{
    int flag;
    int num;
    cin >> flag;
    if(flag == 1)
    {
        string tempchar;
        cin >> tempchar;
        used++;
        cout << "Case " << used << ": 1 " << tempchar << endl;
        if(m1[tempchar].size() == 0)
        {
            cout << "NA" << endl;
            return;
        }
        sort(m1[tempchar].begin(),m1[tempchar].end(),cmp1);
        for(int i = 0; i < m1[tempchar].size(); i++)
            cout << m1[tempchar][i].zkz << " " << m1[tempchar][i].grade << endl;
        return;
    }
    if(flag == 2)
    {
        cin >> num;
        used++;
        cout << "Case " << used << ": 2 " << num << endl;
        if(m2[num].size() == 0)
        {
            cout << "NA" << endl;
            return;
        }
        int tot = 0;
        for(int i = 0; i < m2[num].size(); i++)
            tot += m2[num][i].grade;
        cout << m2[num].size() << " " << tot << endl;
        return;
    }
    if(flag == 3)
    {
        string num;
        cin >> num;
        used++;
        cout << "Case " << used << ": 3 " << num << endl;
        if(m3[num].size() == 0)
        {
            cout << "NA" << endl;
            return;
        }
        for(int i = 0; i < 1234; i++)
            rm[i].roompos = i;
        for(int i = 0; i < m3[num].size(); i++)
            rm[m3[num][i].roompos].tot++;
        sort(rm+1,rm+1234,cmp2);
        for(int i = 1; i <= m3[num].size()+2; i++)
        if(rm[i].tot == 0)
            break;
        else
            cout << rm[i].roompos << " " << rm[i].tot << endl;
        return;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> s[i].zkz >> s[i].grade;
    for(int i = 1; i <= n; i++)
        s[i].gets();
    for(int i = 1; i <= n; i++)
    {
        m1[s[i].cla].push_back(s[i]);
        m2[s[i].roompos].push_back(s[i]);
        m3[s[i].data].push_back(s[i]);
    }
    for(int i = 1; i <= m; i++)
        work();
    return 0;
}