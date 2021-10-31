/*实验六：稀疏矩阵的三元组表结构的实现

实验要求：掌握三元组表的定义及实现

实验步骤：

1.定义三元组表存储结构；

2.定义函数，实现三元组表的创建及输出等

   操作；

3.编写主函数，运行并测试*/

/*定义三元组表存储类型*/

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

    // 1
    cin >> T.rows >> T.cols >> T.terms;

    cout << "输入非零元素的行号、列号和值" << endl;

    for (int i = 1; i <= T.terms; i++)
        cin >> T.data[i].i >> T.data[i].j >> T.data[i].e;
    // 2
}

void Show_Matrix(Matrix T)

{
    int i;

    cout << "稀疏矩阵的三元组表为:" << endl;
    for (i = 1; i <= T.terms; i++)
        cout << T.data[i].i << " " << T.data[i].j << " " << T.data[i].e << endl;
    // 3
}

void Show_array(Matrix T)

{
    int i, j;

    int array[MAXSIZE][MAXSIZE];

    /*初始化二维矩阵*/

    for (i = 1; i <= T.rows; i++)

        for (j = 1; j <= T.cols; j++)

            array[i][j] = 0;

    for (i = 1; i <= T.terms; i++)
        array[T.data[i].i][T.data[i].j] = T.data[i].e;
    // 7 //赋值非零元素于二维矩阵中

    /*输出二维矩阵*/

    cout << "稀疏二维矩阵：" << endl;

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
