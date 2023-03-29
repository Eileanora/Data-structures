#include <iostream>
using namespace std;

class Student
{
private:
    string studentName;
    int id; 
    double phone;

public:
    void setName(string name)
    {
        studentName = name;
    }
    void setId(int id)
    {
        this->id = id;
    }
    string getName(){
        return studentName;
    }
    int getId(){
        return id;
    }

    Student() {
        studentName = "";
        id = 0;
        phone = 0;
    }
};