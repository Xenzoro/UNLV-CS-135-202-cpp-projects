/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_6
    * Description: DESCRIPTION_OF_PROGRAM
    * Input: EXPECTED_PROGRAM_INPUT
    * Output: EXPECTED_PROGRAM_OUTPUT
*/
#include "CFirm.h"
#include <string>
using namespace std;

CFirm::CFirm()
{
    portfolioValue = 0.0;
}

 void CFirm::calculatePortfolio()
 {
 double total = 0;
    for (int i = 0; i < Users.size(); ++i)
    {
        for (int j = 0; j < Users[i].Orders.size(); ++j)
        {
            total += Users[i].Orders[j].getPrice() *
                     Users[i].Orders[j].getQuantity();
        }
    }
 }

 double CFirm::getPortfolio() const
 {
     return portfolioValue;
 }

 CFirm::CFirm(const CFirm& other) //copy constructor
 {
      //deep copy
      portfolioValue = other.portfolioValue;
      Users = other.Users;
 }

 CFirm CFirm::operator+(const CFirm& other) const  //Binary Operator
 {
    CFirm newFirm;
       for(int i=0; i < Users.size();++i)
       {
           newFirm.Users.push_back(Users[i]);
       }
     for(int i=0; i < other.Users.size();++i)
     {
         newFirm.Users.push_back(other.Users[i]);
     }
     return newFirm;
 }
 