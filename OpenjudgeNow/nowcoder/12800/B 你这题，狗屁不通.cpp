#include<iostream>
#include<ctime>
using namespace std;

int main(){
	time_t  now =time(0);
	char  * data = ctime(&now);
	
	// cout << now  <<endl;  //输出一个时间戳    1970 年 1 月 1 日以来经过的秒数。如果系统没有时间，则返回 .1。
	// cout << data <<endl;  //字符串时间  
	
	//转换UTC时间
	//  tm *gmtime(const time_t *time);  该函数返回一个指向 time 的指针，time 为 tm 结构，用协调世界时（UTC）也被称为格林尼治标准时间（GMT）表示。
	tm  * gm =gmtime(&now);
	// char * asctime ( const struct tm * time );  该函数返回一个指向字符串的指针，字符串包含了 time 所指向结构中存储的信息，返回形式为：day month date hours:minutes:seconds year\n\0。
	data = asctime(gm);
	// cout << data <<endl;   //UTC 时间  
    cout << "2021/4/1 ";
    for(int i = 11; i <= 18; i++)
        cout << data[i];
	return 0;
}

