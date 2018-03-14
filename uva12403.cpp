#include <iostream>
using namespace std ;
int tc , m , ans = 0 ;
string s ;
int main()
{
	cin>>tc ;
	while(tc--)
	{
		cin>>s ;
		if(s=="donate")
		{
			cin>>m ; 
			ans+= m ;
		}
		else
			cout<<ans<<"\n";
	}
	return 0;
}