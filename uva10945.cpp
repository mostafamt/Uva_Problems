/* @author : mostafa
 * created : 2018-09-08 00:54
 */
#include <iostream>
#include <string>
using namespace std ;
#define pb push_back

bool is_alpha(char c)
{
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ){
        return true ;
    }
    return false ;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    string line ;
    while( getline(cin,line) , line != "DONE" ){
        string extracted ;
        for(int i = 0 ; i <(int)line.size() ; i++){
            if( is_alpha( line[i] ) ){
                if( line[i] < 'a' ){
                    line[i] += 'a' - 'A' ;
                }
                extracted.pb( line[i] );
            }
        }
        bool status = true ;
        for(int i = 0 , j = (int)extracted.size()-1 ; i < j ; i++ , j-- ){
            if( extracted[i] != extracted[j] ){
                status = false ;
                break ;
            }
        }
        status ? cout << "You won't be eaten!\n" : cout << "Uh oh..\n" ;
    }
	return 0 ;
}
