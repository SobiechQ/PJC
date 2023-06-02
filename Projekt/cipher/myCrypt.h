//
// Created by mikol on 29.05.2023.
//
/**
*@file myCrypt.h
*@brief Definition file for the myCrypt library.
*This file contains the declarations of functions for encryption and decryption using a key.
*/
#ifndef PJC2_MYCRYPT_H
#define PJC2_MYCRYPT_H

#include <string>
    /**
    *Encrypts a string value using a key.
    *@param value The string value to encrypt.
    *@param key The key used for encryption.
    *@return The encrypted string.
    */
    auto myEncrypt(std::string value, std::string key) -> std::string;
    /**
    *Decrypts an encrypted string value using a key.
    *@param valueEncrypted The encrypted string value to decrypt.
    *@param key The key used for decryption.
    *@return The decrypted string.
    */
    auto myDecrypt(std::string valueEncrypted, std::string key) -> std::string;

#endif //PJC2_MYCRYPT_H
