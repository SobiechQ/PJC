//
// Created by mikol on 30.05.2023.
//

#include <fstream>
#include <regex>
#include "CategoryManager.h"
#include "../filesManager/FilesManager.h"

CategoryManager *CategoryManager::instance = nullptr;
CategoryManager *CategoryManager::getInstance() {
    if (CategoryManager::instance == nullptr)
        CategoryManager::instance = new CategoryManager();
    return CategoryManager::instance;
}
CategoryManager *CategoryManager::read() {
    ifstream file("C:\\Users\\mikol\\Documents\\PJC\\Projekt\\category\\category");
    if (!file)
        throw std::ios_base::failure("Failed to open the file for reading");
    string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    auto records = FilesManager::split(content, "\r\n");
    this->categories = records;
    return this;
}

CategoryManager *CategoryManager::save() {
    auto message = string();
    for(auto& c:*this->getCategories() )
        message += c+"\r\n";
    std::ofstream fileStream("C:\\Users\\mikol\\Documents\\PJC\\Projekt\\category\\category");
    if (!fileStream)
        throw std::ios_base::failure("Failed to open the file for writing.");
    fileStream << message;
    fileStream.close();
}

vector<std::string> *CategoryManager::getCategories() {
    return &this->categories;
}


