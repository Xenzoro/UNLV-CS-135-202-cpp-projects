/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_6
    * Description: DESCRIPTION_OF_PROGRAM
    * Input: EXPECTED_PROGRAM_INPUT
    * Output: EXPECTED_PROGRAM_OUTPUT
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
     << "Price: " << Price << endl
     << "Quantity: " << sQuantity << endl
     << "Total Price: " << totalPrice << endl;
}

COrder COrder::operator+() // unary operator overloading
{
 double nuevoPrice = 1.10 * Price;
 int nuevosQuantity = 10 + sQuantity;
 double nuevoTotalPrice = nuevosQuantity * nuevoPrice;

 COrder nueveoOrder(stockName,nuevoTotalPrice,
                    nuevosQuantity, User);
    return nueveoOrder; //returns the new object
} //                |
  // ask for help? \/

istream& operator>> (istream& is, COrder& order) //dont need to
                      // include friend keyword like in the prototype.
{
    //read the values from the input stream
is >> order.stockName >> order.Price >> order.sQuantity >> order.User;

return is; //return the input stream
}
//ask for help with this function too !
ostream& operator<< (ostream& os, const COrder& order)
{
    //use os istead of cout to print the values?
    //dont we already do this in the orderDisplay function?
os   << "Stock Name: " << order.stockName << endl
     << "Price: " << order.Price << endl
     << "Quantity: " << order.sQuantity << endl
     << "Total Price: " << order.totalPrice << endl;
    return os; //return the output stream
}