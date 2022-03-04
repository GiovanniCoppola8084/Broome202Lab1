//-------------------------------------------------------------------------------------------------
//File Name: CoppolaGMain.cpp
//Associated file: CoppolaGMain.h
//Members:
//  ReadPoliceData - 
//  ReadCrookData - 
//  SelectionSortCops - 
//  IndexOfSmallest - 
//  Swap - 
//  SwitchNameCrooks - 
//  SwitchNamePolice - 
//  ProcessCapers - 
//
//-------------------------------------------------------------------------------------------------

//Include the main header file
#include "CoppolaGMain.h"

int main(void)
{

	//Input file stream for crooks
	ifstream finCrook;

	//Input file stream for police
	ifstream finPolice;

    //Input file stream for capers
    ifstream finCaper;

	//Output file stream for silko
	ofstream foutSilko;

    //Output file stream for suspects
    ofstream foutSuspects;

	//Open the crook file stream
	finCrook.open("crooks.txt");

	//Open the police file stream
	finPolice.open("cops.txt");

    //Open the capers file stream
    finCaper.open("capers.txt");

    //Open the output file stream
    foutSilko.open("silko.txt");

    //Open the output file stream for suspects
    foutSuspects.open("Suspects.txt");

	//Create an array of 25 crooks
	crookPtr crooks[MAX_ELEMENTS];

	//Create an array of 25 police
	policePtr police[MAX_ELEMENTS];

	//Create a tag field for the police
	int tagFieldPolice = 0;

	//Create a tag field for the crooks
	int tagFieldCrooks = 0;

	//Call the ReadCrookData function
	ReadCrookData(finCrook, crooks, tagFieldCrooks);

    //Call the ReadPoliceData function
    ReadPoliceData(finPolice, police, tagFieldPolice);

    //Print the divider to the output file
    PrintDivider(foutSilko, '-', 180);

    //Print the header to print the crook information
    PrintCenteredMessage(foutSilko, "Data for the Crooks", 180);

    //Print the divider to the output file
    PrintDivider(foutSilko, '-', 180);

    //For loop to loop through and print all crooks data
    for (int index = 0; index < tagFieldCrooks; index++)
    {

        //Call the switch name function
        SwitchNameCrooks(crooks, index);

        //Call the print method for the crook
        crooks[index]->Print(foutSilko);

        //Print the header for the crook
        foutSilko << left << "Height of the crook: ";

        //Print the crooks height
        crooks[index]->PrintHeight(foutSilko);

        //Print the header for the weight of the crook
        foutSilko << left << "Weight of the crook: ";

        //Print the crooks weight
        crooks[index]->PrintWeight(foutSilko);

        //Print the crooks incarcerated value
        crooks[index]->PrintIncarcerated(foutSilko);

        //Move the cursor to the next line
        foutSilko << endl;

    }

    //Print the number of crooks
    foutSilko << "There are " << tagFieldCrooks << " crooks" << endl;

    //Print the divider to the output file
    PrintDivider(foutSilko, '-', 180);

    //Move the cursor to the next line
    foutSilko << endl;

    //Print the divider to the output file
    PrintDivider(foutSilko, '-', 150);

    //Print the header to print the police information
    PrintCenteredMessage(foutSilko, "Data for the Police before the sort", 150);

    //Print the divider to the output file
    PrintDivider(foutSilko, '-', 150);

    //For loop to loop through and print all police data
    for (int index = 0; index < tagFieldPolice; index++)
    {

        //Call the switch name function
        SwitchNamePolice(police, index);

        //Call the print method for the cop
        police[index]->Print(foutSilko);

        //Print the header for the office of the cop
        foutSilko << left << "Cops office: ";

        //Print the cops office
        police[index]->PrintOffice(foutSilko);

        //Print if the cop is a sergeant or not
        police[index]->PrintSergeant(foutSilko);

        //Print the number of cases
        police[index]->PrintNumberOfCases(foutSilko);

        //Move the cursor to the next line
        foutSilko << endl;

    }

    //Print the number of cops
    foutSilko << "There are " << tagFieldPolice << " cops" << endl;

    //Print the divider to the output file
    PrintDivider(foutSilko, '-', 150);

    //Call the SelectionSortCops function
    SelectionSortCops(police, tagFieldPolice);

    //Print the divider to the output file
    PrintDivider(foutSilko, '-', 150);

    //Print the header to print the police information
    PrintCenteredMessage(foutSilko, "Data for the Police after the sort", 150);

    //Print the divider to the output file
    PrintDivider(foutSilko, '-', 150);

    //For loop to loop through and print all police data
    for (int index = 0; index < tagFieldPolice; index++)
    {

        //Call the print method for the cop
        police[index]->Print(foutSilko);

        //Print the header for the office of the cop
        foutSilko << left << "Cops office: ";

        //Print the cops office
        police[index]->PrintOffice(foutSilko);

        //Print if the cop is a sergeant or not
        police[index]->PrintSergeant(foutSilko);

        //Print the number of cases
        police[index]->PrintNumberOfCases(foutSilko);

        //Move the cursor to the next line
        foutSilko << endl;

    }

    //Print the number of cops
    foutSilko << "There are " << tagFieldPolice << " cops" << endl;

    //Print the divider to the output file
    PrintDivider(foutSilko, '-', 150);

    //Call the process capers function
    ProcessCapers(finCaper, foutSuspects, police, crooks, tagFieldPolice, tagFieldCrooks);

}

