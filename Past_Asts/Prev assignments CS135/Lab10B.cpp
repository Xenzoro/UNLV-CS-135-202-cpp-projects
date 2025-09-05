/* * Name: Jacob Martinez,5007553403, 1011, Lab10B
    * Description: I will use input and output
    * using structs, and arrays...
    * with three different functions I will take data from a file...
    * read that data into an array...
    * then output that array in a neat box using IOMANIP...
    * I will also calculate some stats...
    * Input: file name
    * Output: neat box with customer info and stats
    * about the customers...
    *
    * an example of code...
Enter file name
**test
Error: Invalid file name
Enter file name
**purchases1.csv
+-------------+--------------+-------+----------+----------+--------+
| Customer ID | Product Name | Price | Quantity | Tax Rate | Total  |
+-------------+--------------+-------+----------+----------+--------+
|     A134CX2 |        shirt | 10.00 |        1 |     8.25 |  10.82 |
|     A134CX2 |        pants | 15.95 |        2 |     8.25 |  34.53 |
|     A134CX2 |       jacket | 24.49 |        1 |     8.25 |  26.51 |
|     4J37I2I |       blouse | 19.99 |        1 |     8.25 |  21.64 |
|     4J37I2I |        pants | 14.98 |        1 |     8.25 |  16.22 |
|     4J37I2I |      mittens |  9.99 |        3 |     8.25 |  32.44 |
|     4J37I2I |        socks | 10.98 |        3 |     8.25 |  35.66 |
|     B834621 |       gloves |  9.99 |        2 |     7.15 |  21.41 |
|     B834621 |          cap | 24.99 |        3 |     7.15 |  80.33 |
|     27G8ZZY |     earrings | 49.99 |        1 |     8.25 |  54.11 |
+-------------+--------------+-------+----------+----------+--------+
Unique users: 4
Average total: $33.37
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
//creating struct...
struct PurchaseType{
    string customerID;
    string productName;
    double price;
    int qtyPurchase;
    double taxRate;
    double sum;
};
//A fuction that checks for input error...
void openFile(ifstream& , string prompt);
//A function that reads input into array...
void readFile(ifstream&, PurchaseType[]);
//A function that prints the read input...
void printPurchasedData(PurchaseType[], int);
int main (){

    ifstream iFile;
    string txt = "Enter file name\n**";
    const int s = 10;
    PurchaseType Purchase[s];
    //first function checks input...
    openFile(iFile, txt);
    readFile(iFile, Purchase);
    printPurchasedData(Purchase,s);
    return 0;
}
void openFile(ifstream& iFile, string prompt){
    string fileName;
    do{
       cout << prompt;
       cin >> fileName;
       //opens file...
       iFile.open(fileName);
       //checks if file has opened
       if(!iFile.is_open()){
           //if out... error will output
           cout << "\nError: Invalid file\n";
       }
    }while(!iFile.is_open());

}
void readFile(ifstream& iFile, PurchaseType Purchase[]){
    string s1;
    const int length = 10;
    for (int i = 0; i < length && getline(iFile,s1); i++){
        istringstream ss(s1);

        getline(ss, Purchase[i].customerID,',');
        getline(ss, Purchase[i].productName,',');
         ss >> Purchase[i].price;
         ss.ignore();
         ss >> Purchase[i].qtyPurchase;
         ss.ignore();
         ss >> Purchase[i].taxRate;

         Purchase[i].taxRate *=100;
         Purchase[i].sum = Purchase[i].price * Purchase[i].qtyPurchase *(1 +Purchase[i].taxRate / 100);
    }
}
void printPurchasedData(PurchaseType Purchase[], int s){
    int uniqueCustomer = 0;
    double sum = 0;
    //first row displays categories about the customer...
    cout << "\n+-------------+--------------+-------+----------+----------+--------+" << endl
         << "| Customer ID | Product Name | Price | Quantity | Tax Rate | Total  |" << endl
         << "+-------------+--------------+-------+----------+----------+--------+" << endl;
    // a for loop iterates throught the different customers...
        for(int i = 0; i < s; i++){
            cout << "| " << setw(11) << Purchase[i].customerID << " | "
                 << setw(12) << Purchase[i].productName << " | "
                 << setw(5) << setprecision(2) << fixed << Purchase[i].price
                 << " | " << setw(8) << Purchase[i].qtyPurchase
                 << " | " << setw(8) << setprecision(2) << fixed << Purchase[i].taxRate << " | " << setw(6)
                 << setprecision(2) << fixed << Purchase[i].sum << " |" << endl;
            //calculates the sum..
            sum += Purchase[i].sum;
            //counts special customers++...
            if (Purchase[i].customerID != Purchase[i-1].customerID){
                uniqueCustomer++;
            }
        }
            //final line to close off the box...
            cout << "+-------------+--------------+-------+----------+----------+--------+" << endl;
        // checks average of all the customers...
        double aveSum = sum/ s;
        //displayes customer data...
        cout << "Unique users:  " << uniqueCustomer << endl
             << "Average total: $" << setprecision(2)
             << fixed << aveSum;
}



