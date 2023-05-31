//
// Created by mikol on 31.05.2023.
//

#ifndef PJC2_COMPARATOR_H
#define PJC2_COMPARATOR_H


#include <string>
#include <optional>
#include "../records/VaultRecord.h"


using namespace std;
class Comparator {
private:
    string primaryComparingBy;
    optional<string> secondaryComparingBy = optional<string>();
public:
    auto compare(VaultRecord v1, VaultRecord v2) -> bool ;
    auto compareSecondary(VaultRecord v1, VaultRecord v2) -> bool ;
    auto setSecondary(string& secondary) -> void;

    explicit Comparator(const string &primaryComparingBy);


};


#endif //PJC2_COMPARATOR_H
