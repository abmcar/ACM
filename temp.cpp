#include <iostream>
#include <cmath>
using namespace std;
const int N = 10010;
void print(int start, int len, int a[]); //测试函数
//判断素数
int pan(int num)
{
    if (num == 1)
    {
        return -1;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return -1;
        }
    }
    return num;
}
int text[N];          //刚开始存的所有数, 不是素数存-1
int fact[N];          //后面用的不含-1的素数集合
int len = 0, ans = 0; //fact数组长度   最后的值
int num;              //输入的值
//递归
void move(int index, int nowin)
{ //index 数组下标    nowin 当前的数的和
    //递归结束条件
    if (nowin > num || index == len+2)
        return;
    cout << index << " " << nowin << endl;
    if (nowin == num)
    {
        ans++;
        return;
    }
    // if (index == len + 1)
    // {
    //     if (nowin == num)
    //     {
    //         ans += 1; //若等于num, 则ans++
    //     }
    //     return;
    // }
    //取
    move(index + 1, nowin + fact[index]);
    //不取
    move(index + 1, nowin);
}
int main()
{
    for (int i = 1; i <= 1001; i++)
    {
        text[i] = pan(i); //从1开始判断素数
    }
    cin >> num; //输入num
    for (int i = 1; i <= num; i++)
    {
        if (text[i] != -1)
        {
            len++;
            fact[len] = text[i]; //去除-1
        }
    }
    print(1, len, fact); //测试代码
    move(1, 0);          //递归
    cout << ans << endl; //输出答案
    return 0;
}
//测试代码
void print(int start, int len, int a[])
{
    for (int i = start; i <= len; i++)
    {
        cout << "\t" << a[i];
    }
    cout << endl;
}
