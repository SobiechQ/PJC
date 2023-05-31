//
// Created by mikol on 28.05.2023.
//

#ifndef PJC2_FILE_H
#define PJC2_FILE_H


#include <string>
#include <vector>
#include "../records/VaultRecord.h"

using namespace std;
class File {
private:
    const string fileLocation;
    vector<VaultRecord>* records;
public:
    File(const string &fileLocation);
    auto getLocation() -> string;
    vector<VaultRecord>* getRecords();
    auto setRecords(vector<VaultRecord>* records) -> File*;

    virtual ~File();
};


#endif //PJC2_FILE_H