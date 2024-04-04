#ifndef CFIRM_H
#define CFIRM_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "CUser.h"

/**
 * @class CFirm
 * @brief Represents a firm with a collection of users and a 
 * portfolio value.
 *
 * The CFirm class represents a firm and maintains a collection of users 
 * associated with the firm. It also stores a portfolio value representing 
 * the firm's financial worth. The class provides various member functions
 * for calculating the portfolio, accessing the portfolio value,
 * performing operator overloading for combining firm information, 
 * and more.
 */
class CFirm
{
public:
    std::vector<CUser> Users; // The collection of users associated 
                                //with the firm.
    double portfolioValue; // The portfolio value of the firm.

    /**
     * @brief Default constructor.
     *
     * This constructor initializes a CFirm object with an 
     * empty Users vector and a portfolioValue of 0.0.
     */
    CFirm();

    /**
     * @brief Calculate the portfolio value of the firm.
     *
     * This function calculates the portfolio value of the firm based
     * on the orders and assets of its users.
     * The calculated value is stored in the portfolioValue 
     * member variable.
     */
    void calculatePortfolio();

    /**
     * @brief Get the portfolio value of the firm.
     *
     * This function returns the portfolio value of the firm.
     *
     * @return The portfolio value of the firm.
     */
    double getPortfolio() const;

    /**
     * @brief Copy constructor.
     *
     * This constructor creates a new CFirm object by copying
     *  the contents of another CFirm object.
     *
     * @param other The CFirm object to be copied.
     */
    CFirm(const CFirm& other);

    /**
     * @brief Operator overloading for combining firm information.
     *
     * This operator overloading allows the addition of two CFirm objects.
     * It creates a new CFirm object with the combined Users vectors
     * and the sum of the portfolio values.
     *
     * @param other The CFirm object to be combined with.
     * @return A new CFirm object with the combined information.
     */
    CFirm operator+(const CFirm& other) const;

    /**
     * @brief Unary operator overloading for deep copying the Users vector.
     *
     * This unary operator overloading creates a new CFirm object with
     * a deep copy of the Users vector.
     *
     * @return A new CFirm object with a deep copy of the Users vector.
     */
    CFirm operator+() const;

    /**
     * @brief Operator overloading for comparing two CFirm objects.
     *
     * This operator overloading compares two CFirm objects based
     *  on their portfolio values.
     * It returns true if the portfolio value of the current CFirm object
     *  is greater than the other CFirm object.
     *
     * @param other The CFirm object to be compared with.
     * @return True if the portfolio value is greater, false otherwise.
     */
    bool operator>(const CFirm& other) const;

    /**
     * @brief Operator overloading for comparing two CFirm objects.
     *
     * This operator overloading compares two CFirm objects based
     *  on their portfolio values.
     * It returns true if the portfolio value of the current CFirm
     *  object is less than the other CFirm object.
     *
     * @param other The CFirm object to be compared with.
     * @return True if the portfolio value is less, false otherwise.
     */
    bool operator<(const CFirm& other) const;

    /**
     * @brief Prefix increment operator overloading.
     *
     * This operator overloading increments the portfolio value
     *  of the CFirm object by 1 and returns a reference to 
     * the updated CFirm object.
     *
     * @return A reference to the updated CFirm object.
     */
    CFirm& operator++();

    /**
     * @brief Postfix increment operator overloading.
     *
     * This operator overloading increments the portfolio value
     *  of the CFirm object by 1 and returns a copy of the CFirm object
     *  before the increment.
     *
     * @return A copy of the CFirm object before the increment.
     */
    CFirm operator++(int);

    /**
     * @brief Assignment operator overloading.
     *
     * This operator overloading assigns the contents of another 
     * CFirm object to the current CFirm object.
     *
     * @param other The CFirm object to be assigned.
     * @return A reference to the updated CFirm object 
     * after assignment.
     */
    CFirm& operator=(const CFirm& other);


    /**
     * @brief Friend function declaration for overloading the << operator.
     *
     * This friend function allows overloading the << operator to output
     *  the CFirm object's information to an output stream.
     *
     * @param os The output stream.
     * @param firm The CFirm object to be outputted.
     * @return The output stream after writing the 
     * CFirm object's information.
     */
    friend std::ostream& operator<<(std::ostream& os, const CFirm& firm);

    
};


#endif
