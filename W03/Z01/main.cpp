//
// Created by mikol on 13.03.2023.
//

#include <iostream>
#include <cmath>
#include <algorithm>


int main() {
    using namespace std;
    auto word = string();
    cout << __cplusplus << '\n';
    cout << __GNUC__ << '\n';
    cout << __GNUC_MINOR__ << '\n';
    cout << __GNUC_PATCHLEVEL__ << '\n';
    word = "razdwatrzy";
    cout << word[0] << '\n';
    cout << "'" << word[word.size() - 1] << '\'' << '\n';
    cout << word.size() << '\n';
    cout << "\"" << word[word.size() / 2] << '"' << '\n';
    cout << '[' << word << "]\n";
    ranges::sort(word);
    cout << word;
    return 0;
}




