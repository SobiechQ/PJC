//
// Created by mikol on 25.05.2023.
//
//#include "enum.h"
#include <iostream>
#include <optional>
#include "enum.h"

BETTER_ENUM(Category, int, LOGIN, MEMO, IMPORTANT, WORK)

using namespace std;

class VaultRecord {
private:
    string name;
    string password;
    Category category;
    optional<std::string> webAddress;
    optional<std::string> login;
public:
    VaultRecord(const string &name, const string &password, const Category &category) : name(name), password(password),
                                                                                        category(category) {
        this->name = name;
        this->password = password;
        this->category = category;
        this->webAddress = optional<std::string>();
        this->login = optional<std::string>();
    }

    auto setWebAddress(const std::string &webAddress) -> void {
        this->webAddress.swap((optional<basic_string<char>> &) webAddress);
    }

    auto setLogin(const std::string &login) -> void {
        this->login.swap((optional<basic_string<char>> &) login);
    }

    auto toString() -> std::string {
        std::string output = "Name: " + this->name + "\n";
        output += "Password: " + this->password + "\n";
        output += "Category: ";
        output += this->category._to_string();
        output += '\n';
        if (this->webAddress.has_value())
            output += "Web Address: " + this->webAddress.value() + "\n";
        if (this->login.has_value())
            output += "Login: " + this->login.value() + "\n";
        return output;
    }

    auto toCsv() -> std::string {
        std::string output = "name,password,category,webAddress,login\r\n";
        output += this->name + ',';
        output += this->password + ',';
        output += this->category._to_string();
        output += ',';
        output += this->webAddress.value_or("NULL"); //todo protect so that web address cant be set as null.
        output += ',';
        output += this->login.value_or("NULL");
        output += "\r\n";
        return output;
    }

};

