//
// Created by mikol on 28.05.2023.
//

#include <fstream>
#include "File.h"
#include <optional>
#include <filesystem>

#ifndef PJC2_FILESMANAGER_H
#define PJC2_FILESMANAGER_H

#endif //PJC2_FILESMANAGER_H

using namespace std;

/**
 * Singleton class used to file i/o operation and manipulation.
 * Allowes for manipulation on loaded file set in currentFile variable.
 * @see FilesManager::isFileSet() to check if file is loaded.
 */
class FilesManager {
private:
    static FilesManager *instance;
    optional<File> currentFile;

    FilesManager() {}

public:
    static auto getInstance() -> FilesManager * {
        if (FilesManager::instance == nullptr)
            FilesManager::instance = new FilesManager();
        return FilesManager::instance;
    }

    auto isFileSet() -> bool { return currentFile.has_value(); }

    /**
     * Creates new .pass file on drive, and sets the optional<File> currentFile as that file.
     * @param fileLocation Location and name (without .pass) of file to be created
     * @throws ios_base::failure, when unable to create file on that location. In such case optional
     * current file wont change.
     * @return Instancce of currentFile
     */
    auto createFile(string fileLocation) -> optional<File> * {
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
            this->writeToFile("tes2222");
        } catch (std::logic_error ex){
            //technically this should never happen since we just set the pointer
            //tho its here just in case.
            throw ios_base::failure(ex.what());
        }


        fileStream.close();
        return &this->currentFile;
    }

    auto getCurrentFile() -> optional<File> * {
        return &this->currentFile;
    }

private:
    auto isFileAlreadyExisting(const std::string &filePath) -> bool {
        std::filesystem::path path(filePath);
        return std::filesystem::exists(path) && std::filesystem::is_regular_file(path);
    }

    auto writeToFile(const string &message) -> void {
        if (!this->isFileSet())
            throw logic_error("unable to write. File is not set.");
        std::ofstream fileStream(this->currentFile.value().getLocation());
        if (!fileStream)
            throw std::ios_base::failure("Failed to open the file for writing.");
        fileStream << message;
        fileStream.close();
    }


};

