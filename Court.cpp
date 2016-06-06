
#include <fstream>
#include <cstdlib>

#include "Court.h"
using namespace std;	

Court::Court()
{
	_experience = rand() % 101;
	_rhetoric = rand() % 101; 
 	_corrupt = rand() % 101;
	_indulgence = rand() % 101; 
	_isPublic = rand() % 2;
	_testimony = rand() % 101;
}

string Court::A_description()
{
	string ispublic = (( _isPublic==0 ) ? "NO" : "YES");
	return "Experience: " + to_string(_experience) + "/100\n" +
			"Rhetoric: " + to_string(_rhetoric) + "/100\n" +
			"Public: " + ispublic + "\n\n";
}

string Court::P_description()
{
	return "Experience: " + to_string(_experience) + "/100\n" +
			"Rhetoric: " + to_string(_rhetoric) + "/100\n" +
			"Indulgence: " + to_string(_indulgence) + "/100\n\n" ;
			
}
string Court::J_description()
{
	return "Indulgence: " + to_string(_indulgence) + "/100\n" +
			"Corruption level " + to_string(_corrupt) + "/100\n\n" ;
			
}


