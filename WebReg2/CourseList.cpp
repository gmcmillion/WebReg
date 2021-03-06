#include "CourseList.h"
#include <fstream>
#include <iomanip>

//Constructor
CourseList::CourseList()
{
	head = nullptr;
}

//Destructor
CourseList::~CourseList()
{
	ListNode * temp;           
	ListNode * nodePtr = head;

	while (nodePtr != nullptr)
	{
		temp = nodePtr;
		nodePtr = nodePtr->next;
		delete temp;
	}
}

//Add Course to linked list
void CourseList::add(DeptCourse* addedCourse)
{
	ListNode * newNode; //To point to a new node
	ListNode * nodePtr; //To move through the list

	newNode = new ListNode();				//Allocate a new node
	
										    //Allocate a new deptcourse object within the struct
	newNode->course = new DeptCourse(
		addedCourse->getProf(), addedCourse->getCourseNum(), addedCourse->getClassName(),
		addedCourse->getType(), addedCourse->getSection(), addedCourse->getUnits(),
		addedCourse->getTime(), addedCourse->getLocation(), addedCourse->getFinalDateTime(),
		addedCourse->getmaxEnrollment(), addedCourse->getcurrentEnrollment(),
		addedCourse->getWaitListed(),	 addedCourse->getStatus());

	if (!head)
	{									//If there are no nodes in the list
		head = newNode;					//make newNode the first node
	}
	else                    
	{
		nodePtr = head;					//Initialize nodePtr to the front of the list

		while (nodePtr->next)           //Traverse the list to the last node
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;        //Insert newNode as the last node
	}
}

//Display each course in the linked list
void CourseList::displayAll()
{
	string courseTitle = "";
	ListNode* prevPtr = nullptr;
	ListNode* traversePtr = head;
	cout << "\n---------------------------------------------------------------- "
    << "AVAILABLE COURSES "
    << "----------------------------------------------------------------\n";

	//print the first course in the node
	if (traversePtr != nullptr) {
		traversePtr->course->display();
	}

	while (traversePtr != nullptr) {

		if (traversePtr->next != nullptr && prevPtr != nullptr) //if not currently the first node, and there's a next node
		{
			if (prevPtr->course->getClassName() != traversePtr->course->getClassName()) //if next course title is different
			{
				cout << endl;					//skip line for formatting
				traversePtr->course->display();
			}
			else							   
			{
				traversePtr->course->display(courseTitle);
			}
		}
		else if (traversePtr->next == nullptr) //if the last node
		{
			if (prevPtr->course->getClassName() != traversePtr->course->getClassName())
			{
				traversePtr->course->display();
			}
			else
			{
				traversePtr->course->display(courseTitle);
			}
		}

		prevPtr = traversePtr;
		traversePtr = traversePtr->next;
	}
    cout << endl;
}


//Display each course the student has signed up for
void CourseList::displayLoad()
{
	cout << "\n------------------------------------------- ENROLLED COURSES "
    << "-------------------------------------------\n";
    
    //Heading
    cout << "      Course Name       | " << "Crs Code | " << "Type | " << "Sect | "
    << "Units | " << " Professor  | " << "       Time         | "
    << " Location" << endl;

	//Traverse the list
	for (ListNode * temp = head; temp != NULL; temp = temp->next)
	{
		temp->course->displaySchedule();
		cout << endl;
	}
}

//Updates the ICS_Classes.txt with any changes
void CourseList::writeListToFile()
{
	string emptyLine = "";
	ofstream outFile;
	outFile.open("ICS_Classes.txt");

	ListNode* traversePtr = head;
	
	//this loop traverses through the list while writing to the file
	while (traversePtr != nullptr) {

		outFile << traversePtr->course->getClassName()				<< endl;
		outFile << traversePtr->course->getCourseNum()				<< endl;
		outFile	<< traversePtr->course->getType()					<< endl;
		outFile << traversePtr->course->getSection()				<< endl;
		outFile << traversePtr->course->getUnits()					<< endl;
		outFile << traversePtr->course->getProf()					<< endl;
		outFile << traversePtr->course->getTime()					<< endl;
		outFile << traversePtr->course->getLocation()				<< endl;
		
		//conditional to handle courses without final exams
		if (traversePtr->course->getFinalDateTime().size() > 6) {
			outFile << traversePtr->course->getFinalDateTime() << endl;

		}

		outFile << traversePtr->course->getmaxEnrollment()			<< endl;
		outFile << traversePtr->course->getcurrentEnrollment()		<< endl;
		outFile << traversePtr->course->getWaitListed()				<< endl;
		outFile << traversePtr->course->getStatus()					<< endl;

		if (traversePtr->next != nullptr) {       //this fixes the bug where we were
			outFile << emptyLine << endl;		  //printing the same course multiple times.
		}										  //now we can rewrite to the same file safely

		traversePtr = traversePtr->next;
	}

	outFile.close();
}

