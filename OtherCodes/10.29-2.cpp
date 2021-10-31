// 实验二：顺序表的合并

// 实验要求：设有两个集合A和B，设计算法实验两个集合的合并操作

// 实验步骤：

// 1.定义顺序表存储类型；

// 2.定义顺序表的初始化、插入、输出、查找和 合并等基本操作函数；

// 3.定义主函数运行并测试。*/


/*顺序表类型定义*/

/*初始化函数*/

#include <bits/stdc++.h>
// #include<iostream.h>
using namespace std;

#define MAXSIZE 30

typedef char Datatype;

typedef struct

{

    Datatype *data; //存储数据元素的成员

    int length; //表示顺序表的长度

    int listsize; //表示顺序表的最大长度

} Sqlist;

void Initlist(Sqlist &L)

{

    L.data = new Datatype[MAXSIZE];

    //开辟MAXSIZE个结点空间

    L.length = 0; //将顺序表置为空

    L.listsize = MAXSIZE;

    cout << "输入表长";

    cin >> L.length;

    for (int i = 0; i <= L.length - 1; i++)

        cin >> L.data[i];
}

/*在表L的第i号位置插入新的元素e*/

void Insertlist(Sqlist &L, int i, Datatype e)

{

    for (int j = L.length - 1; j >= i - 1; j--) //部分元素移动

        L.data[j + 1] = L.data[j];

    L.data[i - 1] = e; //元素e插入表中第i号位置

    L.length++;
}

/*输出顺序表*/

void show(Sqlist L)

{
    cout << "顺序表为：";

    for (int i = 0; i <= L.length - 1; i++)

        cout << L.data[i] << "  "; //输出每个元素

    cout << endl;
}

/*查找函数，查找顺序表中值为X的元素*/

int Locat(Sqlist L, Datatype x)

{
    for (int i = 0; i < L.length; i++)

        if (L.data[i] == x)
            return 1; //查找成功则返回1

    return 0;
}

void merge(Sqlist &A, Sqlist B)

{
    int i, k;

    k = A.length; //A表中插入位置初始化

    for (i = 0; i < B.length; i++)

    {
        if (Locat(A, B.data[i]) == 0) //B中第i个元素若存在于A
        {
            A.data[k] = B.data[i];

            k++;
            A.length++;
            // 4 //A表长+1
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

    cout << "合并后";

    show(A);
}
