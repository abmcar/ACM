#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include<conio.h>
#include<iomanip>

using namespace std;

struct Student
{
    string name;
    int grade1;
    int grade2;
};

bool cmp(Student ta,Student tb)
{
    return ta.grade1 < tb.grade2;
}

struct ListNode
{
    Student student;
    ListNode *next;
};

class List
{
public:
    List();
    List(Student arr[], int size);
    inline void AddNode(ListNode nownode);
    void AddNodeAft(ListNode nownode, ListNode posNode);
    void DeleteNode(int pos);
    inline void AddNodePre(ListNode nownode, ListNode posNode);
    ListNode Search(string s);
private:
    ListNode *head = new ListNode;
    ListNode *last = new ListNode;
};

List::List()
{
    (*head).next = NULL;
    cout << "List create!" << endl;
}

// List::List(Student arr[], int size)
// {
//     (*head).next = NULL;
//     ListNode nowNode = head;
//     for (int i = 0; i < size; i++)
//     {
//         ListNode newNode = new ListNode;
//         newNode.student = arr[i];
//         newNode.next = NULL;
//         nowNode.next = newNode;
//         nowNode = newNode;
//     }
//     cout << "List create!" << endl;
// }

List::List(Student arr[], int size)
{
    (*head).next = NULL;
    ListNode *nowNode = head;
    for (int i = 0; i < size; i++)
    {
        ListNode *newNode = new ListNode;
        newNode->student = arr[i];
        newNode->next = nowNode->next;
        nowNode->next = newNode;
    }
    cout << "List create!" << endl;
}

inline void List::AddNode(ListNode nownode)
{
    ListNode *p = new ListNode;
    ListNode *addnode = new ListNode;
    *addnode = nownode;
    p = head;
    while((*p).next != NULL)
        p = (*p).next;
    (*addnode).next = (*p).next;
    (*p).next = addnode;
    cout << "New node insert!" << endl;
}
inline void List::AddNodeAft(ListNode nownode, ListNode posNode)
{
    ListNode *p = new ListNode;
    ListNode *addnode = new ListNode;
    *addnode = nownode;
    p = head;
    while(p->next != NULL && p->student.name != posNode.student.name)
        p = p->next;
    addnode->next = p->next;
    p->next = addnode;
    cout << "New node insert!" << endl;
}
inline void List::AddNodePre(ListNode nownode, ListNode posNode)
{
    ListNode *p = new ListNode;
    ListNode *addnode = new ListNode;
    *addnode = nownode;
    p = head;
    while(p->next != NULL && p != &posNode)
        p = p->next;
    addnode->next = p->next;
    p->next = addnode;
    cout << "New node insert!" << endl;
}

void List::DeleteNode(int pos)
{
	
    ListNode *p = head->next;
    ListNode *pre = head;
    if(pos <= 0)
    {
        cout << "Error:this node don't exist." << endl;
        getch();
        return;
    }
    int i;
    for(i = 1; i < pos &&p->next != NULL; i++)
    {
        p = pre->next->next;
        pre = pre->next;
    }
    if(i != pos)
    {
        cout << "Error:this node don't exist." << endl;
        getch();
        return;
    }
    pre->next = p->next;
    delete(p);
    cout << "Delete node!" << endl;
}

ListNode List::Search(string s)
{
    ListNode *p = new ListNode;
    p = head;
    int nowpos = 0;
    while((*p).next != NULL && p->student.name != s)
    {
        cout << "search " << p->student.name << endl;
        p = (*p).next;
    }
    if (p->next == NULL && p->student.name != s)
    {
        cout << "Error can find";
    }
    return *p;
}



int main()
{
    std::ios::sync_with_stdio(false);
    Student tempArr[10];
    tempArr[0] = {"01",1,2};
    tempArr[1] = {"02",1,2};
    tempArr[2] = {"03",1,2};
    List newList(tempArr,3);
    cout << newList.Search("03").student.name << endl;
    return 0;
}
