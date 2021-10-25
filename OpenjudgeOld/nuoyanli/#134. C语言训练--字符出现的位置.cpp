#include<stdio.h>

int pos = -1;

int main()
{
    int n;
    char a[66665],x;
    char temp;
    scanf("%d",&n);
    scanf("%c",&temp);
    for(int i=1; i <= n; i++)
        scanf("%c",&a[i]);
    scanf("%c",&temp);
    scanf("%c",&x);
    for(int j=1; j<=n; j++)
    {
        if(a[j]==x)
        {
        	pos = j-1;
            break;
        }
    }
    printf("%d",pos);
    return 0;
}
