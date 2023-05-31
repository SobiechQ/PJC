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
    } while (command != "exit");
}

auto Interface::help() -> std::string {
    return "Command list. Type help $command$ for information about specific command"
           "\n\t help"
           "\n\t use"
           "\n\t create"
           "\n\t show"
           "\n\t add"
           "\n\t delete"
           "\n\t alter"
           "\n\t load"
           "\n\t save\n";
}

auto Interface::use() -> void {
    fmt::print("{}", "Use.\n\tNow please enter a valid file location (excluding the .pass) of an encrypted file: \n");
    auto location = string();
    cin >> location;
    try{
        FilesManager::getInstance()
                ->setCurrentFile(location);
    } catch (std::ios_base::failure ex){
        fmt::print("{}", "Unable to load file. I/O error. Try again."
                         "Reason: ");
        fmt::print("{}", ex.what());
    } catch (std::logic_error ex){
        fmt::print("{}", "Unable to load file. Logic error. Try again."
                         "Reason: ");
        fmt::print("{}", ex.what());
    }
}
