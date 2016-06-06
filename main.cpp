
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "Court.h" 
#include "Defendant.h"

using namespace std;


int main (int argc, char *argv[])
{
	srand (time(NULL));			
	int n = (argc=='2' ? atoi(argv[1]) : 5);
	 //wspolczynnik skazania

	Defendant defendant;
	Court witness[n];
	Court attorney;
	Court prosecutor;
	Court judge;

	cout << "\nDEFENDANT: " <<defendant.description() << endl<<endl;
		usleep(2000000);
	
	cout << "REPRESENTED BY ATTORNEY: " << "\n";
	cout << attorney.A_description();
		usleep(2000000);

	cout << "PROSECUTOR: " << "\n";
	cout << prosecutor.P_description();
		usleep(2000000);

	cout << "JUDGE:" << "\n";
	cout << judge.J_description();			
		usleep(2000000);

for (int i=0; i<n; i++)
	{
		cout << (i+1) << " witness testimony: " << witness[i].testimony() 
		<< "/100 for the benefit of the accused.\n";
	}


	int x=defendant.rate();

	
	(attorney.experience() > prosecutor.experience()) ? (x-=20) : (x+=20);

	(attorney.rhetoric() > prosecutor.rhetoric()) ? (x-=20) : (x+=20);

	(attorney.isPublic() == 0) ? (x-=50) : (x+=50);

	(prosecutor.indulgence() > 50) ?(x-=15) : (x+=15);

	(judge.indulgence() > 50) ?(x-=25) : (x+=25);

	(judge.corrupt() > 50) ?(x-=100) : (x+=0);


for (int i=0; i<n; i++)
	{
	 (x+=100-(witness[i].testimony()));
	}

	cout << endl << "Rate: " << x <<endl;

	usleep(300000);
	int _sentence;
	
	if (x == 0 || x<0)    	 cout << defendant.name() <<" is innocent! " << endl;
	if (x>=0 && x<50)		
	{
		_sentence = rand()%6;
		cout << defendant.name() << " received " << _sentence << "year prison sentence." <<endl;
	}

	if (x>=50 && x<150)		
		{
		_sentence = 6 + rand()%10;
		cout << defendant.name() << " received " << _sentence << "year prison sentence." <<endl;
		}

	if (x>=150 && x<250)		
	{
		_sentence = 10 + rand()%21;
		cout << defendant.name() << " received " << _sentence << "year prison sentence." <<endl;
	}

	if (x>=250 && x<350)	
	{
		_sentence = 21 + rand()%50;	
		cout << defendant.name() << " received " << _sentence << "year prison sentence." <<endl;
	}


	if (x>=350)		cout << endl<< defendant.name() <<" received a death sentence. :c But don't worry! You can now request your last meal before execution! " << endl;
	


	}

