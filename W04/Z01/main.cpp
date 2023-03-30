//
// Created by Sobiech on 21.03.2023.
//
#include <iostream>
bool isPalindrome(std::string input){
    using namespace std;
    string kopia;
    for (int i = input.size()-1; i >= 0; i--) {
        kopia.push_back(input[i]);
    }
    cout << kopia << '\n';
    return kopia==input;
}



int main() {
    using namespace std;
    cout << isPalindrome("kajakarz") << '\n';



    return 0;
}