//-------------------------------------------------------------------------------------------------
//ReadPoliceData - Read in the data from "cops.txt" for the police
//-------------------------------------------------------------------------------------------------
void ReadPoliceData(ifstream& fin, policePtr police[], int& tagField)
{

	//Create a temporary string variable
	string tempString;

	//Create a temporary integer variable
	int tempInt;

	//Create a temporary character array
	char aName[26];

	//Input the first name from the crooks input file (primer)
	fin.get(aName, 26);

	//While loop to process all of the police
	while (fin && tagField < MAX_ELEMENTS)
	{

        //Create a new pointer to the police class type
        police[tagField] = new policePersonClassType;

		//Set the character array to the name of the cop
		police[tagField]->SetName(aName);

        //Ignore the next blank character
        fin.ignore();

		//Input if the cop is a sergeant or not
		getline(fin, tempString, ' ');

		//Determine if the cop is a sergeant
		if (tempString.compare("Y") == 0)
		{

			//Set the cop to be a sergeant
			police[tagField]->SetSergeant(true);

		}
		else
		{

			//Set the cop to not be a sergeant
			police[tagField]->SetSergeant(false);

		}

		//Input the string for the cops office
		getline(fin, tempString, ' ');

		//Set the cops office
		police[tagField]->SetOffice(tempString);

		//Input the state for the cop
		getline(fin, tempString, ' ');

        //Set the state for the cop
        police[tagField]->SetState(tempString);

		//Input the age of the cop
		fin >> tempInt;

		//Set the age of the cop
		police[tagField]->SetAge(tempInt);

		//Input the number of cases for the cop
		fin >> tempInt;

		//Set the number of cases for the cop
		police[tagField]->SetNumberOfCases(tempInt);

        //Ignore the rest of the line
        fin.ignore(100, '\n');

		//Increment the tag field
		tagField++;

		//Input the name of the next cop (changer)
		fin.get(aName, 26);

	}

}

//-------------------------------------------------------------------------------------------------
//ReadCrookData - Read in the data from "crooks.txt" for the crooks
//-------------------------------------------------------------------------------------------------
void ReadCrookData(ifstream& fin, crookPtr crooks[], int& tagField)

