//
// Created by mikol on 31.05.2023.
//

#include <string>
#include <iostream>
#include "Interface.h"
#include "../filesManager/FilesManager.h"
#include <fmt/printf.h>
//#include "C:\Users\mikol\Documents\PJC\Projekt\filesManager\FilesManager.h"
using namespace std;

auto Interface::run() -> void {
    auto command = string();
    fmt::print("{}", "Password manager is running. Please insert command"
                     "\n\t type help for command list: \n");
    do {
        cin >> command;
        if (command == "help")
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
        if (command == "clear" || command == "cls")
            system("CLS");
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
           "\n\t category_show"
           "\n\t category_add"
           "\n\t category_remove"
           "\n\t using"
           "\n\t clear"
           "\n\t exit\n";
}

auto Interface::use() -> void {
    fmt::print("{}\n", "");
    fmt::print("{}\n", "Use\nNow please enter a valid file location (excluding the .pass) of an encrypted file:");
    auto location = string();
    cin >> location;
    try {
        FilesManager::getInstance()
                ->setCurrentFile(location);
        fmt::print("{}\n", "File has been properly set. Use load command to read data");
    } catch (std::ios_base::failure ex) {
        fmt::print("{}\n", "Unable to load file. I/O error. Try again. \n"
                           "Reason: ");
        fmt::print("{}\n", ex.what());
    }
}

auto Interface::load() -> void {
    fmt::print("{}\n", "");
    auto key = string();
    fmt::print("{}", "Please provide a decryption key for given file: ");
    cin >> key;

    fmt::print("{}", "Loading file... \n"); //todo add decrypt
    try {
        FilesManager::getInstance()
                ->read(key);
        fmt::print("{}\n", "Data loaded successfully!");
    } catch (std::logic_error ex) {
        fmt::print("{}\n", "command failure. File was not loaded");
        fmt::print("{}\n", ex.what());
    } catch (ios_base::failure ex) {
        fmt::print("{}\n", "Input/output fail. File might be corrupted or missing. Reason:");
        fmt::print("{}\n", ex.what());
    }
}

auto Interface::create() -> void {
    fmt::print("{}\n", "");
    fmt::print("{}\n",
               "Create.\nPlease prvide a full address to a location and name of the file to be created (without .pass)");
    auto location = string();
    cin >> location;
    try {
        FilesManager::getInstance()
                ->createFile(location);
        fmt::print("{}\n", "File was created and loaded.");
    } catch (ios_base::failure ex) {
        fmt::print("{}\n", "unable to create file. Reason: ");
        fmt::print("{}\n", ex.what());
    }
}

auto Interface::add() -> void {
    fmt::print("{}\n", "");
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("{}\n",
                   "cant add new record if file was not set! Please create new file using command create or use existign file using command use");
        return;
    }


    fmt::print("{}\n", "Add.\n Please provide data to be added to added to vault.");
    fmt::print("{}\n", "Please enter name of new record: ");
    auto name = string();
    cin >> name;
    fmt::print("{}\n", "Please enter password of new record: ");
    auto password = string();
    cin >> password;
    fmt::print("{}\n", "Please enter category of new record: "); //todo handle category
    auto category = string();
    cin >> category;
    auto record = VaultRecord(name, password, category);
    fmt::print("{}\n", "If you want to store login please type it. If you want login to remain empty type: empty");
    auto login = string();
    cin >> login;
    if (login != "empty")
        record.setLogin(login);
    fmt::print("{}\n",
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
    fmt::print("{}\n", "Sucessfuly added new record. Remember to save unsaved changes using save command");
}

auto Interface::save() -> void {
    fmt::print("{}\n", "");
    fmt::print("{}\n", "Save\nPlease provide encrtyption key to encrypt unsaved data.");
    auto key = string();
    cin >> key;
    try {
        FilesManager::getInstance()
                ->save(key);
        fmt::print("{}\n", "File saved properly");
    } catch (logic_error ex) {
        fmt::print("{}\n", "Terminated, this command cant be run now. File was not saved. Reason:");
        fmt::print("{}\n", ex.what());
    } catch (std::ios_base::failure ex) {
        fmt::print("{}\n", "Saving fail. File might be corrupted or no access to file. Reason:");
        fmt::print("{}\n", ex.what());
    }

}

auto Interface::show() -> void {
    fmt::print("{}\n", "");
    fmt::print("{}\n", "Show\n");
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("{}\n",
                   "File was not set. Please create new file using command create or use existign file using command use");
        return;
    }
    if (FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()
            ->empty()) {
        fmt::print("{}\n", "File was set but no data was loaded. Use command load, to load and decrypt stored data");
        return;
    }
    fmt::print("{}\n", "INDEX | NAME | PASSWORD | CATEGORY | LOGIN | WEB ADDRESS");
    for (int i = 0; i < 30; ++i)
        fmt::print("{}", '-');
    fmt::print("{}\n", "");
    auto j = 0;
    for (auto &record: *FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()) {
        fmt::print("{}", j++);
        fmt::print("{}", " | ");
        cout << record.getName();
        fmt::print("{}", " | ");
        cout << record.getPassword(); // todo to moze byc *** i pokazywane na zyczenie
        fmt::print("{}", " | ");
        cout << record.getCategory();
        fmt::print("{}", " | ");
        cout << record.getLogin().value_or(" --- ");
        fmt::print("{}", " | ");
        cout << record.getWebAddress().value_or(" --- ");
        fmt::print("{}\n", "");
    }
    for (int i = 0; i < 30; ++i)
        fmt::print("{}", '-');
    fmt::print("{}\n", "");
}

