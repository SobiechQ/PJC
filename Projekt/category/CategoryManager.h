//
// Created by mikol on 30.05.2023.
//

#ifndef PJC2_CATEGORYMANAGER_H
#define PJC2_CATEGORYMANAGER_H


#include <string>
#include <vector>

using namespace std;
class CategoryManager {
private:
    vector<std::string> categories;
    static CategoryManager* instance;
public:
    static CategoryManager* getInstance();
    CategoryManager* read();
    CategoryManager* save();
    vector<std::string>* getCategories();

};


#endif //PJC2_CATEGORYMANAGER_H
