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

//creating struct...
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_TOPPINGS = 2;
const int MAX_DONUTS = 50;


struct donutType
{
    string name;
    bool type; /// true , dough base. false, cake base
    string filling;
    string toppings[MAX_TOPPINGS]; // two toppings mqx
    double price;
};

ifstream getFileStream(string); // done this one
int getDonuts(ifstream&, donutType[]); //done this one
bool continueMenu(string);
void sortByPrice(donutType[], int);
int searchByName(const donutType[], int, string); // in the process
void removeDonutFromList(donutType[], int&, int);
int getCheapestDonut(const donutType[], int); // in the process
void soldDonut(donutType, donutType[], int&);
void outputSoldDonuts(ofstream&, const donutType[], int);
void displayAvailableDonuts(const donutType[], int); //done this one
string allCaps(string); //done this one

int main()
{   int validity = 0;
    ifstream infile;
    ofstream outfile("sold.csv");
    string filename;
    string request;
    donutType donuts[MAX_DONUTS];
    donutType soldDonuts[MAX_DONUTS];
    int amtSold = 0;
    double total = 0;
    cout << fixed << setprecision(2);

    string msg = "Enter donut file:\n";
    string prompt = "will this complete your order?\n";
    //function that checks user input, returns a good file from the list...
    infile = getFileStream(msg);
    // reads in data from infile and stores it into the struct...
    int amtDonuts = getDonuts( infile, donuts);
        cout << "Welcome to Hank\'s Donut World!\n\n";
    do{
        //displays available donuts...
        displayAvailableDonuts(donuts, amtDonuts);
        cout << "\nEnter donut name or cheapest:\n";
        string in;
        getline(cin, in);
        in = allCaps(in);
        int donutIndex = 0;
        if (in == "CHEAPEST") {
           donutIndex = getCheapestDonut(donuts, amtDonuts);
            removeDonutFromList( donuts, amtDonuts, donutIndex);
        } else {
           donutIndex = searchByName(donuts, amtDonuts, in);
        }
        bool contOp = continueMenu(prompt);
        if(contOp){
            return 0;
        }
    }while (validity ==0);
    cout << "\ntest";
}

ifstream getFileStream(string msg)
{
    ifstream iFile;
    string in;
    do {
        //asks for input using function argument.
        cout << msg;
        getline(cin,in);
        // checks for user input failure.
        iFile.open(in);
        if (!iFile.is_open()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << msg;
            getline(cin,in);
        }
    }while(!iFile.is_open());
    //returns the "GOOD" file.
    return iFile;
}
int getDonuts(ifstream& infile, donutType donuts[]) {
    string line;
    int i = 0;
    unsigned int commaIndex = 0;
    while(!infile.eof()) {
        getline(infile, line);
        while (getline(infile, line)) {
            //find the first value in the struct... name
            commaIndex = line.find(',');
            donuts[i].name = line.substr(0, commaIndex);
            line.erase(0, commaIndex + 1);
            //finds a bool value in the struct by evaulating a bool
            //statement
            commaIndex = line.find(',');
            donuts[i].type = line.substr(0, commaIndex) ==
                             "dough";
            line.erase(0, commaIndex + 1);
            //finds filling value to store into struct...
            commaIndex = line.find(',');
            donuts[i].filling = line.substr(0, commaIndex);
            line.erase(0, commaIndex + 1);
            //finds the  1st topping in donuts then stores it into struct...
            commaIndex = line.find(',');
            donuts[i].toppings[0] = line.substr(0, commaIndex);
            line.erase(0, commaIndex + 1);
            //finds the 2nd topping in donuts then stores it into struct
            commaIndex = line.find(',');
            donuts[i].toppings[1] = line.substr(0, commaIndex);
            line.erase(0, commaIndex + 1);
            //finds price then stores it into struct
            donuts[i].price = stod(line);
            i++;
        }
    }
    return i;
}
bool continueMenu(string prompt){
    string choice;
    do {
        cout << prompt;
        getline(cin,choice);
        //makes user  input all caps..
        choice = allCaps(choice);
        if (choice == "YES"){
            return true;
        }
    }while( (choice != "NO"));
    return false;
}
//pass in donuts array, the "the sold" donuts... amnt donuts will be the amount of donuts
//sold,, in acending order by price... use bubble sort... then apply it
void sortByPrice(donutType donuts[], int amtDonuts){}
/*{

    int i, j;
    bool swapped;
    for (i = 0; i < amtDonuts - 1; i++) {
        swapped = false;
        for (j = 0; j < amtDonuts - i - 1; j++) {
            if (donuts[j] > donuts[j + 1]) {
                swap(donuts[j], donuts[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false) {
            break;
        }
    }
}
 */
// why const? no update needed.., make sure its case insensitve...

int searchByName(const donutType donuts[], int amtDonuts, string name)
{
   int removeIndex = 0;
cout << "You chose search by name!\n";

return 2;
}

int getCheapestDonut(const donutType donuts[], int amtDonuts)
{
cout << "You chose cheapest\n";
return 1;
}

string allCaps(string s)
{
    for (int i = 0; i < s.size(); i++){
        s[i] = toupper(s[i]);
    }
    return s;
}


//USED TO output the sold donuts to a csv file.
void outputSoldDonuts(ofstream& outfile, const donutType soldDonuts[], int amtSold)
{
    outfile << fixed << setprecision(2);
    outfile << "Name,Type,Filling,Topping1,Topping2,Price" << endl;

}

void displayAvailableDonuts(const donutType donuts[], int amtDonuts) {
    cout << "List of donuts" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < amtDonuts; i++) {
        cout << donuts[i].name << " " << donuts[i].price << endl;
    }

}

































/*
 *
#include <iostream>
#include <string>

using namespace std;

const int MAX_PART = 100;
int numParts = 0;

struct Part {
    int number;
    string name;
    int onHand;
} inventory[MAX_PART];

int findPart(int);
void insert();
void search();
void update();
void print();

int main() {
    //  Write your code here!
    return 0;
}

//  Write the implementations of findPart, insert, search, and update here!

void print() {
    std::printf("Part Number    Part Name                "
                "Quantity on Hand\n");
    for (int i = 0; i < numParts; ++i) {
        std::printf("%7d        %-25s%11d\n", inventory[i].number, inventory[i].name.c_str(), inventory[i].onHand);
    }
}
 */