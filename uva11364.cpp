#include<stdio.h>
int tc , n , x , min , max ;
int main()
{
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d",&n,&x);
		min = max = x ;
		while(--n)
		{
			scanf("%d",&x);
			if(x>max)max = x ;
			if(x<min)min = x ;
		}
		printf("%d\n",(max-min)*2);
	}
	return 0 ;
}
