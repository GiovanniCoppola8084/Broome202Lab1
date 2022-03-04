//-------------------------------------------------------------------------------------------------
//File Name: Person.h
//Associated file: Person.cpp
//Members:
//  1 Constructor : Default
//  Standard Methods:
//      Get - GetName, GetAge, and GetState
//      Set - SetName, SetAge, and SetState
//      Print - PrintName, PrintAge, and PrintState
//  Other Methods
//
//  Friends:
//  Destructor : Print the number of objects destroyed
//-------------------------------------------------------------------------------------------------

#ifndef Person_h
#define Person_h

//Include the header file for the standards
#include "Standards.h"

class personClassType
{

public:

    //Default constructor for the personClassType class
    personClassType(void);

    //Destructor for the personClassType class
    ~personClassType(void);

    //Inline method for GetName
    string GetName(void) { return name; }
    //Inline method for GetAge
    int GetAge(void) { return age; }
    //Inline method for GetState
    string GetState(void) { return state; }

    //Inline method for SetName
    void SetName(string newName) { name = newName; }
    //Inline method for SetName
    void SetAge(int newAge) { age = newAge; }
    //Inline method for SetName
    void SetState(string newState) { state = newState; }

    //Prototype for the PrintName method
    void PrintName(ofstream& fout);
    //Prototype for the PrintAge method
    void PrintAge(ofstream& fout);
    //Prototype for the PrintState method
    void PrintState(ofstream& fout);
    //Prototype for the Print method
    void Print(ofstream& fout);

private:

    //String variable for the name
    string name;

    //Integer variable for the age
    int age;

    //String variable for the state
    string state;

};

#endif // !Person_h
