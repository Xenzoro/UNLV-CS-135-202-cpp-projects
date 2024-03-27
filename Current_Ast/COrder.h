#ifndef CORDER_H
#define CORDER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


/**
 * @class COrder
 * @brief Represents an order for a stock.
 *
 * The COrder class stores information about a stock order, including 
 * the stock name, price, quantity, total price, and the user 
 * associated with the order. It provides functionality to initialize 
 * the order, retrieve the price and quantity, display the order details,
 * and perform operator overloading for addition.
 */
class COrder
{
public:
    std::string stockName;
    double Price;
    int sQuantity;
    double totalPrice;
    std::string User;

    /**
     * @brief Default constructor.
     *
     * This constructor initializes the COrder 
     * object with default values:
     * - stockName: empty string
     * - Price: 0.0
     * - sQuantity: 0
     * - totalPrice: 0.0
     * - User: empty string
     */
    COrder(); //constructor

    /**
     * @brief Parameterized constructor.
     *
     * This constructor initializes the COrder object with 
     * the provided values.
     *
     * @param sName The name of the stock.
     * @param price The price of the stock.
     * @param quantity The quantity of the stock.
     * @param user The user associated with the order.
     */
    COrder(const std::string& sName, double price, int quantity,
     const std::string& user);
    // parameterized constructor initialize the objects attributes
    // with the provided parameters accrodingdly
    /**
     * @brief Get the price of the stock.
     *
     * @return The price of the stock.
     */
    double getPrice() const; //getter

    /**
     * @brief Get the quantity of the stock.
     *
     * @return The quantity of the stock.
     */
    int getQuantity() const; //getter

    /**
     * @brief Display the order details.
     *
     * This function prints the stock name, price, quantity, 
     * and total price of the order to the console.
     */
    void orderDisplay(); //displays or prints the order details

    /**
     * @brief Overloaded operator+ for addition.
     *
     * This operator overloading function adds 10% to the price 
     * and increases the quantity by 10 for the order.
     * It returns a new COrder object with the updated values.
     *
     * @return A new COrder object with the updated values.
     */
    COrder operator+(); //overloaded operator+ for addition

    /**
     * @brief Friend function declaration for overloading the >> operator.
     *
     * This friend function allows overloading the >> operator 
     * to read and assign values to a COrder object from an input stream.
     *
     * @param is The input stream.
     * @param order The COrder object to be assigned values 
     * from the input stream.
     * @return The input stream after reading and assigning values
     *  to the COrder object.
     */

    friend std::istream& operator>>(std::istream& is, COrder& order);
    //overloading the >> operator to read and assign values to a COrder object from an input stream
    /**
     * @brief Friend function declaration for overloading the << operator.
     *
     * This friend function allows overloading the << operator to 
     * output the COrder object's information to an output stream.
     *
     * @param os The output stream.
     * @param order The COrder object to be outputted.
     * @return The output stream after writing the 
     * COrder object's information.
     */
    friend std::ostream& operator<<(std::ostream& os, COrder& order);
    //overloading the << operator to output the COrder object's information to an output stream
};


#endif