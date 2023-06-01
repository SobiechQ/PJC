//
// Created by mikol on 28.05.2023.
//

#ifndef PJC2_VAULTRECORD_H
#define PJC2_VAULTRECORD_H


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

    auto setWebAddress(std::string webAddress) -> void;

    auto setLogin(string login) -> void;

    auto toString() -> std::string;

    auto toCsv() -> std::string;

    const string &getName() const;

    const string &getPassword() const;

    const string &getCategory() const;

    const optional<std::string> &getLogin() const;

    const optional<std::string> &getWebAddress() const;

    void setName(const string &name);

    void setPassword(const string &password);

    void setCategory(const string &category);
};
#endif //PJC2_VAULTRECORD_H