{

	//Create a temporary string variable
	string tempString;

	//Create a temporary integer variable
	int tempInt;

    //Create a temporary character array
    char aName[26];

	//Input the first name from the crooks input file (primer)
    fin.get(aName, 26);

	//While loop to process all of the crooks
	while (fin && tagField < MAX_ELEMENTS)
	{

        //Create a new pointer to the crooks class type
        crooks[tagField] = new CrookClassType;

        //Set the character array to the name of the crook
        crooks[tagField]->SetName(aName);

		//Input the height of the crook
		fin >> tempInt;

		//Set the height of the crook
		crooks[tagField]->SetHeight(tempInt);

		//Input the weight of the crook
		fin >> tempInt;

		//Set the weight of the crook
		crooks[tagField]->SetWeight(tempInt);

		//Input the age of the crook
		fin >> tempInt;

		//Ignore the blank
		fin.ignore();

		//Set the age of the crook
		crooks[tagField]->SetAge(tempInt);

		//Input the state of the crook
		getline(fin, tempString, ' ');

		//Set the state of the crook
		crooks[tagField]->SetState(tempString);

		//Input the incarcerated value
		getline(fin, tempString, '\n');

		//If the incarcerated value is 'Y'
		if (tempString.compare("Y") == 0 || tempString.compare("y") == 0)
		{

			//Set the incarcerated value of the crook to true
			crooks[tagField]->SetIncarcerated(true);

		}
		else
		{

			//Set the incarcerated value of the crook to false
			crooks[tagField]->SetIncarcerated(false);

		}

		//Increment the tagField
		tagField++;

		//Input the name of the next crook
        fin.get(aName, 26);

	}

}

//-------------------------------------------------------------------------------------------------
//SelectionSortCops - Sort the cops by number of cases in ascending order
//-------------------------------------------------------------------------------------------------
void SelectionSortCops(policePtr police[], int tagField)
{

    //Create a variable to represent the smallest index
    int smallestIndex;

    //For loop to loop through each element of the array of class pointers
    for (int index = 0; index < tagField; index++)
    {

        //Call the IndexOfSmallest function and store it in smallestIndex
        smallestIndex = IndexOfSmallest(police, index, tagField);

        //Call the swap function to sort
        Swap(police[smallestIndex], police[index]);

    }

}

//-------------------------------------------------------------------------------------------------
//IndexOfSmallest - find the smallest index value and return it
//-------------------------------------------------------------------------------------------------
int IndexOfSmallest(policePtr police[], int index, int tagField)
{

    //Create a variable for the smallest index
    int smallestIndex;

    //Store the current index in smallest index
    smallestIndex = index;

    //For loop to loop through all elements of the array to find a smaller index
    for (int minIndex = index + 1; minIndex < tagField; minIndex++)
    {

        //If the current number of cases as minIndex is smaller that the one at smallestIndex
        if (police[minIndex]->GetNumberOfCases() < police[smallestIndex]->GetNumberOfCases())
        {

            //Set the smallest index to the minIndex
            smallestIndex = minIndex;

        }

    }

    //Return the smallest index
    return smallestIndex;

}

//-------------------------------------------------------------------------------------------------
//Swap - swap the two current police class pointer arrays
//-------------------------------------------------------------------------------------------------
void Swap(policePtr& police1, policePtr& police2)
{

    //Create a temporary variable
    policePtr temp;
    
    //Swap the two class pointer arrays
    temp = police1;

    police1 = police2;

    police2 = temp;

}

//-------------------------------------------------------------------------------------------------
//SwitchNameCrooks - switch the first name and the last name of the crook
//-------------------------------------------------------------------------------------------------
void SwitchNameCrooks(crookPtr crooks[], int tag)
{

    //Set a temporary string for the last
    string tempLastName;

    //Set a temporary string for the first name
    string tempFirstName;

    //Create a temporary string to hold the value of the name being switched
    string name = crooks[tag]->GetName();

    //Create an integer variable to hold the value of where the first non-blank is
    int nonBlank;

    //For loop to loop through each character of the name to find the comma
    for (int index = 0; index < name.length(); index++)
    {

        //If statement to find the comma in the name
        if (name.at(index) == ',')
        {

            //Set the temp last name to all of the characters before the index
            tempLastName = name.substr(0, index);

            //Increment index by 2
            index += 2;

            //For loop to loop through name from right to left
            for (int value = name.length() - 1; value > index; value--)
            {

                //Check to see if the character is not a space
                if (name.at(value) != ' ')
                {

                    //Set the nonBlank value to value
                    nonBlank = value;

                    //Set value equal to index to end the loop
                    value = index;

                }

            }

            //Set the temp first name to all of the characters after the blanks are deleted
            tempFirstName = name.substr(index, (nonBlank + 1) - index);

        }

    }

    //Reset the new name for the crook
    crooks[tag]->SetName((tempFirstName + ' ' + tempLastName));

}

