/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_6
    * Description: In this assignment you will learn to use operator
    * overloading both as member and non-member functions, friend
    * functions, this pointer, copy constructor. This assignment
    * demonstrates the usage of several classes such as COrder,
    * CUser, CFirm, and CFile for managing the orders, users, and
    * firms in a financial context.
    * Input: numbers '.' and some financial data
    * Output: The program will output the portfolio value of the firm
*/

#include "CFile.h"
#include "CFirm.h"
#include <fstream>
#include <iostream>

using namespace std;
//write to file function for firm
//very easy to overcomplicate the function
void CFile::WriteToFirmFile(const CFirm& firm, const std::string& fileName)
{
    double valPort = 0.0;
    ofstream givenFile(fileName);
    if(givenFile.is_open()){
    for(int i=0; i< firm.Users.size();++i)
    {   //writes the user name and order details
        givenFile << "User: " << firm.Users[i].UserName
                  << " Order details" << endl;
        //output the order details
        for (int j = 0; j < firm.Users[i].Orders.size(); ++j)
        {   //writes the stock name, price, quantity, total price, and user
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
    //writes the portfolio value
    //had to use valport since I didnt have access to the private variable
    //so I had to calculate it in the function and then write it to the file
    givenFile << "Portifolio Value: " << valPort << endl << endl;
    valPort = 0.0;
    }
    }
    givenFile.close();
}
 //write to file function for user
 void CFile::ReadAndDisplayFirmFile(const string& fileName)
{   //open the file
    ifstream givenFile;
    givenFile.open(fileName);
    //check if the file is open
    while(!givenFile.eof())
    {
       string tempLine;
       //get the line from the file
       getline(givenFile, tempLine);
         //print the line
       cout << tempLine << endl;
    }

}