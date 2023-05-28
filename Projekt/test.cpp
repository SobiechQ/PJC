//
// Created by mikol on 18.05.2023.
//
#include <iostream>
#include <fmt/printf.h>
#include "myCrypt.cpp"
#include "filesManager/FilesManager.h"
int main() {
    using namespace std;
    auto records = vector<VaultRecord>();
    records.push_back(VaultRecord("name1", "pass1", "normal"));
    records.push_back(VaultRecord("name2", "pass2", "normal"));
    records.push_back(VaultRecord("name3", "pass3", "normal"));
    records.push_back(VaultRecord("name4", "pass4", "normal"));
    records.push_back(VaultRecord("name5", "pass5", "normal"));

    try {
        FilesManager::getInstance()->createFile("C:\\Users\\mikol\\Documents\\PJC\\Projekt\\passwd\\test1");
    } catch (const std::ios_base::failure& ex) {
        std::cerr << "Exception caught: " << ex.what() << '\n';
    }
    fmt::print("{}", FilesManager::getInstance()->isFileSet());
    FilesManager::getInstance()->setCurrentFile("C:\\Users\\mikol\\Documents\\PJC\\Projekt\\passwd\\test1.pass");
    fmt::print("{}", FilesManager::getInstance()->isFileSet());
    FilesManager::getInstance()
        ->getCurrentFile()
        ->value()
        .setRecords(records);
    FilesManager::getInstance()
        ->flush();




    return 0;
}
