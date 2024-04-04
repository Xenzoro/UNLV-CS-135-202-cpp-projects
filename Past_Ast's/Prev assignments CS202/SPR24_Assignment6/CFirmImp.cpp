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

 CFirm CFirm::operator+() const// unary operator; Deep Copy of the users Vector
 {
        CFirm newFirm;
        for(int i=0; i < Users.size();++i)
        {
            newFirm.Users.push_back(Users[i]);
        }
        return newFirm;
 }

 bool CFirm::operator>(const CFirm& other) const
 {
     return portfolioValue > other.portfolioValue;
 }

 bool CFirm::operator<(const CFirm& other) const
 {
     return portfolioValue < other.portfolioValue;
 }

 CFirm& CFirm::operator++() //pre-increment operator
 {
    //this operator overloading increments the
    // portfolio value of the CFirm object by 1
    // and returns a reference to the updated CFirm object.
    // overloaded pre-increment operator that adds a new CUser object to the users
    //help?
    CUser newUser;
    Users.push_back(newUser);
    return *this;
 }

 CFirm CFirm::operator++(int) //post-increment operator
 {
    //overloaded post-increment operator that adds a nw CUser object to the Users vector of the CFirm object and
    // returns a copy of the original object
    //confused
    CUser newUser;
    CFirm tempNew = *this;
    Users.push_back(newUser);
    return tempNew;
 }

 CFirm& CFirm::operator=(const CFirm& other) //Assignment operator
    //overloaded alignment operator that copies the users of another CFIrm object to the current object.
    {
        Users = other.Users;
        return *this;
    }

 ostream& operator<<(ostream& os, const CFirm& firm)
 //Friend funciton that overloads the << operator to output the firm information icluding the names of it's users
 {
     os << "Portfolio Value: " << firm.portfolioValue << endl;
     // how can i output the names of the users?
     return os;
 }

