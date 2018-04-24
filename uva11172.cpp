#include <iostream>
using namespace std ;

int n , x , y ;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n ;
	while(n--)
	{
		cin>>x>>y ;
		x > y ? cout<<">\n" : x==y ? cout<<"=\n" : cout<<"<\n";
	}
	return 0 ;
}
