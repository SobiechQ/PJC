#include <string>
#include <fmt/printf.h>
#include <map>
#include <vector>
#include <random>

//
// Created by mikol on 18.05.2023.
//
//todo javadoc
/**
 * @param value
 * @param key
 * @return
 */
auto enc2(std::string value, std::string key) -> std::string {
    using namespace std;
    string addingKey = string();
    for (int i = key.size(); i < value.size(); i++)
        addingKey += key[i % key.size()];
    key += addingKey;
    key.resize(value.size());
    if (key.size() != value.size())
        throw std::logic_error("Key and password are not equal in size!");
    //From now on both password and key are exact same length
    for (int i = 0; i < value.size(); i++)
        value[i] += key[i];
    return value;
}

auto dec2(std::string valueEncrypted, std::string key) -> std::string {
    using namespace std;
    string addingKey = string();
    for (int i = key.size(); i < valueEncrypted.size(); i++)
        addingKey += key[i % key.size()];
    key += addingKey;
    key.resize(valueEncrypted.size());
    if (key.size() != valueEncrypted.size())
        throw std::logic_error("Key and valueEncrypted are not equal in size!");
    //From now on both valueEncrypted and key are exact same length
    for (int i = 0; i < valueEncrypted.size(); i++)
        valueEncrypted[i] -= key[i];
    return valueEncrypted;
}

