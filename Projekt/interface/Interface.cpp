//
// Created by mikol on 31.05.2023.
//

#include <string>
#include <iostream>
#include "Interface.h"
#include "../filesManager/FilesManager.h"
#include "../category/CategoryManager.h"
#include "../comparator/Comparator.h"
#include <fmt/printf.h>
//#include "C:\Users\mikol\Documents\PJC\Projekt\category\CategoryManager.h"
using namespace std;

auto Interface::run() -> void {
    auto command = string();
    CategoryManager::getInstance()->read();
    system("CLS");
    fmt::print("\n{:░^50}\n", "");
    fmt::print("{:░^50}\n", "PASSWORD MANAGER v1");
    fmt::print("{:░^50}\n", "type help for more information");
    fmt::print("{:░^50}\n", "");
    do {
        cin >> command;
        if (command == "help_command")
            fmt::print("{}", this->help());
        if (command == "use")
            this->use();
        if (command == "load")
            this->load();
        if (command == "create")
            this->create();
        if (command == "add")
            this->add();
        if (command == "save")
            this->save();
        if (command == "show")
            this->show();
        if (command == "using")
            this->currentFileUsing();
        if (command == "delete")
            this->remove();
        if (command == "alter")
            this->alter();
        if (command == "close") {
            fmt::print("\n{:-^32}\n", "CLOSE");
            FilesManager::getInstance()->close();
            fmt::print("\t{}\n", "File has been closed.");
            fmt::print("{:-^32}\n\n", "");
        }
        if (command == "category_show")
            this->category_show();
        if (command == "category_add")
            this->category_add();
        if (command == "category_delete")
            this->category_delete();
        if (command == "clear" || command == "cls")
            system("CLS");
        if (command == "order")
            this->order();
    } while (command != "exit");
    FilesManager::getInstance()
            ->close();
}

auto Interface::help() -> std::string {
    return "Command list. Type help for information about specific command"
           "\n\t help"
           "\n\t create"
           "\n\t use"
           "\n\t load"
           "\n\t save"
           "\n\t show"
           "\n\t add"
           "\n\t delete"
           "\n\t alter"
           "\n\t order" //todo!!
           "\n\t category_show"
           "\n\t category_add"
           "\n\t category_delete"
           "\n\t using"
           "\n\t clear"
           "\n\t close"
           "\n\t exit\n";
}

