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
#include <fmt/printf.h>




using namespace std;

class VaultRecord {
private:
    string name;
    string password;
    string category;
    optional<std::string> login;
    optional<std::string> webAddress;
public:
    VaultRecord(const string &name, const string &password, const string &category) : name(name), password(password),
                                                                                      category(category) {}
    auto setWebAddress(std::string webAddress) -> void {
        this->webAddress = webAddress;
    }

    auto setLogin(string login) -> void {
        this->login=login;
    }

    auto toString() -> std::string {
        std::string output = "Name: " + this->name + "\n";
        output += "Password: " + this->password + "\n";
        output += "Category: " + this->category + "\n";
        if (this->login.has_value())
            output += "Login: " + this->login.value() + "\n";
        if (this->webAddress.has_value())
            output += "Web Address: " + this->webAddress.value() + "\n";
        output+='\n';
        return output;
    }

    auto toCsv() -> std::string {
        std::string output;
        output += this->name + ',';
        output += this->password + ',';
        output += this->category;
        output += ',';
        output += this->login.value_or("NULL");
        output += ',';
        output += this->webAddress.value_or("NULL"); //todo protect so that web address cant be set as null.
        output += "\r\n";
        return output;
    }

    const string &getName() const {
        return name;
    }

    const string &getPassword() const {
        return password;
    }

    const string &getCategory() const {
        return category;
    }

    const optional<std::string> &getLogin() const {
        return login;
    }

    const optional<std::string> &getWebAddress() const {
        return webAddress;
    }

};


