/*ʵ������������ı�ʾ��ʵ��

ʵ��Ҫ���������Ա����ʽ�洢�������ص�

ʵ�鲽�裺1.���嵥�������ͣ�

2.���嵥����Ľ�����������ҺͲ���Ȼ����㷨������

3.��д�����������в�����

*/
#include <bits/stdc++.h>
using namespace std;

typedef char Datatype;

typedef struct lnode
{

    Datatype data;

    lnode *next;

} * Linklist;

/*ͷ�彨��*/

void Creatlink(Linklist &L)

{
    Datatype ch;

    lnode *p;

    //   (1) //��ʼ���ձ�
    L = new (lnode);
    L->next = NULL;
    cout << "��������";

    cin >> ch;

    while (ch != '$') //���롮$���ַ������

    {


        p = new (lnode); //���ٽ��ռ�
        p->data = ch;
        // (5) //�����p���뵽��ͷλ��
        p->next = L;
        L = p;
        cin >> ch;
    }
}

/*��ʾ����*/

void Show(Linklist &L)

{
    lnode *p;

    // (6) //��ʼ��ָ��p��λ��
    p = L;
    cout << "������Ϊ:";

    while (p != NULL) //��pָ��Ĳ��ǿս��

    {

        cout << p->data << "   "; //���p��ָ������Ϣ

        p = p->next;
        // (8) //p����ƶ���ָ����һ�����
    }

    cout << endl; //�������������<�س�>����
}

/*���Һ��������������е�i��Ԫ��ָ�룩*/

lnode *Locat(Linklist L, int i)

{

    lnode *p;

    int j = 1;

    p = L->next;

    while (p->next != NULL && j < i-1) //��������

    {
        p = p->next;

        j++;
    }

    if (p == NULL)
        return NULL;

    else
        return p;
}

/*���뺯��*/

void Insert(Linklist &L, int i, Datatype e)

{
    lnode *s, *p;

    p = L;
    // ��10��; //��λp��λ��
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
