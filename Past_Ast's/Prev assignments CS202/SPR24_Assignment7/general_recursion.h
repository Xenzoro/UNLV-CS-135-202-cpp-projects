/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_7
    * Description: Recursion is a powerful tool for problem solving.
    * While not always the most efficient, it allows us to reason
    * through problems that might otherwise be difficult to solve.
    * This assignment differs slightly from the others
    * in that it is not a cohesive program so much as a set
    * of problems. You will be asked to solve several problems
    * recursively
    * Input: number
    * Output: the selected function.
*/

#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include <string>

using namespace std;

//This file contains several functions that solve generic recursive problems. 
//TODO: Please finish each and test them using the provided main

/* TODO: Finish the function and replace this description */
int findSum(int num)
{
	//Find the sum of all non-negative integers up to the given num.
	//Which number(s) are trivial to sum up to? Remember to have a base case, recursive case, and reduction operation

    //base case
    if(num==0)
    {
        return 0;
    }//else //delete else?
    {
    //recursive case
    return num + findSum(num-1);
    }
}

/* TODO: Finish the function and replace this description */
int intLog(const int& base, int num)
{
	/*Find the integer log with the given base.
	Ex: log2(16) = 4 where the base is 2, num is 16, and result is 4. i.e. How many times does 2 go into 16?
	Consider what number is trivial to take the log of regardless of base and what value it is. In other words,
	What number can all bases go into the same number of times? Then recurse. */

        //base case
        if(num<base)
        {
            return 0;
        }//else //delete
        {
        //recursive case
        return 1 + intLog(base, num/base);
        }
}

/* TODO: Finish the function and replace this description */
void printReverse(string str, int length)
{
	//This should print the string, str, of the given length backwards to standard out

    //base case
    if(length==0)
    {
        return;
    }//else //delete
    {
    //recursive case
    cout << str.substr(length - 1, 1);
    printReverse(str.substr(0, length - 1),length - 1);
    }
}

/* TODO: Finish the function and replace this description */
bool isValueInArray(int* arr, int start, int length, const int value) {
    //These variables are provided for your convenience, but feel free to make your own.
    //You can write code above or below these
    int leftLength = length / 2; //Length of the left array
    int rightLength = length - leftLength -
                      1; //Length of the right subarray (excluding middle with - 1)
    int middle = start + length /
                         2; //Index of the middle element in the array

    /*This function should perform a binary search using the given value on the given array with first index given by start and the given length.
    It returns true if the value is found within the array and false if it is not. You can assume the array is pre-sorted in non-descending order.
    Recall that a binary search should check if the middle value in the array is the one being searched for. If it isn't, try the left
    array if the value is less than than the middle and the right array if it is greater than the middle. Consider what the length and
    starting index of each subarray is when recursively calling as well as any base cases.
    Index and length calculations are provided for your convenience above.
    */

    //base case 01
    // if length is 0 then its not in the array.

    if (length == 0)
    {
        return false;
    }
    //base case 02
    // if middle element is same as value then return true

    if (arr[middle] == value)
    {
        return true;
    }//else
     if(arr[middle] > value)
    {
        //recursive case 01
        // if index at middle is greater than value then search in left array
        // because it is in the left array

        return isValueInArray(arr, start, leftLength, value);
    }

        //recursive case 02
        // if index at middle is less than value then search in right array
        // because it is in the right array

        return isValueInArray(arr, middle + 1, rightLength, value);

}
#endif
