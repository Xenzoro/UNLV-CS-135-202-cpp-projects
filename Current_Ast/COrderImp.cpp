/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_6
    * Description: DESCRIPTION_OF_PROGRAM
    * Input: EXPECTED_PROGRAM_INPUT
    * Output: EXPECTED_PROGRAM_OUTPUT
*/
#include "COrder.h"
#include <string>
using namepsace std;

COrder::COrder(const string& sName, double price, int quantity, const string& user){
    stockName = sName;
    Price = price;
    sQuantity = quantity;
    User = user;
    totalPrice = price * quantity;
}