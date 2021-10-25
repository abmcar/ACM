#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

struct brackets
{
    char data;
    int pos;
};

stack<brackets> s1;
stack<brackets> s2;
vector<int> adds1,adds2;
string temp;
string ans;

void workleft()
{
    for(int i = 0; i < temp.size(); i++)
    {
        brackets t;
        t.data = temp[i];
        t.pos = i;
        if(t.data == '(')
            s1.push(t);
        if(t.data == '[')
            s2.push(t);
        if(t.data == ')')
        {
            if(!s1.empty())
                s1.pop();
            
        }
        if(t.data == ']')
        if(!s2.empty())
            s2.pop();
    }
    while(!s1.empty())
    {
        brackets t = s1.top();
        adds1.push_back(t.pos);
        s1.pop();
    }
    while(!s2.empty())
    {
        brackets t = s2.top();
        adds2.push_back(t.pos);
        s2.pop();
    }
    int added1 = 0;
    int added2 = 0;
    //cout << "pass" << endl;
    while(added1 != adds1.size() || added2 != adds2.size())
    {
        //cout << added1 << " " << added2 << endl;
        if(adds1.size() == 0)
        {
            ans.insert(adds2[added2]+1,"]");
            added2++;
            continue;
        }
        if(adds2.size() == 0)
        {
            ans.insert(adds1[added1]+1,")");
            added1++;
            continue;
        }
        if((adds1[added1] > adds2[added2] && added1 == adds1.size()) || (added2 == adds2.size()))
        {
            ans.insert(adds1[added1]+1,")");
            added1++;
        }else
        {
            ans.insert(adds2[added2]+1,"]");
            added2++;
        }
    }
}

void clear()
{
    adds1.clear();
    adds2.clear();
    while(!s1.empty())
        s1.pop();
    while(!s2.empty())
        s2.pop();
}

void workright()
{
    temp = ans;
    //cout << temp << endl;
    for(int i = temp.size()-1; i >= 0; i--)
    {
        brackets t;
        t.data = temp[i];
        t.pos = i;
        if(t.data == ')')
            s1.push(t);
        if(t.data == ']')
            s2.push(t);
        if(t.data == '(')
        if(!s1.empty())
            s1.pop();
        if(t.data == '[')
        if(!s2.empty())
            s2.pop();
    }
    stack<int> t1,t2;
    while(!s1.empty())
    {
        brackets t = s1.top();
        t1.push(t.pos);
        s1.pop();
    }
    while(!t1.empty())
    {
        adds1.push_back(t1.top());
        t1.pop();
    }
    while(!s2.empty())
    {
        brackets t = s2.top();
        t2.push(t.pos);
        s2.pop();
    }
    while(!t2.empty())
    {
        adds2.push_back(t2.top());
        t2.pop();
    }
    int added1 = 0;
    int added2 = 0;
    while(added1 != adds1.size() || added2 != adds2.size())
    {
        //cout << added1 << " " << added2 << endl;
        if(adds1.size() == 0)
        {
            ans.insert(adds2[added2],"[");
            added2++;
            continue;
        }
        if(adds2.size() == 0)
        {
            ans.insert(adds1[added1],"(");
            added1++;
            continue;
        }
        if((adds1[added1] < adds2[added2] && added1 == adds1.size()) || (added2 == adds2.size()))
        {
            ans.insert(adds1[added1],"(");
            added1++;
        }else
        {
            ans.insert(adds2[added2],"[");
            added2++;
        }
    }
}

int main()
{
    cin >> temp;
    ans = temp;
    workright();
    clear();
    workleft();
    cout << ans << endl;
    return 0;
}