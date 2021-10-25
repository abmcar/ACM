#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int n;
int oddn;
int even;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if(temp % 2 == 1)
            oddn++;
        else
            even++;
    }
    if(n == 1)
    {
        if(oddn == 1)
            cout << "NiuNiu";
        else
            cout << "NiuMei";
        return 0;
    }
    if(even >= 2)
    {
        cout << "NiuMei";
        return 0;
    }
    if(even == 1)
        oddn++;
    if(oddn % 2 == 0)
        cout << "NiuNiu";
    else
        cout << "NiuMei";
    return 0;
}
/*
odd = even + odd
odd = odd * odd

odd + odd = odd
odd + evev = odd

even = even + even
even = even * even
even = even * odd 
even = odd + odd

even + even = even
even + odd = even
odd + odd = even



odd + odd = odd
odd + evev = odd

even + even = even
even + odd = even
odd + odd = even

(0,3) -> (0,2) -> (1,0)
      -> (1,1) -> (1,0)

(0,4) -> (0,3) -> (0,2) -> (1,0)
               -> (1,1) -> (1,0)
      -> (1,2) -> (2,0)
               -> (1,1)


1 5
0 5
1 3
0 3
1 1
0 1

*/