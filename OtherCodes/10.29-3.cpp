/*ʵ������ϡ��������Ԫ���ṹ��ʵ��

ʵ��Ҫ��������Ԫ���Ķ��弰ʵ��

ʵ�鲽�裺

1.������Ԫ���洢�ṹ��

2.���庯����ʵ����Ԫ���Ĵ����������

   ������

3.��д�����������в�����*/

/*������Ԫ���洢����*/

#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 30

typedef struct
{

    int i, j;

    int e;

} Triple; //������Ԫ������

typedef struct

{

    Triple data[MAXSIZE];

    int rows, cols, terms;

} Matrix; //������Ԫ�������

void Creat_Matrix(Matrix &T)

{
    int k;

    cout << "�������������������ͷ���Ԫ�ظ���:" << endl;

    // 1
    cin >> T.rows >> T.cols >> T.terms;

    cout << "�������Ԫ�ص��кš��кź�ֵ" << endl;

    for (int i = 1; i <= T.terms; i++)
        cin >> T.data[i].i >> T.data[i].j >> T.data[i].e;
    // 2
}

void Show_Matrix(Matrix T)

{
    int i;

    cout << "ϡ��������Ԫ���Ϊ:" << endl;
    for (i = 1; i <= T.terms; i++)
        cout << T.data[i].i << " " << T.data[i].j << " " << T.data[i].e << endl;
    // 3
}

void Show_array(Matrix T)

{
    int i, j;

    int array[MAXSIZE][MAXSIZE];

    /*��ʼ����ά����*/

    for (i = 1; i <= T.rows; i++)

        for (j = 1; j <= T.cols; j++)

            array[i][j] = 0;

    for (i = 1; i <= T.terms; i++)
        array[T.data[i].i][T.data[i].j] = T.data[i].e;
    // 7 //��ֵ����Ԫ���ڶ�ά������

    /*�����ά����*/

    cout << "ϡ���ά����" << endl;

    for (i = 1; i <= T.rows; i++)

    {
        for (j = 1; j <= T.cols; j++)

            cout << array[i][j] << "  ";

        cout << endl;
    }
}

signed main()

{

    Matrix T;

    Creat_Matrix(T);

    Show_Matrix(T);

    Show_array(T);
}
