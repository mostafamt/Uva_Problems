#include <cstdio>
using namespace std ;
int left[(int)1e5+5] , right[(int)1e5+5];
int main()
{
	int s , b , L , R ;
	while(scanf("%d%d",&s,&b) , s )
	{
		for(int i  = 1 ; i <= s ;++i)
		{
			left[i] = i-1 ;
			right[i] = i+1 ;
		}	
		left[1] =right[s] =  -1 ;
		while(b-->0)
		{
			scanf("%d%d",&L,&R);
			
			if(left[L]!=-1)
				printf("%d ",left[L]);
			else
				printf("* ");

			if(right[R]!=-1)
				printf("%d\n",right[R]);
			else
				printf("*\n");
			
			if(right[R]!=-1)
				left[right[R]] = left[L];
			if(left[L]!=-1)
				right[left[L]] = right[R];
		}
		printf("-\n");
	}
	return 0 ;
}
