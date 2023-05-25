//
// Created by mikol on 18.05.2023.
//
#include <iostream>
#include <fmt/printf.h>
#include "myCrypt.cpp"
#include "vaultRecord.cpp"
#include "enum.h"
int main() {
    using namespace std;
    VaultRecord vaultRecord = VaultRecord("jan", "dzban", Category::IMPORTANT);
    fmt::print("{}", vaultRecord.toCsv());



    return 0;
}
