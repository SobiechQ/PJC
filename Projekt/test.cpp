//
// Created by mikol on 18.05.2023.
//
#include <iostream>
#include <fmt/printf.h>
#include "myCrypt.cpp"
#include "filesManager/FilesManager.h"
int main() {
    using namespace std;
    /*VaultRecord vaultRecord = VaultRecord("jan", "dzban", "Important");
    vaultRecord.setLogin("abc");
    fmt::print("{}", vaultRecord.toCsv());*/
//    FilesManager::getInstance()->foo();
    try {
        FilesManager::getInstance()->createFile("C:\\Users\\mikol\\Documents\\PJC\\Projekt\\passwd\\test1");
    } catch (const std::ios_base::failure& ex) {
        std::cerr << "Exception caught: " << ex.what() << '\n';
    }
    fmt::print("{}",FilesManager::getInstance()->isFileSet());



    return 0;
}
