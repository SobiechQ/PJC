//
// Created by mikol on 27.03.2023.
//
#include <iostream>
#include <vector>
#include <string>
#include <fmt/ranges.h>
std::vector<std::string> getNamesFrom(std::vector<std::string> input){
    std::vector<std::string> output = input;
    erase_if(output,[](std::string s)->bool{
        return !(s[0]>='A'&&s[0]<='Z');
    });
    return output;
}

int main() {
    using namespace std;
    vector<string> wyrazy = {"Jan","dzban","Mann","90lan","3384","JAKTO","c++"};
    fmt::print("{}",getNamesFrom(wyrazy));



    return 0;
}
