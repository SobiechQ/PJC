//
// Created by mikol on 28.05.2023.
//

#include "File.h"

File::File(const string &fileLocation) : fileLocation(fileLocation) {}

const vector<VaultRecord> &File::getRecords() const {
    return records;
}

void File::setRecords(const vector<VaultRecord> &records) {
    File::records = records;
}

auto File::getLocation() -> string {
    return this->fileLocation;
}
