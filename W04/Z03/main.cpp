//
// Created by Sobiech on 30.03.2023.
//
#include <iostream>
#include <fmt/ranges.h>
#include <vector>

int main() {
    using namespace std;

    auto foo = [](int i) -> auto {return i*i;};
//    vector<auto>()

    cout << foo(5) << '\n';
    return 0;
}