#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "COrder.h"
#include "CUser.h"
#include "CFirm.h"
#include "CFile.h"

using namespace std;



int main() {
    
    cout << "Enter 3 orders for hardcoded entry" << endl;
    cout << "If the order number is greater than 3," 
         << "manual entry is needed" << endl;
    cout << "For orders greater than 3, user will manually enter" 
    << "only the orders that are requested - harcoded 3 entries" << endl;
    
    int newNumber=0; // varaible to store order number requested by user
    cout << "Enter number of orders: " << endl;
    cin>>newNumber;

 // Sample usage of the classes
    int numOrders = 3 ; // Example: 3 orders

    if(newNumber > 3)
        numOrders = numOrders + (newNumber - numOrders);

    else
        numOrders =3;

    // Create a vector to store the dynamically allocated COrder objects
    std::vector<COrder*> orders;

    // Create a vector to store the CUser objects
    std::vector<CUser> users;

    std::string sName, user;
        double price = 0.0;
        int quantity = 0;

    // Loop to create orders
    for (int i = 0; i < numOrders; ++i) {
        // std::string sName, user;
        // double price;

        // Hardcoded values for symbol, price, and user
        if (i == 0) {
            sName = "AAPL";
            price = 173.72;
            quantity = 10;
            user = "John_Doe";
        }
        else if (i == 1) {
            sName = "AMZN";
            price = 174.48;
            quantity = 18;
            user = "Alice_Smith";
        }
        else if (i == 2) {
            sName = "MSFT";
            price = 417.32;
            quantity = 48;
            user = "John_Doe"; // Same user as the first 
            //order for demonstration
        }
   
       else{
            std::cout << "Enter stock name for order " << i+1 << ": ";
            std::cin >> sName;

            std::cout << "Enter price for order " << i+1 << ": ";
            std::cin >> price;

            std::cout << "Enter quantity for order " << i+1 << ": ";
            std::cin >> quantity;

            std::cout << "Enter user for order " << i+1 << ": ";
            std::cin >> user;

            while(user!="John_Doe" && user!="Alice_Smith"){
                std::cout << "Enter user names as John_Doe" << 
                "or Alice_Smith only " << ": ";
                std::cin >> user;
            }
        }

        // Create COrder object using dynamic memory allocation
        COrder *pOrder = new COrder(sName, price, quantity, user);

        // Add the order to the vector
        orders.push_back(pOrder);

        // Find or create corresponding CUser
        auto it = std::find_if(users.begin(), users.end(), 
            [&user](const CUser& u) {
            return u.UserName == user;
            });

        if (it == users.end()) {
            // User not found, create a new CUser
            CUser newUser(user); //Here newUser is the object of CUser
            newUser.AddOrder(*pOrder);
            users.push_back(newUser);
        }
        else {
            // User found, add the order to existing CUser
            it->AddOrder(*pOrder);
        }
    }//end of for loop

    CFirm firm1;
    firm1.Users.push_back(users[0]);

    CFirm firm2;
    firm2.Users.push_back(users[1]);

    // Combine firm information using operator overloading
    CFirm combinedFirm = firm1 + firm2;

   
    // std::cout << +firm1 << std::endl;


    if (firm1 > firm2) {
        std::cout << firm1.Users[0].UserName + " has more orders than " + 
        firm2.Users[0].UserName + "\n";
    }
    else if (firm1 < firm2) {
        std::cout << firm1.Users[0].UserName + " has fewer orders than " + 
        firm2.Users[0].UserName + "\n";
    }
    else {
        std::cout << firm1.Users[0].UserName + " and " + 
        firm2.Users[0].UserName + " have the same number of orders\n";
    }

    cout << endl;
    cout << "Portiofolio Value" << endl;
    firm1.calculatePortfolio(); //Portfolio Value: 21768.6

    cout << endl;
    //User name: John_Doe
    //Portfolio Value: 21768.6
    cout << firm1.getPortfolio() << endl;



    ++firm1;
    std::cout << "\nFirm after pre-increment: " << firm1.Users.size() 
    << " users\n";

    firm2++;
    std::cout << "Firm after post-increment: " << firm2.Users.size() 
    << " users\n \n";


    
    // Write firm information to a file
    CFile::WriteToFirmFile(combinedFirm, "firm_info.txt");

    // Read and display firm information from the file
    CFile::ReadAndDisplayFirmFile("firm_info.txt");

    std::cout << firm1 << std::endl; //prints John_Doe
    std::cout << firm2 << std::endl; //prints Alice_Smith

    CFirm firm3 = firm1; //copy constructor

    firm1 = firm2; // Assignment operator

    std::cout << firm1 << std::endl; //prints Alice_Smith

    std::cout << firm3 << std::endl; //prints John_Doe

   
    CFirm firmCopy = +firm1;

    //Display the number of users in the original and copied CFirm objects

    //Original Firm: 2 users
    std::cout << "Original Firm: " << firm1.Users.size() << " users\n";

    //Copied Firm: 2 users
    std::cout << "Copied Firm: " << firmCopy.Users.size() << " users\n";


    COrder order("AAPL", 173.72, 10, "John_Doe");
    COrder updatedOrder = +order;
 
    std::cout << "\nOriginal Order: " << std::endl;
    order.orderDisplay();

    std::cout << "\nUpdated Order: " << std::endl;
    updatedOrder.orderDisplay();


    COrder tempOrder;
    cout << "\nEnter tempOrder Details: " << std::endl;
    cin>>tempOrder;

    cout << endl;
    cout << tempOrder << endl;


    for (COrder* order : orders) {
        delete order;
    }

   
    return 0;
}