/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_6
    * Description: DESCRIPTION_OF_PROGRAM
    * Input: EXPECTED_PROGRAM_INPUT
    * Output: EXPECTED_PROGRAM_OUTPUT
*/

#include "CFile.h"
#include <iostream>

using namespace std;

void CFile::WriteToFirmFile(const CFirm& firm, const std::string& fileName)
{
    ofstream pFile(fileName);
    pFile.open(fileName);
    if(!pFile.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    //iteratre over each CUser in firm.Users
    for(int i = 0; i < firm.Users.size(); ++i)
    {
        pFile << firm.Users[i].getUserName() << endl;
        //iterate over each COrder in CUser.Orders
        for(int j = 0; j < firm.Users[i].Orders.size(); ++j)
        {
            pFile << firm.Users[i].Orders[j].getStockName() << " "
                  << firm.Users[i].Orders[j].getPrice() << " "
                  << firm.Users[i].Orders[j].getQuantity() << " "
                  << firm.Users[i].Orders[j].getUser() << endl;
        }
    }
}