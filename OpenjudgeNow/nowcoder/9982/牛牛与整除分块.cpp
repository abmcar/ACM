#include <cstdio>
#include <set>
#include <iostream>

using namespace std;
int n;
set<int> se;

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;++i)se.insert(n/i);
        for(set::reverse_iterator i=se.rbegin();i!=se.rend();++i)
        {
            printf("%d ",*i);
        }
        printf("\n");
    }
    return 0;
}