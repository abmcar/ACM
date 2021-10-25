#include<iostream>
#include<vector>
#include<string>
#define Maxn (int)1e5+10

using namespace std;

struct Node
{
    int val,leftson,rightson,cut,size;
}node[Maxn];

int q;
int root;
int nowsize;

void add(int nownode,int nowval)
{
    if(nowsize == 0)
    {
        nowsize++;
        root = nowsize;
        node[nowsize].cut++;
        node[nowsize].size++;
        node[nowsize].val = nowval;
        return;
    }
    nowsize++;
    node[nownode].size++;
    if(node[nownode].val == nowval)
    {
        node[nownode].cut++;
        return;
    }
    if(node[nownode].val > nowval)
    {
        if(node[nownode].leftson == 0)
        {
            node[nownode].leftson = nowsize;
            node[nowsize].cut++;
            node[nowsize].size++;
            node[nowsize].val = nowval;
            return;
        }
        add(node[nownode].leftson,nowval);
    }
    if(node[nownode].val < nowval)
    {
        if(node[nownode].rightson == 0)
        {
            node[nownode].rightson = nowsize;
            node[nowsize].cut++;
            node[nowsize].size++;
            node[nowsize].val = nowval;
            return;
        }
        add(node[nownode].rightson,nowval);
    }
}

int findpre(int nownode,int nowval,int nowans)
{
    if(node[nownode].val >= nowval)
    {
        if(node[nownode].leftson == 0)
            return nowans;
        return findpre(node[nownode].leftson,nowval,nowans);
    }
    nowans = max(nowans,node[nownode].val);
    // cout << "findpre " << nownode << " " << nowval << " " << node[nownode].val << endl; 
    if(node[nownode].rightson == 0)
        return nowans;
    return findpre(node[nownode].rightson,nowval,nowans);
}

int findaft(int nownode,int nowval,int nowans)
{
    if(node[nownode].val <= nowval)
    {
        if(node[nownode].rightson == 0)
            return nowans;
        return findaft(node[nownode].rightson,nowval,nowans);
    }
    nowans = min(nowans,node[nownode].val);
    if(node[nownode].leftson == 0)
        return nowans;
    return findaft(node[nownode].leftson,nowval,nowans);
}

int getrank(int nownode,int nowval)
{
    if(nownode == 0)
        return 0;
    if(node[nownode].val == nowval)
        return node[node[nownode].leftson].size;
    if(node[nownode].val > nowval)
        return getrank(node[nownode].leftson,nowval);
    return getrank(node[nownode].rightson,nowval)+node[node[nownode].leftson].size+node[nownode].cut;
}

int getval(int nownode,int nowrank)
{
    int leftsize = node[node[nownode].leftson].size;
    if(nowrank == leftsize+1)
        return node[nownode].val;
    if(nowrank <= leftsize)
        return getval(node[nownode].leftson,nowrank);
    return getval(node[nownode].rightson,nowrank-leftsize-1);
}

int main()
{
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        int tempa,tempb;
        cin >> tempa >> tempb;
        if(tempa == 1)
        {
            cout << getrank(root,tempb)+1 << endl;
            continue;
        }
        if(tempa == 2)
        {
            cout << getval(root,tempb) << endl;
            continue;
        }
        if(tempa == 3)
        {
            cout << findpre(root,tempb,-2147483647) << endl;
            continue;
        }
        if(tempa == 4)
        {
            cout << findaft(root,tempb,2147483647) << endl;
            continue;
        }
        if(tempa == 5)
        {
            add(root,tempb);
            continue;
        }
    }
    return 0;
}