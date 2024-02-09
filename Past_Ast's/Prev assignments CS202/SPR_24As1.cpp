/*
    Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_1
    Description: The purpose of this assignment is to help refresh
    your memory of C++ programming and get your
    mind back into thinking logically and critically.
    The objective of this assignment is to build a
    terminal based application that generates an ASCII
    representation of the United States map with
    its states/cities. The program should also allow users
    to input the name of a state/city and retrieve
    information about it from the map. It is important to emphasize
    that while there are better ways
    to do this, you will not learn them until about a month into CS202.
    Finally, in order to get high
    marks, your program must compile and run on code grade
    - this means, your program should work
    correctly and follow all instructions.
    Input: boundary.csv city.csv and search function
    Output: map of the us with boundary and cities.
    also search outputs
    PS C:\Users\origi\CLionProjects\UNI\cmake-build-debug>
    ./a.exe boundary.csv city.csv
    "-search=Ashland,Albuquerque,Allentown,Au"
    Enter the name of a city: Ashland

    City: Ashland
    State: OR
    latitude: 42.1947222
    longitude: -122.7083333

    Enter the name of a city: Albuquerque

    City: Albuquerque
    State: NM
    latitude: 35.0844444
    longitude: -106.6505556

    Enter the name of a city: Allentown

    City: Allentown
    State: PA
    latitude: 40.6083333
    longitude: -75.4905556

    ERROR: Invalid city 'Au'. did you mean to say?
    1.Ashland
    2.Albuquerque
    3.Allentown
    4.Aurora
    5.Aurora
    6.Austin

    and
    *Grand Forks ND
*Seattle WA
*Great Falls MT
*Missoula MT
*Bismarck ND
*Fargo ND
*Vancouver WA
*Walla Walla WA
*Billings MT
*Portland OR
*Aberdeen SD
*Salem OR
*Saint Paul MN
*Minneapolis MN
*Bangor ME
*Green Bay WI
*Colchester VT
*Burlington VT
*Eugene OR
*Rapid City SD
*Rochester MN
*Portland ME
*Lewiston ME
*Nampa ID
*Idaho Falls ID
*Sioux Falls SD
*Rochester NY
*Concord NH
*Pocatello ID
*Casper WY
*Madison WI
*Milwaukee WI
*Grand Rapids MI
*Buffalo NY
*Bennington VT
*Nashua NH
*Manchester NH
*Ashland OR
*Rockford IL
*Warren MI
*Detroit MI
*Worcester MA
*Boston MA
*Cedar Rapids IA
*Aurora IL
*Chicago IL
*Toledo OH
*Springfield MA
*Hartford CT
*Warwick RI
*Providence RI
*Cranston RI
*Laramie WY
*Cheyenne WY
*Omaha NE
*Bellevue NE
*Des Moines IA
*Davenport IA
*Fort Wayne IN
*Cleveland OH
*Bridgeport CT
*New Haven CT
*Eureka CA
*West Valley City UT
*Salt Lake City UT
*Lincoln NE
*Paterson NJ
*Newark NJ
*Jersey City NJ
*New York NY
*Provo UT
*Pittsburgh PA
*Allentown PA
*Denver CO
*Aurora CO
*Indianapolis IN
*Columbus OH
*Wilmington DE
*Newark DE
*Philadelphia PA
*Parkersburg WV
*Columbia MD
*Baltimore MD
*Dover DE
*Colorado Springs CO
*Topeka KS
*Overland Park KS
*Kansas City MO
*Saint Louis MO
*Silver Spring MD
*Arlington VA
*Sacramento CA
*Louisville KY
*Huntington WV
*Charleston WV
*San Francisco CA
*Wichita KS
*Evansville IN
*Owensboro KY
*Lexington-Fayette KY
*San Jose CA
*Springfield MO
*Richmond VA
*Norfolk VA
*Las Vegas NV
*Tulsa OK
*Nashville TN
*Paradise NV
*Henderson NV
*Santa Fe NM
*Fayetteville AR
*Knoxville TN
*Greensboro NC
*Raleigh NC
*Oklahoma City OK
*Norman OK
*Fort Smith AR
*Memphis TN
*Charlotte NC
*Albuquerque NM
*Little Rock AR
*Los Angeles CA
*Atlanta GA
*Columbia SC
*Phoenix AZ
*Mesa AZ
*Birmingham AL
*San Diego CA
*Dallas TX
*North Charleston SC
*Charleston SC
*Tucson AZ
*Las Cruces NM
*Shreveport LA
*Jackson MS
*Montgomery AL
*Columbus GA
*Savannah GA
*Hattiesburg MS
*Austin TX
*Baton Rouge LA
*Gulfport MS
*Jacksonville FL
*San Antonio TX
*Tampa FL
*Miami FL
this is just
 some of whats needed to be output

