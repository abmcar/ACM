
/*ʵ������ϡ��������Ԫ���ṹ��ʵ��
ʵ��Ҫ��������Ԫ���Ķ��弰ʵ��
ʵ�鲽�裺
1.������Ԫ���洢�ṹ��
2.���庯����ʵ����Ԫ���Ĵ����������
   ������
3.��д�����������в�����*/
/*������Ԫ���洢����*/
// #include <iostream.h>
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
    cin >> T.rows >> T.cols >> T.terms;
    cout << "�������Ԫ�ص��кš��кź�ֵ" << endl;
    for (k = 1; k <= T.terms; k++)
        cin >> T.data[k].i >> T.data[k].j >> T.data[k].e;
}

void Show_Matrix(Matrix T)
{
    int k;
    cout << "ϡ��������Ԫ���Ϊ:" << endl;
    cout << T.rows << '\t' << T.cols << '\t' << T.terms << endl;
    for (k = 1; k <= T.terms; k++)
        cout << T.data[k].i << '\t' << T.data[k].j << '\t' << T.data[k].e << endl;
}

void Show_array(Matrix T)
{
    int i, j, k;
    int array[MAXSIZE][MAXSIZE];
    /*��ʼ����ά����*/
    for (i = 1; i <= T.rows; i++)
        for (j = 1; j <= T.cols; j++)
            array[i][j] = 0;
    for (k = 1; k <= T.terms; k++)
        array[T.data[k].i][T.data[k].j] = T.data[k].e; //��ֵ����Ԫ���ڶ�ά������
                                                       /*�����ά����*/
    cout << "ϡ���ά����" << endl;
    for (i = 1; i <= T.rows; i++)
    {
        for (j = 1; j <= T.cols; j++)
            cout << array[i][j] << "  ";
        cout << endl;
    }
    cout << endl;
}

/*����ת��*/
void Transpose(Matrix &M, Matrix T)
{
    int i, j, k = 1;
    M.rows = T.cols;
    M.cols = T.rows;
    M.terms = T.terms;
    //��ʾ���в��ҵķ�Χ
    for (j = 1; j <= T.cols; j++)
        for (i = 1; i <= T.terms; i++)
            //����ǰɨ���к���Ԫ���к����
            if (T.data[i].j == j)
            {
                M.data[k].i = T.data[i].j;
                M.data[k].j = T.data[i].i;
                M.data[k].e = T.data[i].e;
                // 3 //��T�ĵ�i��Ԫ��ת�ú����M��k��λ����
                k++;
            }
}
/*����ת��*/
void Fasttrans(Matrix &M, Matrix T)
{
    int i, k = 1, q;
    int num[MAXSIZE];
    int cpot[MAXSIZE];
    M.rows = T.cols;
    M.cols = T.rows;
    M.terms = T.terms;
    /*��ʼ��num   cpot����*/
    for (i = 1; i <= T.cols; i++)
    {
        num[i] = 0;
        cpot[i] = 0;
    }
    /*����num����*/
    for (i = 1; i <= T.terms; i++)
        num[T.data[i].j]++;
    /*����cpot����*/
    cpot[1] = 1;
    for (i = 2; i <= T.cols; i++)
        cpot[i] = cpot[i - 1] + num[i - 1];

    /*˳��ɨ����Ԫ���T*/
    for (i = 1; i <= T.terms; i++)
    {
        q = T.data[i].j;
        k = cpot[q]; //����T�е�i��Ԫ����M�е�λ��k
        M.data[k].i = T.data[i].j;
        M.data[k].j = T.data[i].i;
        M.data[k].e = T.data[i].e;
        cpot[q]++; //�޸�cpot�µ�λ��
    }
}

signed main()
{
    Matrix T, M;
    Creat_Matrix(T);
    Show_Matrix(T);
    Transpose(M, T);
    Show_array(M);
    Fasttrans(M, T);
    Show_array(T);
    Show_array(M);
}