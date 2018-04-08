#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
int tc , n , v , len ;
double ans ;
char c ;
string line ;
map<char,int> mymap ;
int main()
{
	scanf("%d\n",&tc);
	while(tc--)
	{
		ans = 0.0 ;
		mymap.clear();
		scanf("%d\n",&n);
		while(n--)
		{
			scanf("%c %d\n",&c,&v);
			mymap[c] = v ;
		}
		scanf("%d\n",&n);
		while(n-->0)
		{
			getline(cin,line);
			len = line.size();
			rep(i,len)
				ans += mymap.find(line[i])->second ;
		}
		printf("%.2f$\n",ans/100);
	}
	return 0 ;
}

