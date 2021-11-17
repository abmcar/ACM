
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
using  namespace std;

int main() {
  // For Windows
  //对拍时不开文件输入输出
  //当然，这段程序也可以改写成批处理的形式
  int nowTime = 0;
  while (true) {
    system("gen.exe > test.in");  //数据生成器将生成数据写入输入文件
    clock_t aStr = clock();
    system("test.exe < test.in > test.out");  //获取程序1输出
    clock_t aEnd = clock();
    clock_t bStr = clock();
    system("std.exe < test.in > std.out");  //获取程序2输出
    clock_t bEnd = clock();
    cout << ++nowTime << " " << (aEnd-aStr)*1000/CLOCKS_PER_SEC << " " << (bEnd-bStr)*1000/CLOCKS_PER_SEC << endl;
    if (system("fc test.out std.out")) {
      // 该行语句比对输入输出
      // fc返回0时表示输出一致，否则表示有不同处
      system("pause");  // 方便查看不同处
      return 0;
      // 该输入数据已经存放在test.in文件中，可以直接利用进行调试
    } 
  }
}