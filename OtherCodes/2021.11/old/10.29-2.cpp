// ʵ�����˳���ĺϲ�

// ʵ��Ҫ��������������A��B������㷨ʵ���������ϵĺϲ�����

// ʵ�鲽�裺

// 1.����˳���洢���ͣ�

// 2.����˳���ĳ�ʼ�������롢��������Һ� �ϲ��Ȼ�������������

// 3.�������������в����ԡ�*/


/*˳������Ͷ���*/

/*��ʼ������*/

#include <bits/stdc++.h>
// #include<iostream.h>
using namespace std;

#define MAXSIZE 30

typedef char Datatype;

typedef struct

{

    Datatype *data; //�洢����Ԫ�صĳ�Ա

    int length; //��ʾ˳���ĳ���

    int listsize; //��ʾ˳������󳤶�

} Sqlist;

void Initlist(Sqlist &L)

{

    L.data = new Datatype[MAXSIZE];

    //����MAXSIZE�����ռ�

    L.length = 0; //��˳�����Ϊ��

    L.listsize = MAXSIZE;

    cout << "�����";

    cin >> L.length;

    for (int i = 0; i <= L.length - 1; i++)

        cin >> L.data[i];
}

/*�ڱ�L�ĵ�i��λ�ò����µ�Ԫ��e*/

void Insertlist(Sqlist &L, int i, Datatype e)

{

    for (int j = L.length - 1; j >= i - 1; j--) //����Ԫ���ƶ�

        L.data[j + 1] = L.data[j];

    L.data[i - 1] = e; //Ԫ��e������е�i��λ��

    L.length++;
}

/*���˳���*/

void show(Sqlist L)

{
    cout << "˳���Ϊ��";

    for (int i = 0; i <= L.length - 1; i++)

        cout << L.data[i] << "  "; //���ÿ��Ԫ��

    cout << endl;
}

/*���Һ���������˳�����ֵΪX��Ԫ��*/

int Locat(Sqlist L, Datatype x)

{
    for (int i = 0; i < L.length; i++)

        if (L.data[i] == x)
            return 1; //���ҳɹ��򷵻�1

    return 0;
}

void merge(Sqlist &A, Sqlist B)

{
    int i, k;

    k = A.length; //A���в���λ�ó�ʼ��

    for (i = 0; i < B.length; i++)

    {
        if (Locat(A, B.data[i]) == 0) //B�е�i��Ԫ����������A
        {
            A.data[k] = B.data[i];

            k++;
            A.length++;
            // 4 //A��+1
        }
    }
}

// void main()
signed main()

{
    Sqlist A, B;

    Initlist(A);

    Initlist(B);

    merge(A, B);

    cout << "�ϲ���";

    show(A);
}