auto Interface::use() -> void {
    fmt::print("\n{:-^32}\n", "USE");
    fmt::print("\t{}\n", "Please enter a valid file location (excluding the .pass) of an encrypted file:");
    auto location = string();
    cin >> location;
    try {
        FilesManager::getInstance()
                ->setCurrentFile(location);
        fmt::print("\t{}\n", "File has been properly set. Use load command to read data");
    } catch (std::ios_base::failure ex) {
        fmt::print("\t{}\n", "Unable to load file. I/O error. Try again. \n"
                             "Reason: ");
        fmt::print("\t{}\n", ex.what());
    }
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::load() -> void {
    fmt::print("\n{:-^32}\n", "LOAD");
    auto key = string();
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("\t{}\n", "File is not set. Please enter command use before loading data.");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    fmt::print("\t{}\n", "Please provide key for a given file: ");
    cin >> key;
    try {
        FilesManager::getInstance()
                ->read(key);
        fmt::print("\t{}\n", "Data loaded successfully!");
    } catch (ios_base::failure ex) {
        fmt::print("\t{}\n", "Input/output fail. File might be corrupted or missing. Reason:");
        fmt::print("\t{}\n", ex.what());
    }
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::create() -> void {
    fmt::print("\n{:-^32}\n", "CREATE");
    fmt::print("\t{}\n",
               "Please prvide a full address to a location and name of the file to be created (without .pass)");
    auto location = string();
    cin >> location;
    try {
        FilesManager::getInstance()
                ->createFile(location);
        fmt::print("\t{}\n", "File was created and loaded.");
    } catch (ios_base::failure ex) {
        fmt::print("\t{}\n", "unable to create file. Reason:");
        fmt::print("\t{}\n", ex.what());
    }
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::add() -> void {
    fmt::print("\n{:-^32}\n", "ADD");
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("\t{}\n", "Set file using command use before adding new records.");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    if (CategoryManager::getInstance()->getCategories()->empty()) {
        fmt::print("\t{}\n", "No categories avaliable, provide categories with category_add command");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    fmt::print("\t{}\n", "Please enter name of new record:");
    auto name = string();
    cin >> name;
    fmt::print("\t{}\n", "Please enter password of new record. If you want password to be automatically generated enter auto");
    auto password = string();
    cin >> password;
    if (password == "auto"){
        int passwordLength;
        std::string includeUpperAndLowerStr;
        std::string includeAlphanumericalCharsStr;

        // Prompt the user for input
        fmt::print("\t{}\n","Enter the number of letters: ");
        std::cin >> passwordLength;

        // Validate the password length
        if (passwordLength <= 0) {
            fmt::print("\t{}\n","Invalid password length. Please enter a positive number.\n");
            fmt::print("{:-^32}\n", "");
            return; // or handle the error in an appropriate way
        }

        fmt::print("\t{}\n","Generate uppercase and lowercase letters? (yes/no): ");
        std::cin >> includeUpperAndLowerStr;

        fmt::print("\t{}\n","Generate alphanumeric characters? (yes/no): ");
        std::cin >> includeAlphanumericalCharsStr;

        bool includeUpperAndLower = (includeUpperAndLowerStr == "yes");
        bool includeAlphanumericalChars = (includeAlphanumericalCharsStr == "yes");

        // Generate the password based on user input
        std::string passwordGen = FilesManager::getInstance()->generatePass( passwordLength, includeUpperAndLower, includeAlphanumericalChars);

        // Assign the generated password to the 'password' variable
        password = passwordGen;
    }
    const auto& records = FilesManager::getInstance()->getCurrentFile()->value()->getRecords();
    bool passwordExists = std::any_of(records->begin(), records->end(), [&password](const VaultRecord& record) {
        return record.getPassword() == password;
    });
    if (passwordExists)
        fmt::print("\t{}\n","WARNING! Provided password was alredy used before!");

    fmt::print("\t{}\n", "Please enter category of new record: ");
    fmt::print("{}\n", "Avaliable categories are:");
    for (auto cat: *CategoryManager::getInstance()->getCategories())
        fmt::print("\t\t{:-^16}\n", cat);
    auto category = string();
    cin >> category;
    if (!(std::find(CategoryManager::getInstance()->getCategories()->begin(),
                    CategoryManager::getInstance()->getCategories()->end(), category) !=
          CategoryManager::getInstance()->getCategories()->end())) {
        fmt::print("\t{} {} {}\n", "Category", category,
                   "is not avaliable in list of categories. Add it by using command category_add");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    auto record = VaultRecord(name, password, category);
    fmt::print("\t{}\n", "If you want to store login please type it. If you want login to remain empty type: empty");
    auto login = string();
    cin >> login;
    if (login != "empty")
        record.setLogin(login);
    fmt::print("\t{}\n",
               "If you want to store web address please type it. If you want web address to remain empty type: empty");
    auto webAddress = string();
    cin >> webAddress;
    if (webAddress != "empty")
        record.setWebAddress(webAddress);
    FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()
            ->push_back(record);
    fmt::print("\t{}\n", "Sucessfuly added new record. Remember to save unsaved changes using save command");
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::save() -> void {
    fmt::print("\n{:-^32}\n", "SAVE");
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("\t{}\n", "Set file with command use before saving");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    if (FilesManager::getInstance()
            ->getCurrentFile()->value()->getRecords()->empty()) {
        fmt::print("\t{}\n", "Terminated. No cached data to save");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    fmt::print("\t{}\n", "Please provide key to encrypt unsaved data.");
    auto key = string();
    cin >> key;
    try {
        FilesManager::getInstance()
                ->save(key);
        fmt::print("\t{}\n", "File saved properly");
    } catch (logic_error ex) {
        fmt::print("\t{}\n", "Terminated, this command cant be run now. File was not saved. Reason:");
        fmt::print("\t{}\n", ex.what());
    } catch (std::ios_base::failure ex) {
        fmt::print("\t{}\n", "Saving fail. File might be corrupted or no access to file. Reason:");
        fmt::print("\t{}\n", ex.what());
    }
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::show() -> void {
    fmt::print("\n{:-^32}\n", "SHOW");
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("\t{}\n",
                   "File was not set. Please create new file using command create or use existign file using command use");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    if (FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()
            ->empty()) {
        fmt::print("\t{}\n", "File was set but no data was loaded. Use command load, to load and decrypt stored data");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    fmt::print("\t\t| {} | {} | {} | {} | {} | {}\n", "INDEX", "NAME", "PASSWORD", "CATEGORY", "LOGIN", "WEB ADDRESS");
    fmt::print("\t{:-^32}\n", "");
    auto j = 0;
    for (auto &record: *FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()) {
        fmt::print("\t\t| {} | {} | {} | {} | {} | {} |\n", j++, record.getName(), record.getPassword(),
                   record.getCategory(), record.getLogin().value_or(" --- "), record.getWebAddress().value_or(" --- "));
    }
    fmt::print("\t{:-^32}\n", "");
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::currentFileUsing() -> void {
    fmt::print("\n{:-^32}\n", "USING");
    if (!FilesManager::getInstance()->isFileSet()) {
        fmt::print("\t{}\n", "File is not selected. Please enter command use, to select .pass file.");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    fmt::print("\t{}\n", FilesManager::getInstance()->getCurrentFile()->value()->getLocation());
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::remove() -> void {
    fmt::print("\n{:-^32}\n", "DELETE");
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("\t{}\n",
                   "File was not set. Please create new file using command create or use existing file using command use");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    if (FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()
            ->empty()) {
        fmt::print("\t{}\n", "File is empty. Nothing to delete. Please load data using command load");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    this->printIndex();
    auto indexString = string();
    bool properParsed;
    int indexInt = 0;
    do {
        fmt::print("\t{}\n", "Please provide index of row to be deleted. Type exit to get back to menu.");
        properParsed = true;
        cin >> indexString;
        if (indexString == "exit") {
            fmt::print("{:-^32}\n\n", "");
            return;
        }
        try {
            indexInt = stoi(indexString);
        } catch (std::invalid_argument ex) {
            fmt::print("\t{}\n", "Provided index is not a proper number. Reason:");
            fmt::print("\t{}\n", ex.what());
            properParsed = false;
        } catch (std::out_of_range ex) {
            fmt::print("\t{}\n", "Provided index is not a proper number. Reason:");
            fmt::print("\t{}\n", ex.what());
            properParsed = false;
        }
        if (indexInt < 0 ||
            indexInt >= FilesManager::getInstance()->getCurrentFile()->value()->getRecords()->size()) {
            fmt::print("\t{}\n", "Provided indexString is out or range");
            properParsed = false;
        }
    } while (!properParsed);
    FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()
            ->erase(FilesManager::getInstance()
                            ->getCurrentFile()
                            ->value()
                            ->getRecords()->begin()
                    + indexInt);
    fmt::print("\t{} {} {} \n", "Properly removed ", indexInt, " element.");
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::alter() -> void {
    fmt::print("\n{:-^32}\n", "ALTER");
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("\t{}\n",
                   "File was not set. Please create new file using command create or use existign file using command use");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    if (FilesManager::getInstance()
            ->getCurrentFile()->value()->getRecords()->empty()) {
        fmt::print("\t{}\n",
                   "File was set but no data is loaded. Use command load to load data from file");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    if (FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()
            ->empty()) {
        fmt::print("\t{}\n", "File is empty. Noting to alter. Load data to alter using command load.");
        fmt::print("{:-^32}\n\n", "");
    }
    fmt::print("\t{}\n", "Currently avaliable records are: ");
    this->printIndex();
    auto indexString = string();
    bool properParsed;
    int indexInt = 0;
    do {
        fmt::print("\t{}\n", "Please provide index of row to be cahnged. Type exit to get back to menu.");
        properParsed = true;
        cin >> indexString;
        if (indexString == "exit") {
            fmt::print("{:-^32}\n\n", "");
            return;
        }
        try {
            indexInt = stoi(indexString);
        } catch (std::invalid_argument ex) {
            fmt::print("\t{}\n", "Provided index is not a proper number. Reason:");
            fmt::print("\t{}\n", ex.what());
            properParsed = false;
        } catch (std::out_of_range ex) {
            fmt::print("\t{}\n", "Provided index is not a proper number. Reason:");
            fmt::print("\t{}\n", ex.what());
            properParsed = false;
        }
        if (indexInt < 0 ||
            indexInt >= FilesManager::getInstance()->getCurrentFile()->value()->getRecords()->size()) {
            fmt::print("\t{}\n", "Provided index is out or range");
            properParsed = false;
        }
    } while (!properParsed);
    auto command = string();
    auto newValue = string();
    fmt::print("\t{}\n", "Please enter name of row you want to change");
    fmt::print("\t\t{:-^16}\n", "name");
    fmt::print("\t\t{:-^16}\n", "password");
    fmt::print("\t\t{:-^16}\n", "category");
    fmt::print("\t\t{:-^16}\n", "login");
    fmt::print("\t\t{:-^16}\n", "address");
    cin >> command;
    if (!(command == "name" || command == "password" || command == "category" || command == "login" ||
          command == "address")) {
        fmt::print("\t{}{}{}\n", "category (", command, ") does not exist");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    fmt::print("\t{}{}\n", "enter new value to replace old ", command);
    auto replaceValue = string();
    if (command == "category") {
        fmt::print("{}\n", "Avaliable categories are:");
        for (auto cat: *CategoryManager::getInstance()->getCategories())
            fmt::print("\t\t{:-^16}\n", cat);
    }
    cin >> replaceValue;
    if (command=="category" && !(std::find(CategoryManager::getInstance()->getCategories()->begin(),
                    CategoryManager::getInstance()->getCategories()->end(), replaceValue) !=
          CategoryManager::getInstance()->getCategories()->end())) {
        fmt::print("\t{} {} {}\n", "Category", replaceValue,
                   "is not avaliable in list of categories. Add it by using command category_add");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    auto *record = &FilesManager::getInstance()->getCurrentFile()->value()
            ->getRecords()->at(indexInt);
    if (command == "name")
        record->setName(replaceValue);
    if (command == "password")
        record->setPassword(replaceValue);
    if (command == "category")
        record->setCategory(replaceValue);
    if (command == "login")
        record->setLogin(replaceValue);
    if (command == "address")
        record->setWebAddress(replaceValue);
    fmt::print("\t{} {} {}\n", command, "has been replaced to: ", replaceValue);
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::printIndex() -> void {
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("\t{}\n",
                   "File was not set. Please create new file using command create or use existign file using command use");
        return;
    }
    fmt::print("\t\t| {} | {} | {} | {} | {} | {} |\n", "INDEX", "NAME", "PASSWORD", "CATEGORY", "LOGIN", "ADDRESS");
    fmt::print("\t{:-^32}\n", "");
    auto j = 0;
    for (auto &record: *FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()) {
        fmt::print("\t\t| {} | {} | {} | {} | {} | {} |\n", j++, record.getName(), " *** ", record.getCategory(),
                   record.getLogin().value_or(" --- "), record.getWebAddress().value_or(" --- "));
    }
    fmt::print("\t{:-^32}\n", "");
}

auto Interface::category_show() -> void {
    CategoryManager::getInstance()->read();
    fmt::print("\n{:-^32}\n", "CATEGORY SHOW");
    if (CategoryManager::getInstance()->getCategories()->empty()) {
        fmt::print("\t{}\n", "No categories are now avaliable. Please create new categories with category_add command");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    fmt::print("\t{}\n", "Currently avaliable categories are:");
    fmt::print("\t\t{}\n", "| INDEX | CATEGORY |");
    fmt::print("\t{:-^32}\n", "");
    auto i = 0;
    for (auto &a: *CategoryManager::getInstance()->getCategories())
        fmt::print("\t\t| {} | {} |\n", i++, a);
    fmt::print("\t{:-^32}\n", "");
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::category_add() -> void {
    CategoryManager::getInstance()->read();
    fmt::print("\n{:-^32}\n", "CATEGORY ADD");
    fmt::print("\t{}\n", "Enter new name of new category:");
    auto category = string();
    cin >> category;
    if (std::find(CategoryManager::getInstance()->getCategories()->begin(),
                  CategoryManager::getInstance()->getCategories()->end(), category) !=
        CategoryManager::getInstance()->getCategories()->end()) {
        fmt::print("\t{} {} {}\n", "category", category, "already exists.");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    CategoryManager::getInstance()
            ->getCategories()
            ->push_back(category);
    CategoryManager::getInstance()
            ->save();
    fmt::print("\t{} {} {}\n", "Category", category, "was saved.");
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::category_delete() -> void {
    fmt::print("\n{:-^32}\n", "CATEGORY DELETE");
    CategoryManager::getInstance()
            ->read();
    if (CategoryManager::getInstance()
            ->getCategories()->empty()) {
        fmt::print("\t{}\n", "No categories found. Nothing to delete.");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    fmt::print("\t{}\n", "Please provide name of category to be deleted: ");
    fmt::print("\t{:-^32}\n", "");
    auto i = 0;
    fmt::print("\t\t| {} | {} |\n", "INDEX", "CATEGORY");
    for (auto &c: *CategoryManager::getInstance()->getCategories())
        fmt::print("\t\t| {} | {} |\n", i++, c);
    fmt::print("\t{:-^32}\n", "");
    auto category = string();
    cin >> category;
    if (!(std::find(CategoryManager::getInstance()->getCategories()->begin(),
                    CategoryManager::getInstance()->getCategories()->end(), category) !=
          CategoryManager::getInstance()->getCategories()->end())) {
        fmt::print("\t{} {} {}\n", "Category", category, "doesnt exist");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    auto *vec = CategoryManager::getInstance()->getCategories();
    vec->erase(std::remove(vec->begin(), vec->end(), category), vec->end());
    fmt::print("\t{} {} {}\n", "value", category, "has been removed.");
    CategoryManager::getInstance()->save();
    fmt::print("{:-^32}\n\n", "");
}

auto Interface::order() -> void {
    fmt::print("\n{:-^32}\n", "ORDER");
    if (!FilesManager::getInstance()->isFileSet()) {
        fmt::print("\t{}\n", "File is not set. nothing to order");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    if (FilesManager::getInstance()->getCurrentFile()->value()->getRecords()->empty()) {
        fmt::print("\t{}\n", "File is set but no data is cashed. Use command load.");
        fmt::print("{:-^32}\n\n", "");
        return;
    }
    fmt::print("\t{}\n", "Enter first category to order by:");
    fmt::print("\t\t{:-^16}\n", "name");
    fmt::print("\t\t{:-^16}\n", "password");
    fmt::print("\t\t{:-^16}\n", "category");
    fmt::print("\t\t{:-^16}\n", "login");
    fmt::print("\t\t{:-^16}\n", "webAddress");
    auto commandFirst = string();
    cin >> commandFirst;
    if (!(commandFirst == "name" || commandFirst == "password" || commandFirst == "category" ||
          commandFirst == "login" || commandFirst == "webAddress")) {
        fmt::print("\t{}\n", "No such category");
        fmt::print("{:-^32}\n", "");
        return;
    }
    auto comparator = Comparator(commandFirst);
    fmt::print("\t{}\n", "Provide second caregory to order by. Enter empty for no additional ordering");
    auto commandSecond = string();
    cin >> commandSecond;

    if (commandSecond != "empty" &&
        ((commandFirst == "name" || commandFirst == "password" || commandFirst == "category" ||
          commandFirst == "login" || commandFirst == "password"))) {
        comparator.setSecondary(commandSecond);
    }
    auto *vec = FilesManager::getInstance()->getCurrentFile()->value()->getRecords();
    auto comparatorPredicate = [&comparator](const VaultRecord &record1, const VaultRecord &record2) {
        return comparator.compare(record1, record2);
    };
    std::sort(vec->begin(), vec->end(), comparatorPredicate);
    fmt::print("\t{}\n", "Records have been sorted. Use command show to display them.");
    fmt::print("{:-^32}\n", "");


}

