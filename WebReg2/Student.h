//Student.h
#ifndef Student_h
#define Student_h

class Student
{
    private:
        string name;
        int idNum;
    public:
        //Constructor
        Student(string n, int i) : name(n), idNum(i)
        {}
    
        //Getters
        string getName()
        {
            return name;
        }
    
        int getIdNum()
        {
            return idNum;
        }
};
#endif
