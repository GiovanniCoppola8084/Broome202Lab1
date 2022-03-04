//-------------------------------------------------------------------------------------------------
//File Name: Police.h
//Associated file: Police.cpp
//Members:
//  1 Constructor : Default
//  Standard Methods:
//      Get - GetOffice, GetNumberOfCases, and GetSergeant
//      Set - SetOffice, SetNumberOfCases, and SetSergeant
//      Print - PrintOffice, PrintNumberOfCases, and PrintSergeant
//  Other Methods
//
//  Friends:
//  Destructor : Print the number of objects destroyed
//-------------------------------------------------------------------------------------------------

#ifndef Police_h
#define Police_h

//Include the header file for the standards
#include "Standards.h"

//Include the header file for the person
#include "Person.h"

//Create the policePersonClassType class that inherits the personClassType class
class policePersonClassType : public personClassType
{

public:

    //Default constructor for the policePersonClassType
    policePersonClassType(void);

    //Destructor for the policePersonClassType
    ~policePersonClassType(void);

    //Inline get method for GetOffice
    string GetOffice(void) { return office; }
    //Inline get method for GetNumberOfCases
    int GetNumberOfCases(void) { return numberOfCases; }
    //Inline get method for GetSergeant
    bool GetSergeant(void) { return sergeant; }

    //Inline set method for SetOffice
    void SetOffice(string newOffice) { office = newOffice; }
    //Inline set method for SetNumberOfCases
    void SetNumberOfCases(int newNumberOfCases) { numberOfCases = newNumberOfCases; }
    //Inline set method for SetSergeant
    void SetSergeant(bool newBool) { sergeant = newBool; }

    //Prototype for PrintOffice method
    void PrintOffice(ofstream& fout);
    //Prototype for PrintSergeant method
    void PrintSergeant(ofstream& fout);
    //Prototype for PrintNumberOfCases method
    void PrintNumberOfCases(ofstream& fout);

private:

    //String variable for the office
    string office;

    //Integer variable for the number of cases
    int numberOfCases;

    //Boolean variable for the sergeant
    bool sergeant;

};

//Create a typedef for the police person class type
typedef policePersonClassType * policePtr;

#endif // !Police_h
