#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std ;

int main()
{
	char s[100];

	while(cin>>s , s[0]!='#')
	{
		int size = strlen(s);
		if(next_permutation(s,s+size))	cout<<s<<"\n" ;
		else							cout<<"No Successor"<<"\n";
	}
	return 0 ;
}

