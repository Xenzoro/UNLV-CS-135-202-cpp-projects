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
#include "CFirm.h"
#include "CUser.h"
#include "COrder.h"
#include <string>
using namespace std;

CFirm::CFirm()
{
    portfolioValue = 0.0;
}
//check this function
 void CFirm::calculatePortfolio()
 {

    for (int i = 0; i < Users.size(); ++i)
    {
        for (int j = 0; j < Users[i].Orders.size(); ++j)
        {
            portfolioValue += Users[i].Orders[j].getPrice() *
                            Users[i].Orders[j].getQuantity();
        }
    }
    cout << "Portfolio Value: " << portfolioValue;


 }

 double CFirm::getPortfolio() const
 {
     for(int i=0; i < Users.size();++i)
     {

         cout << endl << "User name: " << Users[i].UserName << endl;

     }
     cout << "Portfolio Value: ";
     return portfolioValue;
 }

 CFirm::CFirm(const CFirm& other) //copy constructor
 {
      //deep copy
      for(int i=0; i < other.Users.size();++i)
      {
          Users.push_back(other.Users[i]);
      }
      portfolioValue = other.portfolioValue;


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
     return Users[0].Orders.size() > other.Users[0].Orders.size();
 }

 bool CFirm::operator<(const CFirm& other) const
 {
     return Users[0].Orders.size() < other.Users[0].Orders.size();
 }

 CFirm& CFirm::operator++() //pre-increment operator
 {
    //this operator overloading increments the
    // portfolio value of the CFirm object by 1
    // and returns a reference to the updated CFirm object.
    // overloaded pre-increment operator that adds a new CUser object to the users

    CUser newUser("");
    Users.push_back(newUser);
    return *this;
 }

 CFirm CFirm::operator++(int) //post-increment operator
 {
    //overloaded post-increment operator that adds a nw CUser object to the Users vector of the CFirm object and
    // returns a copy of the original object
    //confused
    CUser newUser("");
    Users.push_back(newUser);
    return *this;
 }

 CFirm& CFirm::operator=(const CFirm& other) //Assignment operator
    //overloaded alignment operator that copies the users of another CFIrm object to the current object.
    {
        //deep copy
        if(this != &other)
        {
            Users.clear();
            for(int i=0; i < other.Users.size();++i)
            {
                Users.push_back(other.Users[i]);
            }
        }
        return *this;
    }

 ostream& operator<<(ostream& os, const CFirm& firm)
 //Friend funciton that overloads the << operator to output the firm information icluding the names of it's users
 {
    for(int i=0; i < firm.Users.size();++i)
    {
        if(firm.Users[i].UserName.empty()){
            continue;
        }
        os << "Firm Information: " << endl
           << firm.Users[i].UserName << endl <<endl;
    }
    //no need for this i think?
   /*for(int i=0; i < firm.Users.size();++i)
   {
       os << "User: " << firm.Users[i].UserName << "Order details" << endl;

       vector<COrder> tempOrders = firm.Users[i].getOrders();
        for( int j=0; j < tempOrders.size(); ++j)
       {
           os << "   " << "Stock Name: " << tempOrders[j].stockName << endl
              << "Price: " << tempOrders[j].Price << endl
              << "Quantity: " << tempOrders[j].sQuantity << endl
              << "Total Price: " << tempOrders[j].totalPrice << endl;

       }
   }*/
     return os;
 }

