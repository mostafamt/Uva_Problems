#include <iostream>
#include <string>
using namespace std ;
int L ;
string pre , cur , m ;
bool is_plane1 = true ;
string plane1[] ={"+x","+z","-x","-z"};
string plane2[] ={"+x","-y","-x","+y"};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>L,L)
	{
		pre = "+x";
		for(int i = 1 ; i < L ; ++i)
		{
			cin>>m ;
			if(m=="No")
				cur = pre ;
			else if(pre=="+x")
				cur = m ;
			else if(pre=="-x"&&m=="+y")
				cur="-y";
			else if(pre=="-x"&&m=="-y")
				cur="+y";
			else if(pre=="-x"&&m=="+z")
				cur="-z";
			else if(pre=="-x"&&m=="-z")
				cur="+z";
			else if(pre=="+z"&&m=="+z")
				cur = "-x";
			else if(pre=="+z"&&m=="-z")
				cur = "+x";
			else if(pre=="-z"&&m=="+z")
				cur = "+x";
			else if(pre=="-z"&&m=="-z")
				cur = "-x";
			else if(pre=="+y"&&m=="+y")
				cur = "-x";
			else if(pre=="+y"&&m=="-y")
				cur = "+x";
			else if(pre=="-y"&&m=="+y")
				cur = "+x";
			else if(pre=="-y"&&m=="-y")
				cur = "-x";
			pre = cur ;
		}
		cout<<cur<<"\n";
	}
	return 0 ;
}
