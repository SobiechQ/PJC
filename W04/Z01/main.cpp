//
// Created by mikol on 25.03.2023.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <fmt/ranges.h>
int main() {
    using namespace std;
    using fmt::print;



    auto vec = vector<int>();

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }
    print("Hello pjatk {} w srodku tych klamer \n","a to sie pojawia");
    print("{}abc\n",vec);
    vec.insert(vec.begin()+4,-1);
    vec.erase(vec.begin()+2);
    print("{}abc\n",vec);
    print(
            "{} \n",ranges::count(vec, 3)
            );

    auto isEven = [](int n) -> bool{
        return n%2==0;
    };
    //utworzenie zmiennej z literałem będącym funkcją

    print(
            "{}\n", ranges::count_if(vec,isEven)
            );


    //wywołanie metody bezpośrednio z literałem
    print("{}\n", ranges::count_if(vec, [](int n)-> bool {
        return n%2==1;
    }));





    return 0;
}