//-------------------------------------------------------------------------------------------------
//SwitchNamePolice - switch the first name and the last name of the cop
//-------------------------------------------------------------------------------------------------
void SwitchNamePolice(policePtr police[], int tag)
{

    //Set a temporary string for the last
    string tempLastName;

    //Set a temporary string for the first name
    string tempFirstName;

    //Create a temporary string to hold the value of the name being switched
    string name = police[tag]->GetName();

    //Create an integer variable to hold the value of where the first non-blank is
    int nonBlank;

    //For loop to loop through each character of the name to find the comma
    for (int index = 0; index < name.length(); index++)
    {

        //If statement to find the comma in the name
        if (name.at(index) == ',')
        {

            //Set the temp last name to all of the characters before the index
            tempLastName = name.substr(0, index);

            //Increment index by 2
            index += 2;

            //For loop to loop through name from right to left
            for (int value = name.length() - 1; value > index; value--)
            {

                //Check to see if the character is not a space
                if (name.at(value) != ' ')
                {

                    //Set the nonBlank value to value
                    nonBlank = value;

                    //Set value equal to index to end the loop
                    value = index;

                }

            }

            //Set the temp first name to all of the characters after the blanks are deleted
            tempFirstName = name.substr(index, (nonBlank + 1) - index);

        }

    }

    //Reset the new name for the crook
    police[tag]->SetName((tempFirstName + ' ' + tempLastName));

}

