/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_6
    * Description: DESCRIPTION_OF_PROGRAM
    * Input: EXPECTED_PROGRAM_INPUT
    * Output: EXPECTED_PROGRAM_OUTPUT
*/

#include "CFile.h"
#include "CFirm.h"
#include <fstream>
#include <iostream>

using namespace std;

void CFile::WriteToFirmFile(const CFirm& firm, const std::string& fileName)
{
    double valPort = 0.0;
    ofstream givenFile(fileName);
    if(givenFile.is_open()){
    for(int i=0; i< firm.Users.size();++i)
    {
        givenFile << "User: " << firm.Users[i].UserName
                  << " Order details" << endl;

        for (int j = 0; j < firm.Users[i].Orders.size(); ++j)
        {
            givenFile << "   Stock Name: "
                      << firm.Users[i].Orders[j].stockName << ", "
                      << "Price: " << firm.Users[i].Orders[j].Price
                      << ", "
                      << "Stock Quantity: "
                      << firm.Users[i].Orders[j].sQuantity
                      << ", "
                      << "Total Price: "
                      << firm.Users[i].Orders[j].totalPrice << ", "
                      << "User: "
                      << firm.Users[i].Orders[j].User << endl;
                      valPort += firm.Users[i].Orders[j].Price * firm.Users[i].Orders[j].sQuantity;
        }

    givenFile << "Portifolio Value: " << valPort << endl << endl;
    valPort = 0.0;
    }
    }
    givenFile.close();
}

 void CFile::ReadAndDisplayFirmFile(const string& fileName)
{
    ifstream givenFile;
    givenFile.open(fileName);

    while(!givenFile.eof())
    {
       string tempLine;
       //get the line from the file
       getline(givenFile, tempLine);
         //print the line
       cout << tempLine << endl;
    }

}