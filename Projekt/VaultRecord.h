//
// Created by mikol on 28.05.2023.
//

#ifndef PJC2_VAULTRECORD_H
#define PJC2_VAULTRECORD_H

#endif //PJC2_VAULTRECORD_H
//
// Created by mikol on 25.05.2023.
//
//#include "enum.h"
#include <iostream>
#include <optional>
#include <vector>




using namespace std;

class VaultRecord {
private:
    string name;
    string password;
    string category;
    optional<std::string> webAddress;
    optional<std::string> login;
public:
    VaultRecord(const string &name, const string &password, const string &category) : name(name), password(password),
                                                                                      category(category) {}
    auto setWebAddress(const std::string &webAddress) -> void {
        this->webAddress.swap((optional<basic_string<char>> &) webAddress);
    }

    auto setLogin(const std::string &login) -> void {
        this->login.swap((optional<basic_string<char>> &) login);
    }

    auto toString() -> std::string {
        std::string output = "Name: " + this->name + "\n";
        output += "Password: " + this->password + "\n";
        output += "Category: " + this->category + "\n";
        output += '\n';
        if (this->webAddress.has_value())
            output += "Web Address: " + this->webAddress.value() + "\n";
        if (this->login.has_value())
            output += "Login: " + this->login.value() + "\n";
        return output;
    }

    auto toCsv() -> std::string {
        std::string output;
        output += this->name + ',';
        output += this->password + ',';
        output += this->category;
        output += ',';
        output += this->webAddress.value_or("NULL"); //todo protect so that web address cant be set as null.
        output += ',';
        output += this->login.value_or("NULL");
        output += "\r\n";
        return output;
    }

};


