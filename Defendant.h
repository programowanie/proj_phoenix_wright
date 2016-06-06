#include <vector>
#include <string>

using namespace std;

class Defendant{

private:
	static vector <string> names;
	static vector <string> crimes;

	string _name; 
	string _crime;
	int _alibi; //[0;100], 0-niepodwazalne; 100 - absolutny brak.
	int _evidence; //[0;100] 0-brak; 100-pograzajace.
	int _criminal_record; //[0;100] 0-niekarany; 100-jest doprawdy zle.
	int _behaviour; //[0;100] 0-nie sprawia wrazenia przestepcy; 100-strach podejsc.
	int _plead_guilty; //0 - nie przyznał się, 1-przyznał

	static void initNames();
	static void initCrimes();

public:
	Defendant();

	string name() 			{return _name;}
	string crime() 			{return _crime;}
	int alibi()				{return _alibi;}
	int evidence()			{return _evidence;}
	int criminal_record()	{return _criminal_record;}
	int behaviour()			{return _behaviour;}
	int plead_guilty()		{return _plead_guilty;}

	int rate();
	string description();


};
//