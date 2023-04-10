//
// Created by Sobiech on 10.04.2023.
//
#include <iostream>
#include <vector>
#include <fmt/printf.h>
template <typename T>
auto printVector(std::vector<T> input){
    using namespace std;
    for(auto i:input)
        fmt::printf(i);
}

template <typename T>
auto mapThis(std::vector<T> vec, T predicate){

}


int main() {
    using namespace std;
    vector<string> vec ={"Raz, Dwa, Trzy, Cztery"};
//    printVector(vec);
    auto myComparator = [](int i1, int i2) -> bool {
        return i1%10 > i2%10;
    };
    auto lastInt = [](int i)-> int{
        return  i%10;
    };
    fmt::print("{}",myComparator(24,13));
    fmt::print("{}",lastInt(12));





    return 0;
}
