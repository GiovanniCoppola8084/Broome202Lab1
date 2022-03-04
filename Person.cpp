//-------------------------------------------------------------------------------------------------
//File Name: Person.cpp
//Associated file: Person.h
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

//Include the header file for the person
#include "Person.h"

//-------------------------------------------------------------------------------------------------
//personClassType - default constructor for the personClassType class
//-------------------------------------------------------------------------------------------------
personClassType::personClassType(void)
{

    //Set the name to a null string
    name = "";

    //Set the age to 0
    age = 0;

    //Set the state to a null string
    state = "";

}

//-------------------------------------------------------------------------------------------------
//~personClassType - destructor for the personClassType class
//-------------------------------------------------------------------------------------------------
personClassType::~personClassType(void)
{

    //Create a destructor variable for the personClassType class
    static int personClassCount = 0;

    //Print the object that was destroyed
    cout << "Person class #" << ++personClassCount << " destroyed." << endl;

}

//-------------------------------------------------------------------------------------------------
//PrintName - this method will print the name to the output file
//-------------------------------------------------------------------------------------------------
void personClassType::PrintName(ofstream& fout)
{

    //Print the name to the output file
    fout << GetName();

}

//-------------------------------------------------------------------------------------------------
//PrintAge - this method will print the age to the output file
//-------------------------------------------------------------------------------------------------
void personClassType::PrintAge(ofstream& fout)
{

    //Print the age to the output file
    fout << GetAge();

}

//-------------------------------------------------------------------------------------------------
//PrintState - this method will print the state to the output file
//-------------------------------------------------------------------------------------------------
void personClassType::PrintState(ofstream& fout)
{

    //Print the state to the output file
    fout << GetState();

}

//-------------------------------------------------------------------------------------------------
//Print - this is the base print method and will print the divider, a centered message, and any 
//  other variables to the output file
//-------------------------------------------------------------------------------------------------
void personClassType::Print(ofstream& fout)
{

    //Set the justification to left and the set fill to a blank
    fout << left << setfill(' ');

    //Print the header for the name
    fout << left << "Name: " << setw(30);

    //Call the print name method
    PrintName(fout);

    //Print the header for the age
    fout << left << "Age: " << setw(10);

    //Call the print age method
    PrintAge(fout);

    //Print the header for the state
    fout << left << "State: " << setw(10);

    //Call the print state method
    PrintState(fout);

}