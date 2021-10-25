#include<stdio.h>
#include<stdlib.h>
int main(){
	int x[3], a, b, c;
	for (int i = 0; i <=2; i++)
	{
		printf("ÊäÈëµÚ%dÊý×Ö:",(i+1));
		scanf("%d", &x[i]);
		a = x[i] / 100;
		b = x[i] / 10 % 10;
		c = x[i] % 10;
		if (x[i] == 0)
		{
			exit(0);
		}
		else
		{
			if (x[i] == a*a*a + b*b*b + c*c*c)
			{
				printf("yes\n");
			}
			else
			{
			   printf("no\n");
			}
		}
	}	 
}