#include <stdio.h>
char c , s = 1 ;

int main()
{
	while((scanf("%c" , &c)) == 1)
	{
		if(c=='"')
		{
			if(s==1) 
			{
				printf("%c%c",'`','`');
				s = 0 ;
			}
			else
			{
				printf("%c%c",'\'' , '\'');
				s = 1 ;
			}
		}
		else printf("%c" , c);
	}
	return 0 ;
}
