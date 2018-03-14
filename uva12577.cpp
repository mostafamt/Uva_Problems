#include <iostream>
using namespace std ;
string s ;
int i = 1 ;
int main()
{
	while(cin>>s)
	{
		if(s=="*") break ;
		cout<<"Case "<<i++<<": "; 
		if(s=="Hajj") cout <<"Hajj-e-Akbar\n";
		else          cout <<"Hajj-e-Asghar\n";
	}
	return 0;
}