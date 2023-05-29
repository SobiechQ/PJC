//
// Created by mikol on 28.05.2023.
//

#include "File.h"

File::File(const string &fileLocation) : fileLocation(fileLocation) {}


auto File::setRecords(const vector<VaultRecord> &records) -> File* {
    File::records = records;
    return this;
}

auto File::getLocation() -> string {
    return this->fileLocation;
}

vector<VaultRecord> *File::getRecords() {
    return &this->records;
}
