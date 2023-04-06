#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fmt/ranges.h>
#include <fmt/core.h>
#include <fstream>
#include <sstream> //string stream!, zachowuje się jak stream, zapamiętuje osztatnią pozycje.

bool sameCharacters(std::vector<char> charInput, std::string stringInput){
    //kartkówka
    using namespace std;
    set<char> clearedChar;
    for(char c:charInput)
        clearedChar.insert(c);
    set<char> clearedString;
    for(char c:stringInput)
        clearedString.insert(c);
    return clearedString==clearedChar;
}
auto change (int& n)-> void {
    n++;
}

template <typename T>
auto vec(std::vector<T>& toPrint) -> void{
    for(auto e:toPrint){
        std::cout <<e<< ' ';
    }

    std::cout << '\n';
}


int main() {
    /*
    using namespace std;
    auto file = fstream("file1.txt");
    auto word = std::string();
    //file input std::ios::out | std::ios::trunc -> nadpisanie zamiast
    while(file>>word)
        fmt::print("{} ",word);
*/
    //jakakolwiek operacja wykonana na refererencji jest delegowana do zmiennej z którą jest połączona

/*
    auto x=5;
    auto& y=x;
    change(y);
    fmt::print("{}",y);

    */



    auto test = std::vector<int>{1,2,3,4};

    vec(test);


    return 0;
}
