//-------------------------------------------------------------------------------------------------
//File Name: Crooks.cpp
//Associated file: Crooks.h
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

//Include the header file for crooks
#include "Crooks.h"

//-------------------------------------------------------------------------------------------------
//CrookClassType - default constructor for the CrookClassType class
//-------------------------------------------------------------------------------------------------
CrookClassType::CrookClassType(void)
{

    //Set the height to 0
    height = 0;

    //Set the weight to 0
    weight = 0;

}

//-------------------------------------------------------------------------------------------------
//~CrookClassType - destructor for the CrookClassType class
//-------------------------------------------------------------------------------------------------
CrookClassType::~CrookClassType(void)
{

    //Create a destructor variable for the CrookClassType class
    static int CrookClassCount = 0;

    //Print out the object that was destroyed
    cout << "Crook Class #" << ++CrookClassCount << " destroyed." << endl;

}

//-------------------------------------------------------------------------------------------------
//PrintHeight - this method will print the height to the output file
//-------------------------------------------------------------------------------------------------
void CrookClassType::PrintHeight(ofstream& fout)
{

    //Create a temporary double variable for the height of the crook
    double tempHeight;

    //Create a temporary string variable for the height
    string tempString;

    //Calculate the value of the height in feet and inches
    tempHeight = GetHeight() / 12.0;

    //Set the height to a string
    tempString = to_string(tempHeight);

    //Print the height of the crook
    fout << tempString.at(0) << "\'\ " << tempString.at(2) << setw(10) << "\"\ " << setw(30);

}

//-------------------------------------------------------------------------------------------------
//PrintWeight - this method will print the weight to the output file
//-------------------------------------------------------------------------------------------------
void CrookClassType::PrintWeight(ofstream& fout)
{

    //Print the weight of the crook
    fout << setw(10) << GetWeight();

}

//-------------------------------------------------------------------------------------------------
//PrintIncarcerated - this method will print if incarcerated or not to the output file
//-------------------------------------------------------------------------------------------------
void CrookClassType::PrintIncarcerated(ofstream& fout)
{

    //Print if the crook is incarcerated or not
    if (GetIncarcerated() == true)
    {

        //Print the crook is incarcerated
        fout << "Incarcerated";

    }
    else
    {

        //Print the crook is not incarcerated
        fout << "Not Incarcerated";

    }

}