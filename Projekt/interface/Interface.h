//
// Created by mikol on 31.05.2023.
//

#ifndef PJC2_INTERFACE_H
#define PJC2_INTERFACE_H


class Interface {
public:
    auto run() -> void;
private:
    auto help() -> std::string;
    /*
     * "\n\t help"
           "\n\t use"
           "\n\t show"
           "\n\t add"
           "\n\t remove"
           "\n\t alter"
           "\n\t load"
           "\n\t save";
     */
    auto use() -> void;
//    auto show() -> void;
//    auto add() -> void;
//    auto remove() -> void;
//    auto alter() -> void;
//    auto load() -> void;
//    auto save() -> void;
};


#endif //PJC2_INTERFACE_H
