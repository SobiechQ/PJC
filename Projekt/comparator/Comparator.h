//
// Created by mikol on 31.05.2023.
//

/**
*@file Comparator.h
*Definition file for the Comparator class.
*This file contains the declarations of the Comparator class and its methods for comparing VaultRecord objects.
*/
#ifndef PJC2_COMPARATOR_H
#define PJC2_COMPARATOR_H


#include <string>
#include <optional>
#include "../records/VaultRecord.h"


using namespace std;
/**
*@class Comparator
*Compares VaultRecord objects based on specified criteria.
*The Comparator class provides methods for comparing VaultRecord objects based on primary and secondary criteria.
*/
class Comparator {
private:
    string primaryComparingBy;
    optional<string> secondaryComparingBy = optional<string>();
public:
    /**
    * Compares two VaultRecord objects based on the primary and secondary criteria.
    * @param v1 The first VaultRecord object to compare.
    * @param v2 The second VaultRecord object to compare.
    * @return True if v1 is considered smaller than v2 based on the criteria, false otherwise.
    */
    auto compare(VaultRecord v1, VaultRecord v2) -> bool ;
    /**
     * Compares two VaultRecord objects based on the secondary criteria.
     * @param v1 The first VaultRecord object to compare.
     * @param v2 The second VaultRecord object to compare.
     * @return True if v1 is considered smaller than v2 based on the secondary criteria, false otherwise.
     */
    auto compareSecondary(VaultRecord v1, VaultRecord v2) -> bool;
    /**
     * Sets the secondary criteria for comparison.
     * @param secondary The secondary criteria to set.
     */
    auto setSecondary(string& secondary) -> void;
    /**
     * Constructs a Comparator object with the specified primary criteria.
     * @param primaryComparingBy The primary criteria for comparison.
     */
   Comparator(const string &primaryComparingBy);
};


#endif //PJC2_COMPARATOR_H
