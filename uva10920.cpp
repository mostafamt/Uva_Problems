#include <cstdio>
using namespace std ;

enum directions{TOP,BOTTOM,RIGHT,LEFT};
int x , y , inc , count , sz ;
long long current , p ;
directions dir ;

int main()
{
	while(scanf("%d %lld",&sz , &p) , sz && p )
	{
		x = y = sz/2+1 , inc = 1 , count = 2 , current = 1 , dir = TOP ;
		while(current != p)
		{
			if(current + inc >= p )
				inc = p - current ;
			count-- ;
			current += inc ;
			if(dir==TOP)
			{
				x += inc ;
				dir = LEFT ;
			}
			else if(dir==LEFT)
			{
				y -= inc ;
				dir = BOTTOM ;
			}
			else if(dir == BOTTOM)
			{
				x -= inc ;
				dir = RIGHT ;
			}
			else
			{
				y += inc ;
				dir = TOP ;
			}
			if(count == 0 )
			{
				inc++ ;
				count = 2 ;
			}
		}
		printf("Line = %d, column = %d.\n",x,y);
	}
}
