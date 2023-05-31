//
// Created by mikol on 18.05.2023.
//
#include <iostream>
#include <fmt/printf.h>
#include "cipher/myCrypt.cpp"
#include "filesManager/FilesManager.h"
#include "filesManager/File.h"
#include<dos.h>   //for delay()
#include<conio.h>   //for getch()
#include <thread>
#include "category/CategoryManager.h"

int main() {
    using namespace std;




//    auto records = vector<VaultRecord>();
//    VaultRecord record0 = VaultRecord("0", "a", "normal");
//    record0.setLogin("lorem");
//    record0.setWebAddress("ipsum");
//    records.push_back(record0);
//    records.push_back(VaultRecord("1", "b", "normal"));
//    records.push_back(VaultRecord("2", "c", "normal"));
//    records.push_back(VaultRecord("3", "d", "normal"));
//    records.push_back(VaultRecord("4", "e", "normal"));
//    records[2].setLogin("login");
//    records[2].setWebAddress("web address");
//    records[3].setLogin("efgh");
//    FilesManager::getInstance()
//        ->createFile("C:\\Users\\mikol\\Documents\\PJC\\Projekt\\passwd\\test1")
//        ->setCurrentFile("C:\\Users\\mikol\\Documents\\PJC\\Projekt\\passwd\\test1");
//        ->getCurrentFile()
//        ->value()
//        .setRecords(records);

    for(auto &a: *CategoryManager::getInstance()
            ->read()
            ->getCategories()){
        fmt::print("{}", a);
    }

    return 0;
}
