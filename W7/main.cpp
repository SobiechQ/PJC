#include <iostream>
#include <vector>
#include <algorithm>
#include <fmt/core.h>
#include <fmt/std.h>
#include <filesystem>
struct Base {
    virtual auto print() const -> void {
        fmt::print("Hello");
    }
};
struct Derived : Base{
    auto print() const -> void override{
        fmt::print("Zmiana");
    }
};
auto callPrint(const Base& b) -> void {

    //taką const metode możemy używać tylko na const metody
    b.print();
}



int main() {
    using namespace std;
    /*
     * //kartkówka
     *
    auto vec = vector<string>();
    while (vec.size()<10){
        string tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    auto predicate = [](string s1, string s2)->bool {
        return s1[s1.size()-1] < s2[s2.size()-1];
    };
    std::sort(vec.begin(), vec.end(), predicate);
    for (const auto &item: vec) {
        cout << item << '\n';
    }
*/



    auto const dirPath = string("C:\\Users\\s27233\\Desktop\\Main\\test");
    auto dirIterator = std::filesystem::recursive_directory_iterator(dirPath);
    for (const auto &item: dirIterator) {
        fmt::print("{}\n", item.path());
    }



    //polimorfizm
    callPrint(Derived());
    return 0;
}