*/

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
//structs used inside the assignment
struct Coordinate {
    double latitude;
    double longitude;
};
struct City {
    string name;
    string state;
    Coordinate coordinate;
};
struct Node {
    City city;
    int row;
    int col;
};

bool isNodeLessThan(const Node& this_, const Node& other);
void convertCoordinate(Node& this_, const Coordinate& coordinate);
void insertNode(vector<Node>& nodes, Node& node);
string cityAsString(const City& city);
string nodeAsString(const Node& node);
void readBoundary(ifstream& input, vector<Node>& nodes);
void readCities(ifstream& input, vector<Node>& nodes);
void printNodes(vector<Node>& nodes);
bool search(const string& name, vector<Node>& nodes, vector<Node>& lst);
//global vars
static const double MAX_LATITUDE = 49.373112;
static const double MIN_LONGITUDE = -124.769867;

int main (int argc, char* argv[]){

    ifstream iFile,iFile2;
    string file1,file2,input3,input4,input5;
    vector<Node> nodes;
    vector<Node> lst;
    // this checks if the arguments are less than 2, if so execute this.
    if(argc <= 2){
        cout << "error: Invalid number of arguments provided. Missing "
             << 4 - argc << " out of 3" << endl;
        return 0;
        }
    // if and only if the arguments are 3! do this.
    if(argc == 3){
        file1 = argv[1];
        file2 = argv[2];

        iFile.open(file1);
        if (!iFile.is_open()){
            cout << "error: Input file '" << file1
                 << "' does not exist. Program terminated\n";
            return 0;
            }
    readBoundary(iFile,nodes);
            cout << "US and A boundary map\n"
                 << "**********************\n";
            printNodes(nodes);

    iFile2.open(file2);
        if (!iFile2.is_open()){
            cout << "error: failed to open '" << file2
                 << "' does not exist. Program terminated\n";
            return 0;
        }
    readCities(iFile2,nodes);
            cout << "US and A city map\n"
                 << "**********************\n";
            printNodes(nodes);

    }
    // if the arguments are greater than 3 do this
    if(argc >= 3){
        file1 = argv[1];
        file2 = argv[2];
        iFile.open(file1);
        // dont techincally need this
        readBoundary(iFile,nodes);
        iFile2.open(file2);
        readCities(iFile2,nodes);
        // I start at index argc==3 beacause

        for(int i = 3; i < argc; i++){
            string lastArg = argv[i],searchString;
            if(lastArg =="-printAll"){

                for(int j= 0 ; j <= nodes.size(); j++){
                    //dont need this if statement either
                    //if i get rid of read boundaries
                    if(nodes[j].city.name.empty()){
                        continue;
                    }
                    cout << "*" << nodes[j].city.name
                         << " " << nodes[j].city.state << endl;
                }
                return 0;
            }   // i break this string down to find if SEARCH EXISTS
                searchString =
                        lastArg.substr(0,lastArg.find("=")+1);
                if (searchString == "-search="){
                    //counter for index
                    int index = 0;
                    // getting rid of "-search="
                    lastArg.erase(0,lastArg.find('=')+1);
                    //while my string of names isnt empty do this!
                    while(!lastArg.empty()){
                    // ss = city
                    searchString =
                    lastArg.substr(0,lastArg.find(','));
                    // put into function
                    if(search(searchString,nodes,lst)){
                        cout << "Enter the name of a city: "
                             << lst[index].city.name <<endl << endl
                             << "City: " << lst[index].city.name
                             << endl
                             << "State: " << lst[index].city.state
                             << endl
                             << setprecision(10) << "latitude: "
                             <<lst[index].city.coordinate.latitude
                             << endl << "longitude: "
                             << lst[index].city.coordinate.longitude
                             << endl << endl;
                                index++;
                    }else{
                        cout << "ERROR: Invalid city '"
                             << searchString
                             << "'. did you mean to say?\n";
                        // loops through all instances of the similar
                        // case
                            for(int j = 0 ; j < lst.size(); j++){
                        cout << j+1 <<"." << lst[j].city.name << endl;
                            }
                    }

                    //erases it
                    if(lastArg.find(',') != string::npos){
                        //erases it only if it is perfect!
                    lastArg.erase(0,lastArg.find(',')+1);
                    }
                    // clears the string so I can break out of
                    // the looop
                    else{
                        lastArg.clear();
                    }
                    }
                    //required to check for errors!
                }else{
                    cout << "error: invalid command '"<< lastArg
                         <<"' found. program terminated.";
                }
            }
        }
    return 0;
}
//function that checks node
bool isNodeLessThan(const Node& this_, const Node& other){
    if( this_.row > other.row){
        return true;
    }
    if (this_.row == other.row){
        if(this_.col >= other.col){
            return true;
        }
    }
    return false;
}
void convertCoordinate(Node& this_, const Coordinate& coordinate){
    //pretty simple function, taken directly from annoncements!
    // we essentially simplify the row and column to simple integers
    //0 1 2 3 4 5 6 etc..
    //updates the value of the row and column at THIS INSTANCE.
    this_.row = round(2 * (MAX_LATITUDE - coordinate.latitude));
    this_.col = round(2 * (coordinate.longitude - MIN_LONGITUDE));
}
            //           has no data       has data for first
            // pass
