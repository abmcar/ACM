#include<iostream>
#include<iomanip>

using namespace std;

double a,b;

int main()
{
    cin >> a >> b;
    cout << fixed << setprecision(3) << (b/a)*100 << "%";
    return 0;
}