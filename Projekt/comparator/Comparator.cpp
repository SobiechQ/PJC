//
// Created by mikol on 31.05.2023.
//

#include "Comparator.h"


Comparator::Comparator(const string &primaryComparingBy) : primaryComparingBy(primaryComparingBy) {

}

auto Comparator::compare(VaultRecord v1, VaultRecord v2) -> bool {
    if (this->primaryComparingBy == "name")
        if(v1.getName()!=v2.getName())
            return v1.getName().compare(v2.getName());
    if (this->primaryComparingBy == "password")
        if (v1.getPassword() != v2.getPassword())
            return v1.getPassword().compare(v2.getPassword());
    if (this->primaryComparingBy == "category")
        if (v1.getCategory() != v2.getCategory())
            return v1.getCategory().compare(v2.getCategory());

    if (this->primaryComparingBy == "login") {
        //both have value
        if(v1.getLogin().has_value() && v2.getLogin().has_value())
            return v1.getLogin().value().compare(v2.getLogin().value());
        //only v1 has value
        if(v1.getLogin().has_value() && !v2.getLogin().has_value())
            return true; // those that have value go higher
        if (!v1.getLogin().has_value() && v2.getLogin().has_value())
            return false; //if no value, put at the end of sort
        //if both dont have value, sort by secondary option
    }
    
    if (this->primaryComparingBy == "webAddress") {
        //both have value
        if(v1.getWebAddress().has_value() && v2.getWebAddress().has_value())
            return v1.getWebAddress().value().compare(v2.getWebAddress().value());
        //only v1 has value
        if(v1.getWebAddress().has_value() && !v2.getWebAddress().has_value())
            return true; // those that have value go higher
        if (!v1.getWebAddress().has_value() && v2.getWebAddress().has_value())
            return false; //if no value, put at the end of sort
        //if both dont have value, sort by secondary option
    }
    if (this->secondaryComparingBy.has_value())
        return compareSecondary(v1, v2);
    return false;
}

auto Comparator::setSecondary(string &secondary) -> void {
    this->secondaryComparingBy = secondary;
}

auto Comparator::compareSecondary(VaultRecord v1, VaultRecord v2) -> bool {
    if (!this->secondaryComparingBy.has_value())
        throw std::logic_error("Cant compare by sencodary value, if it was not set");

    if (this->secondaryComparingBy.value() == "name")
        if(v1.getName()!=v2.getName())
            return v1.getName().compare(v2.getName());
    if (this->secondaryComparingBy.value() == "password")
        if (v1.getPassword() != v2.getPassword())
            return v1.getPassword().compare(v2.getPassword());
    if (this->secondaryComparingBy.value() == "category")
        if (v1.getCategory() != v2.getCategory())
            return v1.getCategory().compare(v2.getCategory());

    if (this->secondaryComparingBy.value() == "login") {
        //both have value
        if(v1.getLogin().has_value() && v2.getLogin().has_value())
            return v1.getLogin().value().compare(v2.getLogin().value());
        //only v1 has value
        if(v1.getLogin().has_value() && !v2.getLogin().has_value())
            return true; // those that have value go higher
        if (!v1.getLogin().has_value() && v2.getLogin().has_value())
            return false; //if no value, put at the end of sort
    }

    if (this->secondaryComparingBy.value() == "webAddress") {
        //both have value
        if(v1.getWebAddress().has_value() && v2.getWebAddress().has_value())
            return v1.getWebAddress().value().compare(v2.getWebAddress().value());
        //only v1 has value
        if(v1.getWebAddress().has_value() && !v2.getWebAddress().has_value())
            return true; // those that have value go higher
        if (!v1.getWebAddress().has_value() && v2.getWebAddress().has_value())
            return false; //if no value, put at the end of sort
        //if both dont have value, sort by secondary option
    }
    return false;
}
