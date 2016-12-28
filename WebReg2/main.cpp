#include "Student.h"
#include "InterfaceFunctions.h"

using namespace std;

int main()
{
	//Variables
    char studentOption;
	bool quitProgram = false;

	map<string, Student*> testMap;
	vector<string> userNameList;
	
    setUpUserVector(userNameList);
    
	testMap = setUpMap(userNameList, testMap);

	cout << "----- Welcome to UCI WebReg -----\n" << endl;

	while (!quitProgram) 
	{
		//Get Student option
        studentOption = startUpMenu();

		switch (studentOption)
		{
		case 'A':
		case 'a':
				  getLogin(userNameList, testMap);
				  break;
		case 'E':
		case 'e': 
				  quitProgram = true;
				  return 0;
		
		default: cout << "\nThat is an invalid option, try again\n\n";
		}
	}

	//deallocate point objects in map
	for (auto itr = testMap.begin(); itr != testMap.end(); itr++)
	{
		delete itr->second;
	}

	return 0;
}