void insertNode(vector<Node>& nodes, Node& node){
    // if the vector is empty (bc we just started
    // we store it in the NEXT available
    //pos).
    if (nodes.empty()) {
        nodes.push_back(node);
        }
        if(!nodes.empty()) {

            for (int i = 0; i <= nodes.size(); i++) {

            if (isNodeLessThan(nodes[i], node)) {
                //might have to change position of i to - i
                nodes.insert(nodes.begin() + i, node);
                return;
                }
            }
             nodes.push_back(node);
        }
    }

string cityAsString(const City& city){
    string out = city.name + " " + city.state;
    return out;
}
string nodeAsString(const Node& node){
    //nested struct
    if (node.city.name.empty()){
        return "#";
    }else {
        string out = cityAsString(node.city);
        return "*" + out;
    }
}
void readBoundary(ifstream& input, vector<Node>& nodes){
    Node tempNode;
    string str1, str2;
    // this while loop reads each line of the csv.boundary
    // file until there are no more lines to read
    while(getline(input, str1)){
        // this parses str1 in the first sequment
        // which is then stored into str2
        // str2 is then stored in a instance of node or
        //tempnode
        str2 = str1.substr(0,str1.find(','));
        str1 = str1.substr(str1.find(',') + 1, str1.size());
        // the reason we do stod is because
        // a string CANNOT be stored into a DOUBLE,
        // so we can convert a string which ONLY has
        //numbers into a double using function
        //stod(string);
        tempNode.city.coordinate.latitude = stod(str2);
        tempNode.city.coordinate.longitude = stod(str1);
        //we call convert coord using an INSTANCE of tempnode and
        //the instance of the COORDINATES
        //the COORDINATES contains BOTH latitude and Longitude!
        convertCoordinate(tempNode, tempNode.city.coordinate);
        // insert nodes checks each INSTANCE of a node
        insertNode(nodes, tempNode);

    }
}
void readCities(ifstream& input, vector<Node>& nodes){
    Node tempNode;
    string str1,str2,str3;
    while(getline(input, str1)){
        // this function is basically the same as read boundaries
        // ++ 2 more strings which we can break apart using
        // substr,.find,and .size!
        str2 = str1.substr(0,str1.find(','));
        tempNode.city.name = str2;
        str2 = str1.substr(str1.find(',')+ 1,str1.size());
        str3 = str2.substr(0,str2.find(','));
        tempNode.city.state = str3;
        str1 = str2.substr(str2.find(',')+1,str2.size());
        str2 = str1.substr(0,str1.find(','));
        tempNode.city.coordinate.latitude = stod(str2);
        str2 = str1.substr(str1.find(',') + 1,str1.size());
        tempNode.city.coordinate.longitude = stod(str2);
        convertCoordinate(tempNode,tempNode.city.coordinate);
        insertNode(nodes,tempNode);
    }
}
void printNodes(vector<Node>& nodes){
    //postition is my column and line is my row
    int col = 0; // position!
    int row = 0; // line!
    // I used a forloop to iterate through the
    // entire vector
    for(int i = 0; i < nodes.size(); i++){
        while(row < nodes[i].row){
        cout << "\n";
        row++;
        col = 0;
        }
            if(col > nodes[i].col){
                continue;
        }
        while(col < nodes[i].col){
            cout << " ";
            col++;
        }
        // adjusts for the position of the string/name
        cout << nodeAsString(nodes[i]);
        col += nodeAsString(nodes[i]).length();
    }
        cout << "\n";
    }

bool search(const string& name, vector<Node>& nodes, vector<Node>& lst) {
for(int i=0; i < nodes.size(); i++){
    //very simple if the name matches exatly
    // as the nodes at Instance I.
    if(name == nodes[i].city.name){
        // if it is TRUE i store it into
        // the NEW VECTOR OF GOOD NAMES!
        lst.push_back(nodes[i]);
        return true;
    }      //that means the node is a PARTIAL MATCH!
           // since it is, we save it.
           //string::npos is an error
        if(nodes[i].city.name.find(name) != string::npos){
            //stores it into the vector if i do NOT recieve an error!
            lst.push_back(nodes[i]);
            }
        }
//returns FALSE because it is NOT a perfect match, very important when
// I cout my lst vector!
    return false;
}