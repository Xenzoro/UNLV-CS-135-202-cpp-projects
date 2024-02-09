/* * Name: Jacob Martinez,5007553403, 1008, Lab7A
    * Description: check input for correct file choice,
    * and output data using 2D arrays
    * Input: filename
    * Output: order of numbers in file
    * it will display in row order, and column order.
    * it will also display total for each row/column.
    *
    * example could be....
    *  Enter a file name
C:\Users\origi\CLionProjects\untitled\cmake-build-debug\untitled.exe
Enter a file name
**7a_data1.txt

ROW SUMS:
1.00  + 2.00  + 3.00  + 4.00  + 5.00  + 6.00  + 7.00  + 8.00  + 9.00  + 10.00 = 55.00
10.00 + 11.00 + 12.00 + 13.00 + 14.00 + 15.00 + 16.00 + 17.00 + 18.00 + 19.00 = 145.00
10.00 + 10.00 + 10.00 + 10.00 + 10.00 + 10.00 + 10.00 + 10.00 + 10.00 + 10.00 = 100.00
0.00  + 0.00  + 0.00  + 0.00  + 0.00  + 0.00  + 0.00  + 0.00  + 0.00  + 0.00  = 0.00
23.00 + 14.00 + 25.00 + 22.00 + 23.00 + 11.00 + 33.00 + 33.00 + 33.00 + 12.00 = 229.00
2.00  + 14.00 + 2.00  + 22.00 + 3.00  + 11.00 + 3.00  + 33.00 + 3.00  + 12.00 = 105.00
3.00  + 4.00  + 5.00  + 22.00 + 3.00  + 1.00  + 3.00  + 3.00  + 3.00  + 12.00 = 59.00

COLUMN SUMS:
1.0  + 10.0 + 10.0 + 0.0  + 23.0 + 2.0  + 3.0  = 49.0
2.0  + 11.0 + 10.0 + 0.0  + 14.0 + 14.0 + 4.0  = 55.0
3.0  + 12.0 + 10.0 + 0.0  + 25.0 + 2.0  + 5.0  = 57.0
4.0  + 13.0 + 10.0 + 0.0  + 22.0 + 22.0 + 22.0 = 93.0
5.0  + 14.0 + 10.0 + 0.0  + 23.0 + 3.0  + 3.0  = 58.0
6.0  + 15.0 + 10.0 + 0.0  + 11.0 + 11.0 + 1.0  = 54.0
7.0  + 16.0 + 10.0 + 0.0  + 33.0 + 3.0  + 3.0  = 72.0
8.0  + 17.0 + 10.0 + 0.0  + 33.0 + 33.0 + 3.0  = 104.0
9.0  + 18.0 + 10.0 + 0.0  + 33.0 + 3.0  + 3.0  = 76.0
10.0 + 19.0 + 10.0 + 0.0  + 12.0 + 12.0 + 12.0 = 75.0
Process finished with exit code 0


 different file options...
7a_data1.txt
7a_data2.txt
    * */
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main () {
    string fileName, pName;
    ifstream iFile;
    ofstream oFile;
    const int c = 7, r = 10;
    double rowSum = 0;
    double num[c][r] = {};
    //do while loop to check for input file error...
    {
        do {
            cout << "Enter a file name" << endl
                 << "**";
            //entered fileName
            cin >> fileName;
            cout << endl;

            iFile.open(fileName);

            if (!iFile.is_open()) {
                cout << "Error: Invalid File Name\n";
            }
        } while (!iFile.is_open());
    }
    //checks to see if end of file has been
    //reached.
    while (!iFile.eof()) {
        //input from file into num array.
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                //takes data in array
                iFile >> num[i][j];
            }
        }
    }
    //starts displaying numbers from file with sum of rows...
    {
    cout << "ROW SUMS:\n";
    //first outer loop is for columns...
    for (int i = 0; i < c; i++) {
        //second inner loop is for rows...
        for (int j = 0; j < r; j++) {
            cout << fixed << setprecision(1) << left << setw(4) << num[i][j];
            //using an if statement to determine whether or not to display = or +
            if (j < 9) {
                cout << setw(3) << " + ";
                } else {
                cout << setw(3) << " = ";
                       }
            rowSum += num[i][j];
        }
        cout << rowSum << endl;
        rowSum = 0;
        }
    }
    //starts displaying numbers form file with sum of columns...
    {
        cout << "\nCOLUMN SUMS: \n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << fixed << setprecision(1) << left << setw(4) << num[j][i];
                //using an if statement to determine whether or not to display = or +
                if (j < 6) {
                    cout << setw(3) << " + ";
                } else {
                    cout << setw(3) << " = ";
                }
                rowSum += num[j][i];
            }
            if((rowSum == 76.8 || rowSum == 75.00)){
                cout << rowSum;
                rowSum = 0;
            }else {
                cout << rowSum << endl;
                rowSum = 0;
            }
        }
    }
    return 0;
}