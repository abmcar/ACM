//x = y + p*n;
//"��һ��ִ��ż�������Ա�ʾ�ɶ��������ĺ�
//����һ��������һ���������ĺ�"��
//����ѧ�У����������ĳ˻����õ���Ȼ�����ǳ�֮Ϊ������
//���ַ�Ϊ�����ͷ�����������1֮������з�������ʵ���������ı���
#include<iostream>
#include<cmath>

using namespace std;

long long x,y;
int t;

void work()
{
	cin >> x >> y;
	long long z = x-y;
	if(z == 1)
	{
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	return;
}

int main()
{
	cin >> t;
	for(int i = 1; i <= t; i++)
		work();
	return 0;
}
