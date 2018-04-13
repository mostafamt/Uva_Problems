#include <iostream>
#include <string>
#include <vector>
using namespace std ;
typedef vector<string> vs ;
int N , n ;
vs rotate(vs s)
{
	vs r(n,string(n,0));
	for(int y = 0 ; y < n ; y++)
		for(int x = 0 ; x < n ; x++)
			r[x][n-y-1] = s[y][x];
	return r ;
}

int is_match(vs S , vs s , int x0 , int y0)
{
	for(int y = 0 ; y < n ; y++)
		for(int x = 0 ; x < n ; x++)
			if(S[y+y0][x+x0] != s[y][x])
				return 0 ;
	return 1 ;
}

int match(vs S , vs s)
{
	int num = 0 ;
	for(int y = 0 ; y <= N-n ; y++)
		for(int x = 0 ; x <= N-n ; x++)
			num += is_match(S,s,x,y);
	return num ;
}

int main()
{
	while(cin>>N>>n , N || n )
	{
		vs S(N) , s(n) ;
		for(int i = 0 ; i < N ; i++)
			cin>>S[i] ;
		for(int i = 0 ; i < n ; i++)
			cin>>s[i] ;
		vs s1 = rotate(s);
		vs s2 = rotate(s1);
		vs s3 = rotate(s2);
		cout<<match(S,s)<<' '<<match(S,s1)<<' '<<match(S,s2)<<' '<<match(S,s3)<<'\n' ;
	}
	return 0 ;
}
