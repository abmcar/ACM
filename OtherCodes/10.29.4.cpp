
/*实验六：稀疏矩阵的三元组表结构的实现
实验要求：掌握三元组表的定义及实现
实验步骤：
1.定义三元组表存储结构；
2.定义函数，实现三元组表的创建及输出等
   操作；
3.编写主函数，运行并测试*/
/*定义三元组表存储类型*/
// #include <iostream.h>
#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 30
typedef struct
{
    int i, j;
    int e;
} Triple; //定义三元组类型
typedef struct
{
    Triple data[MAXSIZE];
    int rows, cols, terms;
} Matrix; //定义三元组表类型

void Creat_Matrix(Matrix &T)
{
    int k;
    cout << "输入矩阵的行数、列数和非零元素个数:" << endl;
    cin >> T.rows >> T.cols >> T.terms;
    cout << "输入非零元素的行号、列号和值" << endl;
    for (k = 1; k <= T.terms; k++)
        cin >> T.data[k].i >> T.data[k].j >> T.data[k].e;
}

void Show_Matrix(Matrix T)
{
    int k;
    cout << "稀疏矩阵的三元组表为:" << endl;
    cout << T.rows << '\t' << T.cols << '\t' << T.terms << endl;
    for (k = 1; k <= T.terms; k++)
        cout << T.data[k].i << '\t' << T.data[k].j << '\t' << T.data[k].e << endl;
}

void Show_array(Matrix T)
{
    int i, j, k;
    int array[MAXSIZE][MAXSIZE];
    /*初始化二维矩阵*/
    for (i = 1; i <= T.rows; i++)
        for (j = 1; j <= T.cols; j++)
            array[i][j] = 0;
    for (k = 1; k <= T.terms; k++)
        array[T.data[k].i][T.data[k].j] = T.data[k].e; //赋值非零元素于二维矩阵中
                                                       /*输出二维矩阵*/
    cout << "稀疏二维矩阵：" << endl;
    for (i = 1; i <= T.rows; i++)
    {
        for (j = 1; j <= T.cols; j++)
            cout << array[i][j] << "  ";
        cout << endl;
    }
    cout << endl;
}

/*按列转置*/
void Transpose(Matrix &M, Matrix T)
{
    int i, j, k = 1;
    M.rows = T.cols;
    M.cols = T.rows;
    M.terms = T.terms;
    //表示按列查找的范围
    for (j = 1; j <= T.cols; j++)
        for (i = 1; i <= T.terms; i++)
            //若当前扫描列号与元素列号相等
            if (T.data[i].j == j)
            {
                M.data[k].i = T.data[i].j;
                M.data[k].j = T.data[i].i;
                M.data[k].e = T.data[i].e;
                // 3 //将T的第i个元素转置后存在M的k号位置上
                k++;
            }
}
/*快速转置*/
void Fasttrans(Matrix &M, Matrix T)
{
    int i, k = 1, q;
    int num[MAXSIZE];
    int cpot[MAXSIZE];
    M.rows = T.cols;
    M.cols = T.rows;
    M.terms = T.terms;
    /*初始化num   cpot数组*/
    for (i = 1; i <= T.cols; i++)
    {
        num[i] = 0;
        cpot[i] = 0;
    }
    /*计算num数组*/
    for (i = 1; i <= T.terms; i++)
        num[T.data[i].j]++;
    /*计算cpot数组*/
    cpot[1] = 1;
    for (i = 2; i <= T.cols; i++)
        cpot[i] = cpot[i - 1] + num[i - 1];

    /*顺序扫描三元组表T*/
    for (i = 1; i <= T.terms; i++)
    {
        q = T.data[i].j;
        k = cpot[q]; //计算T中第i个元素在M中的位置k
        M.data[k].i = T.data[i].j;
        M.data[k].j = T.data[i].i;
        M.data[k].e = T.data[i].e;
        cpot[q]++; //修改cpot新的位置
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