#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

int main()
{
    string t1 = "104";
    string t2 = "txt";
    string t3 = "neredeeixiuzihs";
    cout << t1 << t2;
    for(int i = t3.size()-1; i >= 0; i--)
        cout << t3[i];
    return 0;
}