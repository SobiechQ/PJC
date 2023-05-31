//
// Created by mikol on 28.05.2023.
//

#include <string>
#include <optional>
#include <regex>
#include "FilesManager.h"
#include "fmt/printf.h"
#include "C:\Users\mikol\Documents\PJC\Projekt\cipher\myCrypt.h"

using namespace std;
FilesManager *FilesManager::instance = nullptr;

auto FilesManager::createFile(string fileLocation) -> FilesManager * {
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

auto FilesManager::setCurrentFile(string fileLocation) -> FilesManager * {
    fileLocation += ".pass";
    File file = File(fileLocation);
    try {
        this->setCurrentFile(file);
    } catch (const std::ios_base::failure &ex) {
        throw ex;
    }
    return this;
}

auto FilesManager::setCurrentFile(File file) -> FilesManager * {
    if (!this->isFileAlreadyExisting(file.getLocation()))
        throw ios_base::failure("No such file");
    this->currentFile.emplace(file);
    return this;
}

auto FilesManager::save() -> FilesManager * {
    if (!this->isFileSet())
        throw new logic_error("Cant save if file isnt chosen");
    this->writeToFile(*this->getCurrentFile()->value().getRecords());
    return this;
}

auto FilesManager::save(const string &key) -> FilesManager * {
    if (!this->isFileSet())
        throw new logic_error("Cant save if file isnt chosen");
    auto encryptedCopy = File(this->getCurrentFile()->value().getLocation());
    for (auto unEncryptedRecord: *this->getCurrentFile()->value().getRecords()) {
        auto encryptedRecord = VaultRecord(myEncrypt(unEncryptedRecord.getName(), key),
                                           myEncrypt(unEncryptedRecord.getPassword(), key),
                                           myEncrypt(unEncryptedRecord.getCategory(), key)
        );

        if (unEncryptedRecord.getLogin().has_value())
            encryptedRecord.setLogin(myEncrypt(unEncryptedRecord.getLogin().value(), key));
        if (unEncryptedRecord.getWebAddress().has_value())
            encryptedRecord.setWebAddress(myEncrypt(unEncryptedRecord.getWebAddress().value(), key));

        encryptedCopy.getRecords()
                ->push_back(encryptedRecord);
    }

    this->writeToFile(*encryptedCopy.getRecords());
    return this;
}

auto FilesManager::close() -> FilesManager * {
    this->getCurrentFile()->reset();
    return this;
}

auto FilesManager::flush() -> FilesManager * {
    this->save();
    this->close();
    return this;
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
    for (auto &record: records) {
        auto commaSeparatedValues = split(record, ",");
        if (commaSeparatedValues.size() != 5)
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

auto FilesManager::read(const string &key) -> File {
    if (!this->isFileSet())
        throw logic_error("Set file before reading from file");

    auto encryptedFile = this->read();
    auto decryptedFile = File(this->getCurrentFile()->value().getLocation());
    for(auto &encryptedRecord: *encryptedFile.getRecords()){
        auto decryptedRecord = VaultRecord(myDecrypt(encryptedRecord.getName(), key),
                                           myDecrypt(encryptedRecord.getPassword(), key),
                                           myDecrypt(encryptedRecord.getCategory(), key));
        if(encryptedRecord.getLogin().has_value())
            decryptedRecord.setLogin(myDecrypt(encryptedRecord.getLogin().value(), key));
        if(encryptedRecord.getWebAddress().has_value())
            decryptedRecord.setWebAddress(myDecrypt(encryptedRecord.getWebAddress().value(), key));
        decryptedFile.getRecords()->push_back(decryptedRecord);
    }
    this->setCurrentFile(decryptedFile);
    return decryptedFile;
}

auto FilesManager::split(const string &message, const string &reg) -> vector<string> {
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





