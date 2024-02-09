/* * Name: Jacob Martinez,5007553403, 1008, Lab6A
    * Description: check input for correct file choice,
    * and output data using arrays
    * Input: filename
    * Output: order of numbers in file
    * if for whatever reason there is
    * a character other than a number it will output
    * "Error: Invalid input in file." and read on.
    * it will display in normal order, backwards order,
    * min val, max val, sum and the average of all.
    *
    * example could be....
    *  Enter a file name

 INPUT VALUES...
 6b_data1.txt
 6b_data2.txt
 INPUT VALUES...

Enter a file name
**error

Error: invalid file name.
Enter a file name
**error.txt

Error: invalid file name.
Enter a file name
**6b_data1.tx

Error: invalid file name.
Enter a file name
**6b_data1.txt

Enter a name to search
**error
Names Forwards: alex, john, jane, alex, alex, jane, john, ted
Scores Forwards: 84, 97, 99, 91, 95, 100, 98, 55
Names Reverse: ted, john, jane, alex, alex, jane, john, alex
Scores Reverse: 55, 98, 100, 95, 91, 99, 97, 84
Error: error is not a student in the list
Process finished with exit code 0

    * */
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main () {
    string fileName,pName;
    ifstream iFile;
    ofstream oFile;
    int count = 0 ,foundN = 0;
    double total = 0,foundT = 0,average = 0;
    const int size =  100;
    string arr[size];
    double arrNum[size];
    double max = 1, min = 1000;

    do {
        cout << "Enter a file name" << endl
                << "**";
        //entered fileName
        cin >> fileName;
        cout << endl;

        iFile.open(fileName);

        if(!iFile.is_open()){
            cout << "Error: invalid file name.\n";
        }

    }while(!iFile.is_open());
    //end of do while loop
    //start of new while loop that checks if file has ended
    cout << "Enter a name to search"<< endl << "**";
    cin >> pName;
    //keeps running unless its at the end of the file
    while (!iFile.eof()){
        //takes data in array
        iFile >> arr[count] >> arrNum[count];
        if(!iFile) {
            if (!iFile.eof()) {
                iFile.clear();
                iFile.ignore(100, '\n');
                cout << "Error: Invalid input in file.\n";
            }
            continue;
        }
        count++;
    }

    for (int i=0; i < count; i++){
        if(arr[i] ==pName){
            foundN = 1;
            ++foundT;
            total += arrNum[i];

            if (arrNum[i] > max) {
                max = arrNum[i];
            }
            if (arrNum[i] < min) {
                min = arrNum[i];
            }
        }

    }
    //closes input file file
    iFile.close();
    //simply displaying output normally i.e. forwards
    {
        cout << "\nNames Forward: ";
        for (int i = 0; i < count; i++) {

            cout  << arr[i];
            if (i <= count - 2) {
                cout << ", ";
            }
        }
        cout << endl << "Scores Forward: ";
        for (int i = 0; i < count; i++) {

            cout << arrNum[i];
            if (i <= count - 2) {
                cout << ", ";
            }
        }
    }
    //displaying the output in reverse.
    {
        cout << endl << "Names Reverse: ";
        for (int i = count - 1; i >= 0; i--) {
            cout << arr[i];

            if (i <= count && i != 0) {
                cout << ", ";
            }
            //since arr[] can only be 100, if it goes through all the loops
        }
        cout << endl << "Scores Reverse: ";
        for (int i = count - 1; i >= 0; i--) {
            cout << arrNum[i];

            if (i <= count && i != 0) {
                cout << ", ";
            }
            //since arr[] can only be 100, if it goes through all the loops
        }
    }
    if(foundN==1){
        cout << endl << foundT << " results for " << pName << endl;
        //using a for loop to determine min and max values for output
        cout << fixed << setprecision(2) << "Minimum: " << min << endl;
        cout << "Maximum: " << max << endl;
        //using a for loop to find the sum of all elements of arr[]
        cout << fixed << setprecision(2) << "Sum:     " << total << endl;
        // taking the sum from previous output and
        // taking average with it using count
        cout << fixed << setprecision(2) << "Average: ";
        average = total / foundT;
        cout << average;
    }else {
        cout << "\nError: " << pName <<" is not a student in the list";
    }
    return 0;
}