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
#include "COrder.h"
#include <string>
using namespace std;

COrder::COrder()
{
    stockName = "";
    Price = 0.0;
    sQuantity = 0;
    User = "";
    totalPrice = 0.0;
}
COrder::COrder(const string& sName, double price, int quantity,
               const string& user)
{
    stockName = sName;
    Price = price;
    sQuantity = quantity;
    User = user;
    totalPrice = price * quantity;
}
double COrder::getPrice() const // remember to include scope
                                // resolution operator
{
    return Price;
}
int COrder::getQuantity() const
{
    return sQuantity;
}

void COrder::orderDisplay()
{
cout << "Stock Name: " << stockName << endl
     << "Price: $" << Price << endl
     << "Quantity: " << sQuantity << endl
     << "Total Price: $" << totalPrice << endl;
}

COrder COrder::operator+() // unary operator overloading
{
 double nuevoPrice = 1.10 * Price;
 int nuevosQuantity = 10 + sQuantity;
 double nuevoTotalPrice = nuevosQuantity * nuevoPrice;
 //ignore incorrect spelling... I cant spell lol
 COrder nueveoOrder(stockName,nuevoPrice,
                    nuevosQuantity, User);
 nueveoOrder.totalPrice = nuevoTotalPrice;
    return nueveoOrder; //returns the new object
}

istream& operator>> (istream& is, COrder& order) //don't need to
                      // include friend keyword like in the prototype.
{
    //read the values from the input stream
is >> order.stockName >> order.Price >> order.sQuantity >> order.User;

return is; //return the input stream
}

ostream& operator<<(ostream& os, COrder& order)
{
    //use os istead of cout to print the values?
os   << "corder extraction operator (stockname >> price >>"
        " quantity >> user)" << endl
     << "corder insertion operator user name: paul" << endl
     << "Stock Name: " << order.stockName << endl
     << "Price: $" << order.Price << endl
     << "Quantity: " << order.sQuantity << endl
     << "Total Price: $" << order.Price * order.sQuantity << endl;
    return os; //return the output stream
}