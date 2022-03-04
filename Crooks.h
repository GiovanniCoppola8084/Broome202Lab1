//-------------------------------------------------------------------------------------------------
//File Name: Crooks.h
//Associated file: Crooks.cpp
//Members:
//  1 Constructor : Default
//  Standard Methods:
//      Get - GetHeight, GetWeight, and GetIncarcerated
//      Set - SetHeight, SetWeight, and SetIncarcerated
//      Print - PrintHeight, PrintWeight, and PrintIncarcerated
//  Other Methods
//
//  Friends:
//  Destructor : Print the number of objects destroyed
//-------------------------------------------------------------------------------------------------

#ifndef Crooks_h
#define Crooks_h

//Include the header file for the standards
#include "Standards.h"

//Include the header file for the person
#include "Person.h"

//Create the CrookClassType class that will inherit the personClassType
class CrookClassType : public personClassType
{

public:

    //Default constructor for the CrooksClassType class
    CrookClassType(void);

    //Destructor for the CrooksClassType class
    ~CrookClassType(void);

    //Inline get method for GetHeight
    int GetHeight(void) { return height; }
    //Inline get method for GetWeight
    int GetWeight(void) { return weight; }
    //Inline get method for GetIncarcerated
    bool GetIncarcerated(void) { return incarcerated; }

    //Inline set method for SetName
    void SetName(string newName) { personClassType::SetName(newName); }
    //Inline set method for SetHeight
    void SetHeight(int newHeight) { height = newHeight; }
    //Inline set method for SetWeight
    void SetWeight(int newWeight) { weight = newWeight; }
    //Inline set method for SetIncarcerated
    void SetIncarcerated(bool newBool) { incarcerated = newBool; }

    //Prototype for the PrintHeight method
    void PrintHeight(ofstream& fout);
    //Prototype for the PrintWeight method
    void PrintWeight(ofstream& fout);
    //Prototype for the PrintIncarcerated method
    void PrintIncarcerated(ofstream& fout);

private:

    //Integer variable for the height
    int height;

    //Integer variable for the weight
    int weight;

    //Boolean variable for incarcerated
    bool incarcerated;

};

//Create a typedef for the crooks
typedef CrookClassType * crookPtr;

#endif // !Crooks_h
