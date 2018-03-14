#include <iostream>
#include <string>
using namespace std ;
int n ;
string s ;
string s_arr[2] = {"one","two"}; 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n ;
	while(n--)
	{
		cin >> s ;
		if(s.size()==5) cout<<"3\n";
		else
		{
			int one = 0 , two = 0 ;
			for(int i = 0 ; i < 3 ; i++)
			{
				if(s_arr[0][i]==s[i]) one++ ;
				if(s_arr[1][i]==s[i]) two++ ;
			}
			if(one>two) cout<<"1\n";
			else        cout<<"2\n";
		}
	}
}