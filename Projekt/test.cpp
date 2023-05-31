//
// Created by mikol on 18.05.2023.
//
#include <iostream>
#include <fmt/printf.h>
#include "cipher/myCrypt.cpp"
#include "filesManager/FilesManager.h"
#include "filesManager/File.h"
#include "cipher/myCrypt.h"
#include "category/CategoryManager.h"

int main() {
    using namespace std;
    auto records = vector<VaultRecord>();
    records.push_back(VaultRecord("a", "pomidor", "wazne"));
    records.push_back(VaultRecord("b", "rosol", "wazne"));
    records.push_back(VaultRecord("c", "zurek", "nie wazne"));
    records.push_back(VaultRecord("d", "zurek", "nie wazne"));
    records[1].setLogin("z kury");

//    FilesManager::getInstance()
//            ->createFile("C:\\Users\\mikol\\Documents\\PJC\\Projekt\\passwd\\test2")
//            ->getCurrentFile()
//            ->value()
//            .setRecords(records);
//    FilesManager::getInstance()
//        ->save("warzywa");
    FilesManager::getInstance()
            ->setCurrentFile("C:\\Users\\mikol\\Documents\\PJC\\Projekt\\passwd\\test2")
            ->getCurrentFile()
            ->value()
            ->setRecords(&records);
    FilesManager::getInstance()
            ->save();
//            ->close();

//    for (auto &s: *FilesManager::getInstance()
//            ->getCurrentFile()
//            ->value()
//            ->getRecords()) {
//        cout << s.toString() << '\n';
//    }
    delete FilesManager::getInstance();
    return 0;
}
