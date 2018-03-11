#include<stdio.h>
int k , x , y , u , v ;
void determine()
{
	if(u>x&&v>y) 	 printf("NE\n");
	else if(u>x&&v<y)printf("SE\n");
	else if(u<x&&v>y)printf("NO\n");
	else if(u<x&&v<y)printf("SO\n");
	else             printf("divisa\n");
}
int main()
{
	scanf("%d",&k);
	while(k)
	{
		scanf("%d%d",&x,&y);
		while(k--)
		{
			scanf("%d%d",&u,&v);
			determine();
		}
		scanf("%d",&k);
	}
	return 0 ;
}
