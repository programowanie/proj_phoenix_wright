#include "Defendant.h"
#include <cstdlib>
#include <fstream>
#include <iterator>

vector <string> Defendant::names;
vector <string> Defendant::crimes;

void Defendant::initNames()
{
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

void Defendant::initCrimes()
{
	ifstream file("crimes.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(crimes));
	file.close();
}
Defendant::Defendant()
{
	static int amountOfNames = (initNames(), names.size());
	_name = names[rand() % amountOfNames];

	static int amountOfCrimes = (initCrimes(), crimes.size());
	_crime = crimes [rand() % amountOfCrimes];

	_alibi = rand() % 101;
	_evidence = rand() % 101;
	_criminal_record = rand() % 101;
	_behaviour = rand() % 101;
	_plead_guilty = rand() % 2;
}
	int Defendant::rate()
{
	return (_alibi + _evidence + _criminal_record + _behaviour + 50*_plead_guilty);
}

 string Defendant::description()
{
	string guilty = (_plead_guilty == 0) ? "NO" : "YES";

	return _name + " accused by " + _crime + ".\n\n" + 
	"Alibi: " + to_string(_alibi) + "/100\n" +
	"Damnig evidence: " + to_string(_evidence) + "/100\n" +
	"Criminal record: " + to_string(_criminal_record) + "/100\n" +
	"Inappopriate behaviour in court: " + to_string(_behaviour) + "/100\n" +
	"Plead guilty: " + guilty + "\n" ;

	
}