/**
 * @file interface.h
 *  Contains the declaration of the Interface class.
 */

#ifndef PJC2_INTERFACE_H
#define PJC2_INTERFACE_H

/**
 * @class Interface
 *  Provides a command-line interface for interacting with the password manager.
 *
 * The Interface class allows the user to perform various operations on the password manager,
 * such as creating a new file, using an existing file, loading data, saving data, showing records,
 * adding records, removing records, altering records, managing categories, and ordering records.
 */
class Interface {
public:
    /**
     *  Runs the command-line interface.
     *
     * This method starts the command-line interface and presents the user with a menu of options.
     * The user can select an option by entering the corresponding command.
     * After executing the selected command, the menu is displayed again until the user chooses to exit.
     */
    auto run() -> void;

private:
    /**
     *  Displays the available commands and their descriptions.
     *
     * @return A string containing the list of available commands and their descriptions.
     */
    auto help() -> std::string;

    /**
     *  Creates a new password file.
     *
     * This method prompts the user to enter a filename and creates a new password file with the given name.
     * If a file with the same name already exists, the user is prompted to confirm the overwrite.
     */
    auto create() -> void;

    /**
     *  Uses an existing password file.
     *
     * This method prompts the user to enter a filename and sets it as the current file for the password manager.
     * If the file does not exist, an error message is displayed.
     */
    auto use() -> void;

    /**
     *  Loads password data from a file.
     *
     * This method prompts the user to enter a filename and loads password data from the specified file.
     * If the file does not exist, an error message is displayed.
     */
    auto load() -> void;

    /**
     *  Shows all password records.
     *
     * This method displays all the password records stored in the password manager.
     */
    auto show() -> void;

    /**
     *  Adds a new password record.
     *
     * This method prompts the user to enter the website, username, and password for a new password record,
     * and adds it to the password manager.
     */
    auto add() -> void;

    /**
     *  Removes a password record.
     *
     * This method prompts the user to enter the website of the password record they want to remove,
     * and removes it from the password manager.
     */
    auto remove() -> void;

    /**
     *  Alters a password record.
     *
     * This method prompts the user to enter the website of the password record they want to alter,
     * and allows them to modify the username and password of the record.
     */
    auto alter() -> void;

    /**
     *  Shows all password categories.
     *
     * This method displays all the password categories stored in the password manager.
     */
    auto category_show() -> void;

    /**
     *  Adds a new password category.
     *
     * This method prompts the user to enter the name of a new password category,
     * and adds it to the password manager.
     */
    auto category_add() -> void;

    /**
     *  Deletes a password category.
     *
     * This method prompts the user to enter the name of the password category they want to delete,
     * and removes it from the password manager.
     */
    auto category_delete() -> void;

    /**
     *  Changes the order of password records.
     *
     * This method allows the user to change the order in which the password records are displayed.
     * The user can choose to order by website, username, or category.
     */
    auto order() -> void;

    /**
     *  Displays the currently used file.
     *
     * This method displays the name of the currently used file by the password manager.
     */
    auto currentFileUsing() -> void;

    /**
     *  Saves the password data to a file.
     *
     * This method prompts the user to enter a filename and saves the password data to the specified file.
     * If the file already exists, the user is prompted to confirm the overwrite.
     */
    auto save() -> void;

    /**
     *  Prints the index of password records.
     *
     * This method prints the index of password records, showing their position in the current order.
     */
    auto printIndex() -> void;
};

#endif // PJC2_INTERFACE_H
