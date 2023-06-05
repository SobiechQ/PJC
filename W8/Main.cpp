//
// Created by mikol on 05.06.2023.
//
#include <iostream>
using namespace std;
struct Test{
    Test(){
        cout << "Created" << '\n';
    }
    ~Test(){
        cout << "destructed" << '\n';
    }
    auto fooTest() -> void{
        cout << "Jestem!" << '\n';
    }

};
auto foo(Test& test) -> void{
    test.fooTest();
}
int main() {
    using namespace std;
    auto test = Test();
    foo(test);
    return 0;
}
