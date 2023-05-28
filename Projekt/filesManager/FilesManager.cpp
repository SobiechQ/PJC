//
// Created by mikol on 28.05.2023.
//

#include <string>
#include <optional>
#include "FilesManager.h"
#include "fmt/printf.h"

using namespace std;
FilesManager* FilesManager::instance = nullptr;

auto FilesManager::createFile(string fileLocation) -> optional<File> * {
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
    return &this->currentFile;
}

auto FilesManager::setCurrentFile(const string &fileLocation) -> void {
    File file = File(fileLocation);
    try {
        this->setCurrentFile(file);
    } catch (const std::ios_base::failure& ex) {
        throw ex;
    }
}

auto FilesManager::setCurrentFile(File file) -> void {
    if (!this->isFileAlreadyExisting(file.getLocation()))
        throw ios_base::failure("No such file");
    this->currentFile.emplace(file);
}

auto FilesManager::save() -> void {
    if (!this->isFileSet())
        throw new logic_error("Cant save if file isnt chosen");
    this->writeToFile(this->getCurrentFile()->value().getRecords());
}

auto FilesManager::close() -> void {
    this->getCurrentFile()->reset();
}

auto FilesManager::flush() -> void {
    this->save();
    this->close();
}



