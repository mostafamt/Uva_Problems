#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std ;
#define MAX 102
#define max 12
struct team
{
private:
	int id , solved , submission , penality  , penalities[max] ;
public:	
	team(){}
	
	team(int ID)
	{
		id = ID ;
		solved = submission = penality = 0 ;
		for(int i = 0 ; i < max ; i++)
			penalities[i] = 0 ;
	}

	int get_id(){
		return this->id ;
	}
	
	int get_solved_problems(){
		return this->solved ;
	}

	int get_penality_time(){
		return this->penality ;
	}

	void accept(int problem , int t)
	{
		if(penalities[problem] != -1){
			penality += penalities[problem] + t ;
			solved++ ;
			penalities[problem] = -1 ;
		}
		submission++ ;
	}

	void inaccept(int problem)
	{
		if(penalities[problem] != -1){
			penalities[problem] += 20 ;
		}
		submission++ ;
	}

	void submit()
	{
		submission++ ;
	}

	void print()
	{
		cout << id << solved << submission << penality << "\n" ;
		for(int i = 0 ; i < max ; i++)
			cout << penalities[i] << "\n" ;
	}

	bool operator < (team other) const{
		if(solved != other.solved)
			if(solved>other.solved)return true ; else return false ;
		else if ( penality != other.penality)
			if(penality>other.penality)return false ; else return true ;
		else
			if(id>other.id) return false ; else return true ;
	}
	bool has_submission(){ return submission > 0 ; }
};

team teams[MAX] ;
int tc ;
int id , problem , t ;
char state ;
string s ;

int main()
{
	stringstream ss ;
	ss.clear();
	getline(cin,s);
	ss << s ;
	ss >> tc ;
	getline(cin,s);
	while(tc--)
	{
		for(int i = 0 ; i < MAX ; i++)
			teams[i] = {i};
		while( getline(cin,s) , !s.empty() )
		{
			ss.clear();
			ss<<s ;
			ss>> id >> problem >> t >> state ;
			switch(state){
				case 'C':
					teams[id].accept(problem,t);
					break ;
				case 'I':
					teams[id].inaccept(problem);
					break ;
				default:
					teams[id].submit();
			}
		}
		sort(teams , teams+MAX);
		for(auto t : teams){
			if(t.has_submission())
				cout<<t.get_id() << " "<< t.get_solved_problems() <<" "<<t.get_penality_time()<<"\n";
		}
		if(tc!=0)
			cout<<"\n";
	}
	return 0 ;	
}
