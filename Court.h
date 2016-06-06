#include <string>


using namespace std;

class Court
{
private:
	int _experience; 
	int _rhetoric; 
	int _corrupt;
	int _indulgence;
	int _isPublic;  //0-1
	int _testimony; //na korzyść lub niekorzyść oskarżonego

public:
	Court();
	int experience()	{return _experience;}
	int rhetoric()		{return _rhetoric;}
	int corrupt()		{return _corrupt;}
	int indulgence()	{return _indulgence;}
	int isPublic()		{return _isPublic;}
	int testimony()		{return _testimony;}

	string A_description();
	string P_description();
	string J_description();
};

