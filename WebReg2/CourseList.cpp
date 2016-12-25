#include "CourseList.h"
#include <fstream>

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
    cout << "\n------------ Available Courses ------------\n";

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
	cout << "\n-------- Enrolled Courses --------\n";

	//Traverse the list
	for (ListNode * temp = head; temp != NULL; temp = temp->next)
	{
		temp->course->displaySchedule();
		cout << endl;
	}
}

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

//find course student wants to enroll in
bool CourseList::searchCoursetoEnroll(string courseCode) {

    ListNode* traversePtr = head;
    bool exists = false;

	while (traversePtr != nullptr) {

		if (courseCode == traversePtr->course->getCourseNum())
        {
			traversePtr->course->enrollStudentInCourse();
            cout << "Enrolled in " << courseCode << endl;
            exists = true;
			return true;
        }
		traversePtr = traversePtr->next;
	}
    
    //Input validation for courses codes that dont exist
    if (!exists)
    {
        cout << "Course " << courseCode << " does not exist" << endl;
    }
	return false;
}

DeptCourse CourseList::courseToAdd(string courseCode) {

	ListNode* traversePtr = head;

	while (courseCode != traversePtr->course->getCourseNum()) 
	{
		traversePtr = traversePtr->next;
	}

	return *traversePtr->course;   //return a copy of that deptcourse object
}

//find course student wants to enroll in
void CourseList::searchCoursetoDisenroll(string courseCode) {

	ListNode* traversePtr = head;
	bool exist = false;

	while (traversePtr != nullptr) {

		if (courseCode == traversePtr->course->getCourseNum())
		{
			traversePtr->course->disenrollStudent();
			cout << "Successfully dropped course: " << courseCode << endl;
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

//find course student wants to enroll in
bool CourseList::removeCourseFromLoad(string courseCode){

	ListNode* delPtr;
	ListNode* NextNode;
	ListNode* CurrentNode;

	//if bucket is empty
	if (head == nullptr) {
		std::cout << "You have no classes to drop." << std::endl;
	}
	//if one one item exist in bucket
	else if (head->course->getCourseNum() == courseCode && head->next == nullptr){

		delete head;
		head = nullptr;

		std::cout << "Course Dropped" << std::endl;
		
		return true;
	}
	//if item is first in bucket, but bucket has more than one item
	else if (head->course->getCourseNum() == courseCode) {

		NextNode = head->next;
		CurrentNode = head;

		//decapitate head
		delete CurrentNode;
		
		//rechain head to new location
		head = NextNode;
		std::cout << "Course Dropped" << std::endl;
		return true;
	}
	else {
		//more than one node exist in bucket
		NextNode = head->next;
		CurrentNode = head;

		while (NextNode != nullptr && NextNode->course->getCourseNum() != courseCode) {
			CurrentNode = NextNode;
			NextNode = CurrentNode->next;
		}
		if (CurrentNode == nullptr || CurrentNode->course->getCourseNum() != courseCode) {
			std::cout << "Course Not Found" << std::endl;
		}
		else {
			//Set delete ptr to struct to be deleted and rechain
			delPtr = NextNode;
			NextNode = NextNode->next;
			NextNode->next = NextNode;
			delete delPtr;
			std::cout << "Course Dropped" << std::endl;
			return true;
		}
	}
	return false;
}
