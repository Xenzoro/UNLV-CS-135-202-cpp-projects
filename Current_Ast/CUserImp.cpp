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
#include "CUser.h"
#include "COrder.h"
#include <string>
using namespace std;

CUser::CUser(const string& userName)
{
    UserName = userName;
    return;
}

const vector<COrder>& CUser::getOrders() const
{
    return Orders;
}

void CUser::AddOrder(const COrder& order)
{
    Orders.push_back(order);
    return;
}
