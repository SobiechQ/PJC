//
// Created by mikol on 25.05.2023.
//
//#include "enum.h"
#include <iostream>
#include <optional>
#include "VaultRecord.h"

using namespace std;


auto VaultRecord::setWebAddress(std::string webAddress) -> void {
    this->webAddress = webAddress;
}

auto VaultRecord::setLogin(string login) -> void {
    this->login = login;
}

auto VaultRecord::toString() -> std::string {
    std::string output = "Name: " + this->name + "\n";
    output += "Password: " + this->password + "\n";
    output += "Category: " + this->category + "\n";
    if (this->login.has_value())
        output += "Login: " + this->login.value() + "\n";
    if (this->webAddress.has_value())
        output += "Web Address: " + this->webAddress.value() + "\n";
    output += '\n';
    return output;
}

auto VaultRecord::toCsv() -> std::string {
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

const string &VaultRecord::getName() const {
    return name;
}

const string &VaultRecord::getPassword() const {
    return password;
}

const string &VaultRecord::getCategory() const {
    return category;
}

const optional<std::string> &VaultRecord::getLogin() const {
    return login;
}

const optional<std::string> &VaultRecord::getWebAddress() const {
    return webAddress;
}

void VaultRecord::setName(const string &name) {
    VaultRecord::name = name;
}

void VaultRecord::setPassword(const string &password) {
    VaultRecord::password = password;
}

void VaultRecord::setCategory(const string &category) {
    VaultRecord::category = category;
}