auto Interface::currentFileUsing() -> void {
    fmt::print("{}\n", "");
    fmt::print("{}\n", "Using\n");
    fmt::print("{}\n", "Currently using:");
    if (!FilesManager::getInstance()->isFileSet()) {
        fmt::print("{}\n", "No file is loaded");
        return;
    }
    fmt::print("{}\n", FilesManager::getInstance()->getCurrentFile()->value()->getLocation());
}

auto Interface::remove() -> void {
    fmt::print("{}\n", "");
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("{}\n",
                   "File was not set. Please create new file using command create or use existign file using command use");
        return;
    }
    if (FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()
            ->empty()) {
        fmt::print("{}\n", "Cant remove from an empty file");
    }
    this->printIndex();
    auto indexString = string();
    bool properParsed;
    int indexInt = 0;
    do {
        fmt::print("{}\n", "Please provide index of row to be deleted. Type exit to get back to menu.");
        properParsed = true;
        cin >> indexString;
        if (indexString == "exit")
            return;
        try {
            indexInt = stoi(indexString);
        } catch (std::invalid_argument ex) {
            fmt::print("{}\n", "Provided indexString is not a proper number.");
            fmt::print("{}\n", ex.what());
            properParsed = false;
        }
        if (indexInt < 0 ||
            indexInt > FilesManager::getInstance()->getCurrentFile()->value()->getRecords()->size()) {
            fmt::print("{}\n", "Provided indexString is out or range");
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
    fmt::print("{} {} {} \n", "Properly removed ", properParsed, " element.");

}

auto Interface::alter() -> void {
    fmt::print("{}\n", "");
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("{}\n",
                   "File was not set. Please create new file using command create or use existign file using command use");
        return;
    }
    if (FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()
            ->empty()) {
        fmt::print("{}\n", "Cant remove from an empty file");
    }
    this->printIndex();
    auto indexString = string();
    bool properParsed;
    int indexInt = 0;
    do {
        fmt::print("{}\n", "Please provide index of row to be cahnged. Type exit to get back to menu.");
        properParsed = true;
        cin >> indexString;
        if (indexString == "exit")
            return;
        try {
            indexInt = stoi(indexString);
        } catch (std::invalid_argument ex) {
            fmt::print("{}\n", "Provided indexString is not a proper number.");
            fmt::print("{}\n", ex.what());
            properParsed = false;
        }
        if (indexInt < 0 ||
            indexInt > FilesManager::getInstance()->getCurrentFile()->value()->getRecords()->size()) {
            fmt::print("{}\n", "Provided indexString is out or range");
            properParsed = false;
        }
    } while (!properParsed);
    auto command = string();
    auto newValue = string();
    fmt::print("{}\n", "enter what row you wish to change."
                       "\n\tname"
                       "\n\tpassword"
                       "\n\tcategory"
                       "\n\tlogin"
                       "\n\taddress");
    cin >> command;
    fmt::print("{}{}\n", "enter new value to replace old ", command);
    auto* record = &FilesManager::getInstance()->getCurrentFile()->value()
            ->getRecords()[indexInt];
    if (command == "name")
        record



    fmt::print("{} {} {} \n", "Properly removed ", properParsed, " element.");

}

auto Interface::printIndex() -> void {
    if (!FilesManager::getInstance()
            ->isFileSet()) {
        fmt::print("{}\n",
                   "File was not set. Please create new file using command create or use existign file using command use");
        return;
    }
    fmt::print("{}\n", " INDEX | NAME | CATEGORY");
    for (int i = 0; i < 30; ++i)
        fmt::print("{}", '-');
    fmt::print("{}\n", "");
    auto j = 0;
    for (auto &record: *FilesManager::getInstance()
            ->getCurrentFile()
            ->value()
            ->getRecords()) {
        fmt::print("{} | {} | {}\n", j++, record.getName(), record.getCategory());
    }
    for (int i = 0; i < 30; ++i)
        fmt::print("{}", '-');
    fmt::print("{}\n", "");-
}

