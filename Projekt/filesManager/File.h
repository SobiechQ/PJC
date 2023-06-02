//
// Created by mikol on 28.05.2023.
//
/**
*@file File.h
*Definition file for the File class.
*This file contains the declarations of the File class and its methods for handling files and records.
*/
#ifndef PJC2_FILE_H
#define PJC2_FILE_H


#include <string>
#include <vector>
#include "../records/VaultRecord.h"

using namespace std;
/**
*@class File
*Represents a file and its associated records.
*The File class provides methods for managing file operations and accessing records stored in the file.
*/
class File {
private:
    const string fileLocation;
    vector<VaultRecord>* records;
public:
    /**
    * Constructs a File object with the specified file location.
    * @param fileLocation The location of the file.
    */
    File(const string &fileLocation);
    /**
     * Retrieves the file location.
     * @return The file location as a string.
     */
    auto getLocation() -> string;
    /**
     * Retrieves the vector of records associated with the file.
     * @return A pointer to the vector of VaultRecord objects.
     */
    vector<VaultRecord>* getRecords();
    /**
     * Sets the records associated with the file.
     * @param records The vector of VaultRecord objects to set.
     * @return A pointer to the modified File object.
     */
    auto setRecords(vector<VaultRecord>* records) -> File*;
    ~File();
};


#endif //PJC2_FILE_H
