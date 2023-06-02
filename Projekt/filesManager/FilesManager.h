//
// Created by mikol on 28.05.2023.
//
/**
 * @file FilesManager.h
 * Definition of the FilesManager class.
 */
#include <fstream>
#include "File.h"
#include <optional>
#include <filesystem>
#include <tr1/functional>

#ifndef PJC2_FILESMANAGER_H
#define PJC2_FILESMANAGER_H


using namespace std;

/**
 * @class FilesManager
 * Manages file operations and File objects.
 */
class FilesManager {
private:
    static FilesManager *instance;
    optional<File *> *currentFile = new std::optional<File *>();

    FilesManager() {}

public:
    /**
     * Retrieves the singleton instance of FilesManager.
     * @return Pointer to the FilesManager instance.
     */
    static auto getInstance() -> FilesManager * {
        if (FilesManager::instance == nullptr)
            FilesManager::instance = new FilesManager();
        return FilesManager::instance;
    }

    /**
     * Checks if a file is currently set.
     * @return True if a file is set, false otherwise.
     */
    auto isFileSet() -> bool { return currentFile->has_value(); }

    /**
     * Creates a new file at the specified location.
     * @param fileLocation The location where the file should be created.
     * @return Pointer to the FilesManager instance.
     * @throw std::ios_base::failure if the file already exists or fails to save.
     */
    auto createFile(string fileLocation) -> FilesManager *;

    /**
     * Sets the current file using the specified file location.
     * @param fileLocation The location of the file to set as current.
     * @return Pointer to the FilesManager instance.
     * @throw std::ios_base::failure if the file does not exist.
     */
    auto setCurrentFile(string fileLocation) -> FilesManager *;

    /**
     *  Sets the current file using the provided File object.
     * @param file Pointer to the File object to set as current.
     * @return Pointer to the FilesManager instance.
     * @throw std::ios_base::failure if the file does not exist.
     */
    auto setCurrentFile(File *file) -> FilesManager *;

    /**
     *  Saves the current file.
     * @return Pointer to the FilesManager instance.
     * @throw std::logic_error if no file is chosen.
     */

    auto save() -> FilesManager *;

    /**
    *  Saves the current file with encryption using the specified key.
    * @param key The encryption key.
    * @return Pointer to the FilesManager instance.
    * @throw std::logic_error if no file is chosen.
    */

    auto save(const string &key) -> FilesManager *;

    /**
     *  Saves the current file with encryption using the specified key and encryption algorithm.
     * @param key The encryption key.
     * @param algorithm The encryption algorithm to use.
     * @return Pointer to the FilesManager instance.
     * @throw std::logic_error if no file is chosen.
     */

    auto save(const string &key, std::function<std::string(std::string v, std::string k)> algorithm) -> FilesManager *;

    /**
    *  Generates a random password.
    * @param count The length of the password.
    * @param generateUpperAndLower Whether to include uppercase and lowercase letters in the password.
    * @param generateAlphanumericalChars Whether to include special characters in the password.
    * @return The generated password.
    */

    auto generatePass(int count, bool generateUpperAndLower, bool generateAlphanumericalChars) -> string;

    /**
    *  Closes the current file.
    * @return Pointer to the FilesManager instance.
    */
    auto close() -> FilesManager *;

    /**
        *  Splits a message using the specified regular expression.
        * @param message The message to split.
        * @param reg The regular expression to use for splitting.
        * @return A vector of substrings.
        */
    static auto split(const string &message, const string &reg) -> vector<string>;

    /**
        *  Reads the contents of the current file.
        * @return Pointer to the File object representing the current file.
        * @throw std::logic_error if no file is chosen.
        */
    auto read() -> File *;

    /**
       *  Reads the contents of the specified file using the provided key for decryption.
       * @param key The decryption key.
       * @return Pointer to the File object representing the specified file.
       */
    auto read(const string &key) -> File *;

/**
     *  Reads the contents of the specified file using the provided key and decryption algorithm.
     * @param key The decryption key.
     * @param algorithm The decryption algorithm to use.
     * @return Pointer to the File object representing the specified file.
     */
    auto read(const string &key, std::function<std::string(std::string v, std::string k)> algorithm) -> File *;

    auto getCurrentFile() -> optional<File *> * {
        return this->currentFile;
    }

private:
    /**
    *  Checks if a file already exists at the specified location.
    * @param filePath The path to the file.
    * @return True if the file exists, false otherwise.
    */
    auto isFileAlreadyExisting(const std::string &filePath) -> bool {
        std::filesystem::path path(filePath);
        return std::filesystem::exists(path) && std::filesystem::is_regular_file(path);
    }

/**
     *  Writes records to the current file.
     * @param records The records to write.
     */
    auto writeToFile(std::vector<VaultRecord> records) -> void {
        string message = string(this->getCurrentDateTime());
        message += "\r\n";
        for (auto &r: records)
            message += r.toCsv();
        this->writeToFile(message);
    }

    /**
     *  Writes a message to the current file.
     * @param message The message to write.
     */
    auto writeToFile(const string &message) -> void {
        if (!this->isFileSet())
            throw logic_error("unable to write. File is not set.");
        std::ofstream fileStream(this->currentFile->value()->getLocation());
        if (!fileStream)
            throw std::ios_base::failure("Failed to open the file for writing.");
        fileStream << message;
        fileStream.close();
    }

    /**
       *  Retrieves the current date and time.
       * @return The current date and time as a string.
       */
    std::string getCurrentDateTime() {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&currentTime), "%d-%m-%Y %H:%M:%S");
        std::string dateTimeStr = ss.str();
        return dateTimeStr;
    }


public:
    ~FilesManager();
};

#endif //PJC2_FILESMANAGER_H