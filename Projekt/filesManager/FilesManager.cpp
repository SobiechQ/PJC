//
// Created by mikol on 28.05.2023.
//

#include <string>
#include <optional>
#include <regex>
#include "FilesManager.h"
#include "fmt/printf.h"

using namespace std;
FilesManager* FilesManager::instance = nullptr;

auto FilesManager::createFile(string fileLocation) -> FilesManager* {
    fileLocation += ".pass";
    if (this->isFileAlreadyExisting(fileLocation))
        throw ios_base::failure("File already exists on that location");

    File *file = new File(fileLocation);
    ofstream fileStream(file->getLocation());

    if (!fileStream) {
        delete file;
        throw ios_base::failure("Sailed to save file");
    }

    //success in creating a file.
    this->currentFile.emplace(*file);

    try {
        this->writeToFile(this->getCurrentDateTime());
    } catch (std::logic_error ex) {
        //technically this should never happen since we just set the pointer
        //tho its here just in case.
        throw ios_base::failure(ex.what());
    }
    fileStream.close();
    return this;
}

auto FilesManager::setCurrentFile(string fileLocation) -> FilesManager* {
    fileLocation+=".pass";
    File file = File(fileLocation);
    try {
        this->setCurrentFile(file);
    } catch (const std::ios_base::failure& ex) {
        throw ex;
    }
    return this;
}

auto FilesManager::setCurrentFile(File file) -> FilesManager* {
    if (!this->isFileAlreadyExisting(file.getLocation()))
        throw ios_base::failure("No such file");
    this->currentFile.emplace(file);
    return this;
}

auto FilesManager::save() -> void {
    if (!this->isFileSet())
        throw new logic_error("Cant save if file isnt chosen");
    this->writeToFile(*this->getCurrentFile()->value().getRecords());
}

auto FilesManager::close() -> void {
    this->getCurrentFile()->reset();
}

auto FilesManager::flush() -> void {
    this->save();
    this->close();
}
auto split(const string& message, const string& reg) -> vector<string> {
    vector<string> elems;
    regex re(reg);
    sregex_token_iterator iter(message.begin(), message.end(), re, -1);
    sregex_token_iterator end;
    while (iter != end) {
        if (iter->length()) {
            elems.push_back(*iter);
        }
        ++iter;
    }
    return elems;
}

auto FilesManager::read() -> File {
    if (!this->isFileSet())
        throw logic_error("Set file before reading from file");
    ifstream file(this->getCurrentFile()->value().getLocation());
    if (!file)
        throw std::ios_base::failure("Failed to open the file for reading");

    string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    auto records = split(content, "\r\n");
    records.erase(records.begin());
    for(auto& record: records){
        auto commaSeparatedValues = split(record, ",");
        if (commaSeparatedValues.size()!=5)
            throw std::ios_base::failure("File is corrupted, unable to parse comtent");
        auto currentRecord = VaultRecord(
                commaSeparatedValues[0],
                commaSeparatedValues[1],
                commaSeparatedValues[2]);
        if (commaSeparatedValues[3] != "NULL")
            currentRecord.setLogin(commaSeparatedValues[3]);
        if (commaSeparatedValues[4] != "NULL")
            currentRecord.setWebAddress(commaSeparatedValues[4]);
        this->getCurrentFile()
            ->value()
            .getRecords()
            ->push_back(currentRecord);
    }
    return this->getCurrentFile()->value();

}



