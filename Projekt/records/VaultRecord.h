/**
 * @file VaultRecord.h
 *  Defines the VaultRecord class.
 */

#ifndef PJC2_VAULTRECORD_H
#define PJC2_VAULTRECORD_H

#include <iostream>
#include <optional>
#include <vector>

/**
 * @class VaultRecord
 *  Represents a record in the vault.
 */
class VaultRecord {
private:
    std::string name;                          /**< The name of the record. */
    std::string password;                      /**< The password of the record. */
    std::string category;                      /**< The category of the record. */
    std::optional<std::string> login;          /**< The login associated with the record (optional). */
    std::optional<std::string> webAddress;     /**< The web address associated with the record (optional). */

public:
    /**
     *  Constructs a VaultRecord object.
     * @param name The name of the record.
     * @param password The password of the record.
     * @param category The category of the record.
     */
    VaultRecord(const std::string &name, const std::string &password, const std::string &category) : name(name), password(password),
                                                                                      category(category) {}
    /**
     *  Sets the web address for the record.
     * @param webAddress The web address to set.
     */
    auto setWebAddress(std::string webAddress) -> void;

    /**
     *  Sets the login for the record.
     * @param login The login to set.
     */
    auto setLogin(std::string login) -> void;

    /**
     *  Converts the record to a string representation.
     * @return The string representation of the record.
     */
    auto toString() -> std::string;

    /**
     *  Converts the record to a CSV string representation.
     * @return The CSV string representation of the record.
     */
    auto toCsv() -> std::string;

    /**
     *  Returns the name of the record.
     * @return The name of the record.
     */
    const std::string& getName() const;

    /**
     *  Returns the password of the record.
     * @return The password of the record.
     */
    const std::string& getPassword() const;

    /**
     *  Returns the category of the record.
     * @return The category of the record.
     */
    const std::string& getCategory() const;

    /**
     *  Returns the login associated with the record.
     * @return The login associated with the record (optional).
     */
    const std::optional<std::string>& getLogin() const;

    /**
     *  Returns the web address associated with the record.
     * @return The web address associated with the record (optional).
     */
    const std::optional<std::string>& getWebAddress() const;

    /**
     *  Sets the name of the record.
     * @param name The name to set.
     */
    void setName(const std::string& name);

    /**
     *  Sets the password of the record.
     * @param password The password to set.
     */
    void setPassword(const std::string& password);

    /**
     *  Sets the category of the record.
     * @param category The category to set.
     */
    void setCategory(const std::string& category);
};

#endif //PJC2_VAULTRECORD_H
