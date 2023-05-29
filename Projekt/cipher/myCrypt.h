//
// Created by mikol on 29.05.2023.
//

#ifndef PJC2_MYCRYPT_H
#define PJC2_MYCRYPT_H

#include <string>

auto myEncrypt(std::string value, std::string key) -> std::string;
auto myDecrypt(std::string valueEncrypted, std::string key) -> std::string;

#endif //PJC2_MYCRYPT_H