//-------------------------------------------------------------------------------------------------
//ProcessCapers - process the caper file and assign cases to the appropriate cops
//-------------------------------------------------------------------------------------------------
void ProcessCapers(ifstream& fin, ofstream& fout, policePtr police[], crookPtr crooks[],
    int tagFieldCrooks, int tagFieldPolice)
{

    //Create a temporary string variable
    string tempString;

    //Create a boolean variable to determine if the are suspects in the case or not
    bool headerPrinted = false;

    //Create a temporary height integer variable
    int tempHeight;

    //Create a temporary weight integer variable
    int tempWeight;

    //Create a temporary height double variable to store the height in feet and inches
    double newHeight;

    //Create a temporary character array variable
    char aCrime[26];

    //Create a tag field
    int tagField = 0;

    //Create a temporary case number variable
    int tempCaseNum = 0;

    //Create an integer for the amount of suspects
    int amountSuspects = 0;

    //Input the first crime from the capers (changer)
    fin.get(aCrime, 26);

    //While loop to loop through all of the capers
    while (!fin.eof())
    {

        //Input the height
        fin >> tempHeight;

        //Input the weight
        fin >> tempWeight;

        //Print the divider to the output file
        PrintDivider(fout, '-', 100);

        //Print the header to print the police information
        PrintCenteredMessage(fout, "Suspects Report", 100);

        //Print the divider to the output file
        PrintDivider(fout, '-', 100);

        //Print the header for the crime
        fout << "For the crime of : ";

        //Print the crime involved in this case
        for (int index = 0; index < 26; index++)
        {

            //Print the character at index
            fout << aCrime[index];

        }

        //Move the cursor to the next line
        fout << endl;

        //Get the height into inches and feet
        newHeight = tempHeight / 12.0;

        //Convert the height to a string
        tempString = to_string(newHeight);

        //Print the recorded height of the suspect
        fout << "With a recorded height of " << tempString.at(0) << "\'\ "
            << tempString.at(2) << "\"\ ";

        //Print out the weight of the suspect
        fout << "& and weight of: " << tempWeight << " lbs" << endl;

        //Subtract .4 from the height to get the minimum height range
        newHeight -= .4;

        //Convert the height to a string
        tempString = to_string(newHeight);

        //Print out the min height range
        fout << "Height Range: " << tempString.at(0) << "\'\ " << tempString.at(2) << "\"\ ";

        //Add .8 to the height to get the maximum height range
        newHeight += .8;

        //Convert the height to a string
        tempString = to_string(newHeight);

        //Print out the max height range
        fout << "through " << tempString.at(0) << "\'\ " << tempString.at(2) << "\"\ " << endl;

        //Print the weight range
        fout << "Weight Range: " << (tempWeight - 10) << " lbs through " << (tempWeight + 10) <<
            " lbs" << endl;

        //Check which cop will be assigned
        for (int cops = 0; cops < tagFieldPolice; cops++)
        {

            //If the cop has cases open
            if (police[cops]->GetNumberOfCases() != 0 && tempCaseNum !=
                police[cops]->GetNumberOfCases())
            {

                //Print the officers information for who was assigned to the case
                fout << left << setw(10) << "Name: " << police[cops]->GetName() << endl;

                //Print the cops office number
                fout << setw(10) << "Office: " << police[cops]->GetOffice() << endl;

                //Increment the number of cases
                tempCaseNum++;

                //Decrement the number of cases from the cop
                police[cops]->SetNumberOfCases((police[cops]->GetNumberOfCases() - tempCaseNum));

                //End the for loop
                cops = tagFieldPolice;

            }

        }

        //For loop to loop through all the crooks
        for (int suspects = 0; suspects < 21; suspects++)
        {

            //If the height is in the max height range
            if ((tempHeight + 4) >= crooks[suspects]->GetHeight())
            {

                //If the height is in the min range
                if ((tempHeight - 4) <= crooks[suspects]->GetHeight())
                {

                    //If the weight is in the max range
                    if (crooks[suspects]->GetWeight() <= (tempWeight + 10))
                    {

                        //If the weight is in the min range
                        if (crooks[suspects]->GetWeight() >= (tempWeight - 10))
                        {

                            //If the header wasn't printed
                            if (headerPrinted == false)
                            {

                                //Print the divider to the output file
                                PrintDivider(fout, '-', 100);

                                //Print out the header for the crooks if there are suspects
                                fout << left << setw(29) << "Crook's name" << setw(12) << "Height"
                                    << setw(12) << "Weight" << setw(13) << "Age" << setw(15)
                                    << "State" << endl;

                                //Print the divider to the output file
                                PrintDivider(fout, '-', 100);

                                //Set headerPrinted to true
                                headerPrinted = true;

                            }

                            //Create a setw
                            fout << setw(30);

                            //Output the name of the crook
                            crooks[suspects]->PrintName(fout);

                            //Output the height of the crook
                            crooks[suspects]->PrintHeight(fout);

                            //Create a setw
                            fout << setw(15);

                            //Output the weight of the crook
                            crooks[suspects]->PrintWeight(fout);

                            //Create a setw
                            fout << setw(15);

                            //Output the age of the crook
                            crooks[suspects]->PrintAge(fout);

                            //Create a setw
                            fout << setw(15);

                            //Output the state of the crook
                            crooks[suspects]->PrintState(fout);

                            //Move the cursor down a line
                            fout << endl;

                            //Increment the amount of suspects
                            amountSuspects++;

                        }

                    }

                } 

            }

        } // end of for 

        //If the header was not printed, meaning there were no suspects found
        if (headerPrinted == false)
        {

            //Print that there are no suspects in the case
            fout << "There are no current suspects in this case" << endl;

        }
        else
        {

            //Print out the amount of suspects
            fout << "The number of possible suspects is: " << amountSuspects << endl;

            //Set the number of suspects back to zero
            amountSuspects = 0;

        }

        //Set headerPrinted to false
        headerPrinted = false;

        //Print the divider to the output file
        PrintDivider(fout, '-', 100);

        //Move the cursor to the next line
        fout << endl;

        //Move the cursor to the next line
        fin.ignore(100, '\n');

        //Set the case number back to 0
        tempCaseNum = 0;

        //Input the next crime from the capers (primer)
        fin.get(aCrime, 26);

    } // end of while 

}
