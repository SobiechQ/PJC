//
// Created by mikol on 27.03.2023.
//
#include <iostream>
#include <vector>
#include <string>
#include <fmt/ranges.h>
#include <set>
std::vector<std::string> getNamesFrom(std::vector<std::string> input){
    std::vector<std::string> output = input;
    erase_if(output,[](std::string s)->bool{
        return !(s[0]>='A'&&s[0]<='Z');
    });
    return output;
}
std::vector<std::string> filtered(std::vector<std::string> input, std::set<std::string> redacted){
    std::erase_if(input, [redacted](std::string s) -> bool {
        redacted.contains(s);
    });
    return input;
}

int main() {
    using namespace std;
    /*
    {
        //Filtrowanie Imion
        vector<string> wyrazy = {"Jan","dzban","Mann","90lan","3384","JAKTO","c++"};
        fmt::print("{}",getNamesFrom(wyrazy));
    }
    */
/*
    {
        //Filtrowanie Znaków
        std::set<string> redactedWords = {"Cpp", "Java", "Go", ".NET", "COBOL"};
        fmt::print("{}", filtered(std::vector<string>{"Tofu", "Onigiri", "COBOL", "Maki", "Java"}, redactedWords));
    }
*/




    return 0;
}
