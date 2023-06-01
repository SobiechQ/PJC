//
// Created by mikol on 28.05.2023.
//

#include "File.h"

File::File(const string &fileLocation) : fileLocation(fileLocation) {
    this->records = new vector<VaultRecord>();
}


auto File::setRecords(vector<VaultRecord>* records) -> File* {
    this->records = records;
    return this;
}

auto File::getLocation() -> string {
    return this->fileLocation;
}

vector<VaultRecord> *File::getRecords() {
    return this->records;
}

File::~File() {
    delete this->records;
}
