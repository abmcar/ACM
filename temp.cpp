#include <iostream>
#include <cmath>
using namespace std;
const int N = 10010;
void print(int start, int len, int a[]); //���Ժ���
//�ж�����
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
int text[N];          //�տ�ʼ���������, ����������-1
int fact[N];          //�����õĲ���-1����������
int len = 0, ans = 0; //fact���鳤��   ����ֵ
int num;              //�����ֵ
//�ݹ�
void move(int index, int nowin)
{ //index �����±�    nowin ��ǰ�����ĺ�
    //�ݹ��������
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
    //         ans += 1; //������num, ��ans++
    //     }
    //     return;
    // }
    //ȡ
    move(index + 1, nowin + fact[index]);
    //��ȡ
    move(index + 1, nowin);
}
int main()
{
    for (int i = 1; i <= 1001; i++)
    {
        text[i] = pan(i); //��1��ʼ�ж�����
    }
    cin >> num; //����num
    for (int i = 1; i <= num; i++)
    {
        if (text[i] != -1)
        {
            len++;
            fact[len] = text[i]; //ȥ��-1
        }
    }
    print(1, len, fact); //���Դ���
    move(1, 0);          //�ݹ�
    cout << ans << endl; //�����
    return 0;
}
//���Դ���
void print(int start, int len, int a[])
{
    for (int i = start; i <= len; i++)
    {
        cout << "\t" << a[i];
    }
    cout << endl;
}
