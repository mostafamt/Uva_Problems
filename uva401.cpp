#include <iostream>
#include <string>
using namespace std ;
#define MAX 125

int main()
{
	string s ;
	char rev[MAX];
	rev['A']='A';rev['E']='3';rev['H']='H';rev['I']='I';rev['J']='L';rev['L']='J';
	rev['M']='M';rev['O']='O';rev['S']='2';rev['T']='T';rev['U']='U';rev['V']='V';
	rev['W']='W';rev['X']='X';rev['Y']='Y';rev['Z']='5';rev['1']='1';rev['2']='S';
	rev['3']='E';rev['5']='Z';rev['8']='8';
	while( getline(cin,s) , !s.empty())
	{
		int len = s.length();
		bool palindrome = true ;
		bool mirror = true ;
		for(int i = 0 ; i <= len/2 ; i++)
		{
			if(s[i]!=s[len-i-1])
				palindrome = false ;
			
			if( rev[(int)s[i]] != s[len-i-1] && mirror ){
				mirror = false ;
				if(s[i] == 'O' && s[len-i-1]=='0')
					mirror = true ;
			}
			if(!palindrome&&!mirror)
				break ;
		}
		cout << s << " -- ";
		if(palindrome && mirror)
			cout <<"is a mirrored palindrome.\n\n";
		else if(palindrome)
			cout << "is a regular palindrome.\n\n";
		else if(mirror)
			cout<<"is a mirrored string.\n\n";
		else
			cout<<"is not a palindrome.\n\n";
	}
}
