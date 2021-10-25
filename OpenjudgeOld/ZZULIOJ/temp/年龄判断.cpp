#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n <= 3)
		cout << "infant";
	if(n >= 4 && n <= 12)
		cout << "child";
	if(n >= 13 && n <= 18)
		cout << "youngster";
	if(n >= 19 && n <= 25)
		cout << "youth";
	return 0;
}
