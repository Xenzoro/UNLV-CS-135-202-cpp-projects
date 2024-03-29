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
    ofstream givenFile(fileName);
    givenFile.open(fileName);

    for(int i=0; i< firm.Users.size();++i) {
        givenFile << "User: " << firm.Users[i].UserName
                  << "Order details" << endl;

        for (int j = 0; j < firm.Users[i].Orders.size(); ++j)
        {
            givenFile
                    << "   Stock Name: "
                    << firm.Users[i].Orders[j].stockName << ", "
                    << "Price: " << firm.Users[i].Orders[j].Price
                    << ", "
                    << "Stock Quantity: "
                    << firm.Users[i].Orders[j].sQuantity
                    << ", "
                    << "Total Price: "
                    << firm.Users[i].Orders[j].totalPrice
                    << "Portfolio: " << firm.getPortfolio() << endl;
        }
    }
    givenFile.close();
}

static void ReadAndDisplayFirmFile(const string& fileName)
{
    ifstream givenFile;
    givenFile.open(fileName);

    cout << "Firm Information: " << endl;
    while(!givenFile.eof())
    {
       string tempLine;
       givenFile >> tempLine;
       //check if the line is empty or starts with U
       if(tempLine.size() == 0)
       {
           continue;
       }
       if(tempLine[0] != 'U')
       {
           continue;
       }
       string wrd;
       wrd = tempLine.substr(0,5);
       if(wrd != "User:")
       {
           continue;
       }
       wrd = tempLine.substr(6, tempLine.size() - 20);
       cout << wrd << endl;
    }

}