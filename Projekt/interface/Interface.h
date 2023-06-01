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
     */
    auto create() -> void;
    auto use() -> void;
    auto load() -> void;
    auto show() -> void;
    auto add() -> void;
    auto remove() -> void;
    auto alter() -> void;
    auto category_show() -> void;
    auto category_add() -> void;
    auto category_delete() -> void;

    auto currentFileUsing() -> void;
    auto save() -> void;
    auto printIndex() -> void;
};


#endif //PJC2_INTERFACE_H
