#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

class MySet
{
private:
    int father[Maxn];
    int size;

public:
    MySet(int size)
    {
        this->size = size;
        for (int i = 1; i <= size; i++)
            father[i] = i;
    }
    int find(int son)
    {
        if (father[son] == son)
            return son;
        father[son] = find(father[son]);
        return father[son];
    }
    bool inSet(int num1, int num2)
    {
        return find(num1) == find(num2);
    }
    void unionNum(int num1, int num2)
    {
        int f1 = find(num1);
        int f2 = find(num2);
        father[f1] = f2;
    }
};

int n, m;

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    MySet mySet = *(new MySet(n));
    while (m--)
    {
        char opt;
        int num1, num2;
        cin >> opt >> num1 >> num2;
        if (opt == 'M')
            mySet.unionNum(num1,num2);
        if (opt == 'Q')
            cout << (mySet.inSet(num1,num2) ? "Yes" : "No") << endl;
    }
    return 0;
}