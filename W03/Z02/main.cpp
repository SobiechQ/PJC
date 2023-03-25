//
// Created by mikol on 16.03.2023.
//
#include <vector>
#include <iostream>
#include <ranges>
#include <algorithm>
#include <set>
#include <cassert>
#include <numeric>

//int countChars(std::vector<char> inputSet, char inputLook){
//    int count=0;
//    for (char c:inputSet) {
//        if(c==inputLook)
//            count++;
//    }
//    return count;
//}
int countChars(std::vector<char> inputSet, char inputLook){
    return std::ranges::count(inputSet, inputLook);
}
int countChars(std::string inputString, char inputLook){
    return std::ranges::count(inputString, inputLook);
}
auto addElement(std::vector<int> vector) {
    vector.push_back(10);
}
auto dotProduct(
        std::vector<double> first,
        std::vector<double> second
) -> double {
    return std::inner_product(first.begin(), first.end(), second.begin(), 0.0);
}


int countEven(std::vector<int> inputSet){
    int out=0;
    for (int i:inputSet) {
        if(i%2==0)
            out++;
    }
    return out;
}


int main() {
    using namespace std;
    cout << countChars(vector<char>{'a','b','z'}, 'z') << '\n';
    cout << countChars(vector<char>{'a','a','a','a','a','a'}, 'a') << '\n';
    cout << countChars("programowanie", 'e') << '\n';
    cout << countEven({1,2,3,4,5,6,7,8,1,1,1,1,1,1}) << '\n';


    //dodawanie róznych na vectorze
//    vector<string> imiona;
//    string tmpImie;
//    for (int i = 0; i < 4; ++i) {
//        cin >> tmpImie;
//        if(ranges::count(imiona,tmpImie)!=0)
//            continue;
//        imiona.push_back(tmpImie);
//    }
//    for (string s:imiona) {
//        cout << s << '\n';
//    }

//dodawanie różnych na set.
//    set<1

/*
    vector<int> inputNumbers;
    int tmpInput;
    for (int i = 0; i < 10; ++i) {
        cin >> tmpInput;
        inputNumbers.push_back(tmpInput);
    }
    set<int> set[2];
    for (int i = 0; i < inputNumbers.size(); ++i) {
        set[i<5?0:1].insert(inputNumbers[i]);
    }
    cout << "Set 0" << '\n';
    for (int i:set[0]) {
        cout << i << '\n';
    }
    cout << "set 1" << '\n';
    for (int i:set[1]) {
        cout << i << '\n';
    }
    if (set[0]==set[1]) {
      cout << "Rowne" << '\n';
    } else {
        cout << "Rozne" << '\n';
    }
*/


    auto ints = std::vector<int>();
    cout <<" \t Przed: "<< ints.size() << '\n';
    addElement(ints);
    cout <<" \t Po: "<< ints.size() << '\n';
    vector<double>dane[2];
    dane[0]={0,1,2,3,4,5};
    dane[1]={0,1,2,3,4,5,6,7,8,9,0};


    cout << dotProduct(dane[0],dane[1]) << '\n';








    return 0;
}