//Writes the students schedule to file
void CourseList::writeListToFile(string loginName, string passCode, string name, int id, int maxUnits, int currentUnit)
{
	string emptyLine = "";
	ofstream outFile;
	outFile.open(loginName + ".txt");

	outFile << loginName << endl;
	outFile << passCode << endl;
	outFile << name << endl;
	outFile << id << endl;
	outFile << maxUnits << endl;
	outFile << currentUnit << endl;

	ListNode* traversePtr = head;

	//this loop traverses through the list while writing to the file
	while (traversePtr != nullptr) {

		outFile << traversePtr->course->getClassName() << endl;
		outFile << traversePtr->course->getCourseNum() << endl;
		outFile << traversePtr->course->getType() << endl;
		outFile << traversePtr->course->getSection() << endl;
		outFile << traversePtr->course->getUnits() << endl;
		outFile << traversePtr->course->getProf() << endl;
		outFile << traversePtr->course->getTime() << endl;
		outFile << traversePtr->course->getLocation() << endl;

		//conditional to handle courses without final exams
		if (traversePtr->course->getFinalDateTime().size() > 6) {
			outFile << traversePtr->course->getFinalDateTime() << endl;

		}

		outFile << traversePtr->course->getmaxEnrollment() << endl;
		outFile << traversePtr->course->getcurrentEnrollment() << endl;
		outFile << traversePtr->course->getWaitListed() << endl;
		outFile << traversePtr->course->getStatus() << endl;

		if (traversePtr->next != nullptr) {       //this fixes the bug where we were
			outFile << emptyLine << endl;		  //printing the same course multiple times.
		}										  //now we can rewrite to the same file safely

		traversePtr = traversePtr->next;
	}

	outFile.close();
}

//find course student wants to enroll in
bool CourseList::searchCoursetoEnroll(string courseCode) {

    ListNode* traversePtr = head;

	while (traversePtr != nullptr) {

		if (courseCode == traversePtr->course->getCourseNum())
        {
			traversePtr->course->enrollStudentInCourse();
			return true;
        }
		traversePtr = traversePtr->next;
	}
	return false;
}

//Find Course to add from linked list
DeptCourse CourseList::courseToAdd(string courseCode)
{
	ListNode* traversePtr = head;

	while (courseCode != traversePtr->course->getCourseNum()) 
	{
		traversePtr = traversePtr->next;
	}

	return *traversePtr->course;   //return a copy of that deptcourse object
}

//Find course student wants to drop
void CourseList::searchCoursetoDisenroll(string courseCode)
{
	ListNode* traversePtr = head;
	bool exist = false;

	while (traversePtr != nullptr) {

		if (courseCode == traversePtr->course->getCourseNum())
		{
			traversePtr->course->disenrollStudent();
			exist = true;
		}

		traversePtr = traversePtr->next;
	}

	//Input validation for courses codes that dont exist
	if (!exist)
	{
		cout << "Course " << courseCode << " does not exist" << endl;
	}
}

//Find course student wants to drop
bool CourseList::removeCourseFromLoad(string courseCode)
{
    ListNode* nodePtr;              //To traverse the list
    ListNode* previousNode = NULL;  //To point to the previous node
    
    //If list is empty, do nothing
    if(!head)
    {
        std::cout << "You have no classes to drop." << std::endl;
        return false;
    }
    //Determine if the first node is the one
    if(head->course->getCourseNum() == courseCode)
    {
        nodePtr = head->next;   //assign nodePtr to the next node
        cout << "Dropped " << head->course->getCourseNum() << endl;
        delete head;            //delete the head
        head = nodePtr;         //assign head the next pointer
        return true;
    }
    else
    {
        nodePtr = head;     //initialize nodePtr to head of list
        
        //skip all nodes whose courseCode is not equal to argument
        while (nodePtr != NULL && nodePtr->course->getCourseNum() != courseCode)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)    //if found
        {
            previousNode->next = nodePtr->next;
            cout << "Dropped " << nodePtr->course->getCourseNum() << endl;
            delete nodePtr;
            return true;
        }
    }
    cout << "You are not enrolled in " << courseCode << endl;
    return false;
}
