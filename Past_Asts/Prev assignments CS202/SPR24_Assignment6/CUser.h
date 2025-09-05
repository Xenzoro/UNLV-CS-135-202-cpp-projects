#ifndef CUSER_H
#define CUSER_H

#include <iostream>
#include <vector>
#include <string>
#include "COrder.h"


/**
 * @class CUser
 * @brief Represents a user with associated orders.
 *
 * The CUser class represents a user and maintains a collection of orders
 *  associated with that user. 
 * It provides functionality to initialize a user, retrieve the orders, 
 * and add new orders.
 */
class CUser
{
public:
    std::string UserName; // The name of the user.
    std::vector<COrder> Orders;// The collection of orders 
                                //associated with the user.
    /**
     * @brief Default constructor.
     *
     * This constructor initializes a CUser object with an empty UserName.
     */
    CUser();

    /**
     * @brief Parameterized constructor.
     *
     * This constructor initializes a CUser object with the 
     * provided UserName.
     *
     * @param userName The name of the user.
     */
    CUser(const std::string& userName);

    /**
     * @brief Get the orders associated with the user.
     *
     * This function returns a constant reference to the vector of 
     * COrder objects representing the orders associated with the user.
     *
     * @return A constant reference to the vector of COrder objects 
     * representing the orders associated with the user.
     */
    const std::vector<COrder>& getOrders() const;

    /**
     * @brief Add an order to the user's collection of orders.
     *
     * This function adds the provided COrder object to the 
     * user's collection of orders.
     *
     * @param order The COrder object to be added.
     */
    void AddOrder(const COrder& order);


    
};


#endif