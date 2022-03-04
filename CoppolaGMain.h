//-------------------------------------------------------------------------------------------------
//File Name: CoppolaGMain.h
//Associated file: CoppolaGMain.cpp
//Members:
//  Prototypes for the following functions:
//  ReadPoliceData
//  ReadCrookData
//  SelectionSortCops
//  IndexOfSmallest
//  Swap
//  SwitchNameCrooks
//  SwitchNamePolice
//  ProcessCapers
//
//-------------------------------------------------------------------------------------------------

#ifndef CoppolaGMain_h
#define CoppolaGMain_h

//Include the standards header file
#include "Standards.h"

//Include the police header file
#include "Police.h"

//Include the person header file
#include "Person.h"

//Include the crooks header file
#include "Crooks.h"

//Prototype for the read police data function
void ReadPoliceData(ifstream& fin, policePtr police[], int& tagField);

//Prototype for the read crook data function
void ReadCrookData(ifstream& fin, crookPtr crooks[], int& tagField);

//Prototype for the SelectionSortCops function
void SelectionSortCops(policePtr police[], int tagField);

//Prototype for the IndexOfSmallest function
int IndexOfSmallest(policePtr police[], int index, int tagField);

//Prototype for the Swap function
void Swap(policePtr& police1, policePtr& police2);

//Prototype for the SwitchName function for the crooks
void SwitchNameCrooks(crookPtr crooks[], int tag);

//Prototype for the SwitchName function for the police
void SwitchNamePolice(policePtr police[], int tag);

//Prototype for the ProcessCapers function
void ProcessCapers(ifstream& fin, ofstream& fout, policePtr police[], crookPtr crooks[], 
    int tagFieldCrooks, int tagFieldPolice);

#endif // !CoppolalGMain
