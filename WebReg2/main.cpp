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

        //If user selects 'A', login, else quit program
        if(studentOption == 'A')
            getLogin(userNameList, testMap);
        else
            quitProgram = true;
	}

	//deallocate point objects in map
	for (auto itr = testMap.begin(); itr != testMap.end(); itr++)
	{
		delete itr->second;
	}

	return 0;
}
