/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_6
    * Description: DESCRIPTION_OF_PROGRAM
    * Input: EXPECTED_PROGRAM_INPUT
    * Output: EXPECTED_PROGRAM_OUTPUT
*/
#include "CUser.h"
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
