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
#include "comparator/Comparator.h"
#include "interface/interface.h"

int main() {
    using namespace std;
    Interface().run();
    return 0;
}
