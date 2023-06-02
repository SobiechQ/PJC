//
// Created by mikol on 30.05.2023.
//

#ifndef PJC2_CATEGORYMANAGER_H
#define PJC2_CATEGORYMANAGER_H


#include <string>
#include <vector>

using namespace std;
/**
 * Reads categories from a file and updates the category list.
 */
class CategoryManager {
private:
    vector<std::string> categories;
    static CategoryManager* instance;
public:
    /**
    * Gets the singleton instance of the CategoryManager class.
    * @return The singleton instance of the CategoryManager class.
    */
    static CategoryManager* getInstance();
    /**
     * Reads categories from a file and updates the category list.
     * @return The pointer to the CategoryManager instance.
     */
    CategoryManager* read();
    /**
     * Saves the category list to a file.
     * @return The pointer to the CategoryManager instance.
     */
    CategoryManager* save();
    /**
     * Gets the list of categories.
     * @return A pointer to the list of categories.
     */
    vector<std::string>* getCategories();

};


#endif //PJC2_CATEGORYMANAGER_H
