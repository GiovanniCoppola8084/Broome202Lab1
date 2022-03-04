//-------------------------------------------------------------------------------------------------
//File Name: Police.cpp
//Associated file: Police.h
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

//Include the header file for the police
#include "Police.h"

//-------------------------------------------------------------------------------------------------
//policePersonClassType - default constructor for the policePersonClassType class
//-------------------------------------------------------------------------------------------------
policePersonClassType::policePersonClassType(void)
{

    //Set the office to a null string
    office = "";

    //Set the number of cases to 0
    numberOfCases = 0;

}

//-------------------------------------------------------------------------------------------------
//policePersonClassType - default constructor for the policePersonClassType class
//-------------------------------------------------------------------------------------------------
policePersonClassType::~policePersonClassType(void)
{

    //Create a destructor variable for the policePersonClassType class
    static int policePersonCount = 0;

    //Print the object that is being destroyed
    cout << "Police Class #" << ++policePersonCount << " destroyed." << endl;

}

//-------------------------------------------------------------------------------------------------
//PrintOffice - this method will print the office to the output file
//-------------------------------------------------------------------------------------------------
void policePersonClassType::PrintOffice(ofstream& fout)
{

    //Print the cops office to the output file
    fout << setw(15) << GetOffice();

}

//-------------------------------------------------------------------------------------------------
//PrintSergeant - this method will print the sergeant to the output file
//-------------------------------------------------------------------------------------------------
void policePersonClassType::PrintSergeant(ofstream& fout)
{

    //Determine if the cop is a sergeant or not
    if (GetSergeant() == true)
    {

        //Print that the cop is a sergeant
        fout << setw(20) << "Sergeant";

    }
    else
    {

        //Print that the cop is not a sergeant
        fout << setw(20) << "Not a sergeant";

    }

}

//-------------------------------------------------------------------------------------------------
//PrintNumberOfCases - print the number of cases to the output file
//-------------------------------------------------------------------------------------------------
void policePersonClassType::PrintNumberOfCases(ofstream& fout)
{

    //Print the number of cases
    fout << left << "Number of Cases: " << GetNumberOfCases();

}