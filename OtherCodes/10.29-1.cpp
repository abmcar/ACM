/*实验三：单链表的表示及实现

实验要求：掌握线性表的链式存储及操作特点

实验步骤：1.定义单链表类型；

2.定义单链表的建表、输出、查找和插入等基本算法函数；

3.编写主函数，运行并测试

*/
#include <bits/stdc++.h>
using namespace std;

typedef char Datatype;

typedef struct lnode
{

    Datatype data;

    lnode *next;

} * Linklist;

/*头插建表*/

void Creatlink(Linklist &L)

{
    Datatype ch;

    lnode *p;

    //   (1) //初始化空表
    L = new (lnode);
    L->next = NULL;
    cout << "输入数据";

    cin >> ch;

    while (ch != '$') //读入‘$’字符则结束

    {


        p = new (lnode); //开辟结点空间
        p->data = ch;
        // (5) //将结点p插入到表头位置
        p->next = L;
        L = p;
        cin >> ch;
    }
}

/*显示链表*/

void Show(Linklist &L)

{
    lnode *p;

    // (6) //初始化指针p的位置
    p = L;
    cout << "单链表为:";

    while (p != NULL) //若p指向的不是空结点

    {

        cout << p->data << "   "; //输出p所指向结点信息

        p = p->next;
        // (8) //p向后移动，指向下一个结点
    }

    cout << endl; //链表输出结束以<回车>结束
}

/*查找函数（返回链表中第i个元素指针）*/

lnode *Locat(Linklist L, int i)

{

    lnode *p;

    int j = 1;

    p = L->next;

    while (p->next != NULL && j < i-1) //查找条件

    {
        p = p->next;

        j++;
    }

    if (p == NULL)
        return NULL;

    else
        return p;
}

/*插入函数*/

void Insert(Linklist &L, int i, Datatype e)

{
    lnode *s, *p;

    p = L;
    // （10）; //定位p的位置
    for (int k = 1; k < i ;k++)
        p = p->next;
    s = new lnode;

    s->data = e;

    s->next = p->next;

    p->next = s;
}

signed main()

{
    Linklist L;
    lnode *p;

    Creatlink(L);

    Show(L);

    Insert(L, 3, 'M');
    cout << Locat(L,3)->data << endl;
    cout << Locat(L,30)->data << endl;
    Show(L);
}
