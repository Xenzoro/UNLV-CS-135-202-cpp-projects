#ifndef CFILE_H
#define CFILE_H

#include<iostream>
#include<fstream>
#include "CFirm.h"
#include "CUser.h"
#include "COrder.h"
using namespace std;

/**
 * @class CFile
 * @brief Provides file-related operations for reading and writing firm data.
 *
 * The CFile class provides static member functions to perform file-related operations for reading and writing firm data.
 * These functions are designed to work with the CFirm class, allowing the reading and writing of firm information to/from files.
 */
class CFile
{
public:
    /**
     * @brief Write firm data to a file.
     *
     * This static member function writes the information of a CFirm object to a file specified by the fileName parameter.
     * The firm data, including the Users collection and portfolio value, is written to the file in a specific format.
     *
     * @param firm The CFirm object whose data is to be written to the file.
     * @param fileName The name of the file to which the firm data will be written.
     */
    static void WriteToFirmFile(const CFirm& firm, const std::string& fileName);

    /**
     * @brief Read and display firm data from a file.
     *
     * This static member function reads the firm data from a file specified by the fileName parameter and displays it.
     * The file is expected to contain firm information, including the Users collection and portfolio value, in a specific format.
     * After reading the data, the function displays the firm information on the standard output stream.
     *
     * @param fileName The name of the file from which the firm data will be read and displayed.
     */
    static void ReadAndDisplayFirmFile(const std::string& fileName);
};

#endif